#!/bin/sh

export PREFIX=
export TARGET=

# Print an error message on stderr and exit 1.
#  $1 : error message
function die()
{
    echo -e $1 >& 2;
    exit 1
}

# Usage printer
function usage()
{
    cat << EOUSAGE >& 2
Usage: `basename $0` OPTIONS

      --arch=VAL             GNU tools architecture name (target's prefix).
                              E.g. : powerpc, arm, i386... Mandatory.
      --gcc=DIR              GCC source directory.
      --gdb=DIR              GDB source directory.
      --newlib=DIR           Newlib source directory.
      --binutils=DIR         Binutils source directory.
      --prefix=DIR           Prefix (installation) directory. Mandatory.
  -h, --help                 show this message and exit.
EOUSAGE
}

if [ $# = 0 ]; then
    usage;
    die;
fi

GETOPT=`getopt -o 'h'                                                   \
               -l help,arch:,gcc:,gdb:,binutils:,newlib:,prefix:        \
               -n $(basename $0) -- "$@"` || die

function mandatory()
{
    [ -z $1 ] && die "Error: missing mandatory option"
}

function check_path_and_set()
{
    VARIABLE=$1
    VALUE=$2

    [ ! -d $2 ] || die "$1 path does not exist."

    eval "${VARIABLE}=${VALUE}"
}

# Quotes around $GETOPT are essential
eval set -- "$GETOPT"

while [ $# -gt 0 ]; do
    case "$1" in
        -h | --help)
            usage;
            die;
            ;;

        --arch)
            ARCH=$2;
            shift 2;
            ;;

        --gcc)
            check_path_and_set 'GCC' "$2"
            shift 2;
            ;;

        --gdb)
            check_path_and_set 'GDB' "$2"
            shift 2;
            ;;

        --newlib)
            check_path_and_set 'NEWLIB' "$2"
            shift 2;
            ;;

         --binutils)
            check_path_and_set 'BINUTILS' "$2"
            shift 2;
            ;;

        --prefix)

            shift 2;
            ;;

        --)
            shift;
            break
            ;;
    esac
done

mandatory $PREFIX
mandatory $ARCH

export TARGET=$ARCH-eabi
export PREFIX=$PREFIX
export PATH=$PATH:$PREFIX/bin

BUILD_DIRNAME="build-$ARCH"
COMMON_OPTIONS="--target=$TARGET --prefix=$PREFIX --disable-nls -v"

function make_install
{
    if [ ! -w $PREFIX ]; then
        echo 'Root password needed'
        su -mc 'make install-gcc'
    else
        make install
    fi
}

if [ ! -z $BINUTILS ]; then
    cd $BINUTILS &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all;
    make_install;
fi;

if [ ! -z $GCC ]; then
    cd $GCC &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS --disable-libssp --without-headers --with-newlib  --with-gnu-as --with-gnu-ld --enable-languages=c,c++ --disable-shared &&
    make -j4 all-gcc &&
    su -mc 'make install-gcc'
fi;

if [ ! -z $NEWLIB ]; then
    cd $NEWLIB &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all &&
    su -mc 'make install'
fi;

if [ ! -z $GCC ]; then
    cd $GCC/$BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS --disable-libssp --with-newlib  --with-gnu-as --with-gnu-ld --enable-languages=c,c++ --disable-shared &&
    make -j4 all &&
    su -mc 'make install'
fi;

if [ ! -z $GCC ]; then
    cd $GCC/$BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS --disable-libssp --with-newlib  --with-gnu-as --with-gnu-ld --enable-languages=c,c++ --disable-shared &&
    make -j4 all &&
    su -mc 'make install'
fi;


if [ ! -z $GDB ]; then
    cd $GDB &&
    mkdir $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all &&
    su -mc 'make install'
fi;

echo <<EOF
Environment variables to save (.e.g. .${ARCH}.env):
export TARGET=${TARGET}
export PREFIX=${PREFIX}
export PATH=\$PATH:${PREFIX}/bin
EOF
