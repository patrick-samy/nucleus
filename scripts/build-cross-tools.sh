#!/bin/sh

export PREFIX=
export TARGET=
WITHOUT_NEWLIB=1

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

      --binutils=DIR         Binutils source directory absolute path.
      --gcc=DIR              GCC source directory absolute path.
      --gdb=DIR              GDB source directory absolute path.
  -h, --help                 Show this message and exit.
      --newlib=DIR           Newlib source directory absolute path.
      --prefix=DIR           Prefix (installation) directory absolute path. Mandatory.
      --target=VAL           GNU tools target name E.g. : powerpc-eabi,
                              arm-eabi, i386-elf... Mandatory.
      --without-newlib       Compile gcc without runtime libraries.
EOUSAGE
}

if [ $# -eq 0 ]; then
    usage;
    die;
fi

GETOPT=`getopt -o 'h'                                                           \
               -l help,target:,gcc:,gdb:,binutils:,newlib:,prefix:,without-newlib \
               -n $(basename $0) -- "$@"` || die

function mandatory()
{
    [ -z $1 ] && die "Error: missing mandatory option"
}

function check_path_and_set()
{
    VARIABLE=$1
    VALUE=$2

    [ ! -d $2 ] && die "$1 path does not exist."

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

        --target)
            TARGET=$2;
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
            check_path_and_set 'PREFIX' "$2"
            shift 2;
            ;;

        --without-newlib)
            WITHOUT_NEWLIB=0
            shift 2;
            ;;

        --)
            shift;
            break
            ;;
    esac
done

mandatory $PREFIX
mandatory $TARGET

export TARGET=$TARGET
export PREFIX=$PREFIX
export PATH=$PATH:$PREFIX/bin

BUILD_DIRNAME="build-$TARGET"
COMMON_OPTIONS="--target=$TARGET --prefix=$PREFIX --disable-nls -v"

function make_install
{
    if [ ! -w $PREFIX ]; then
        echo 'Root password needed'
        su -mc "make $1"
    else
        make $1
    fi

}
if [ ! -z $BINUTILS ]; then
    cd $BINUTILS &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all &&
    make_install install;
fi;

if [ ! -z $GCC ] && [ $WITHOUT_NEWLIB -eq 1 ]; then
    cd $GCC &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS --disable-libssp --without-headers --with-newlib --with-gnu-as --with-gnu-ld --enable-languages=c,c++ --disable-shared &&
    make -j4 all-gcc &&
    make_install install-gcc
fi;

if [ ! -z $NEWLIB ] && [ $WITHOUT_NEWLIB -eq 1 ]; then
    cd $NEWLIB &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all &&
    make_install install
fi;

if [ ! -z $GCC ]; then
    OPTIONS="$COMMON_OPTIONS --disable-libssp --with-gnu-as --with-gnu-ld --enable-languages=c,c++ --disable-shared";
    if $WITHOUT_NEWLIB -eq 0; then
        OPTIONS="$OPTIONS --without-headers"
    else
        OPTIONS="$OPTIONS --with-newlib"
    fi;

    cd $GCC &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $OPTIONS &&
    make -j4 all &&
    make_install install;
fi;

if [ ! -z $GDB ]; then
    cd $GDB &&
    mkdir -p $BUILD_DIRNAME &&
    cd $BUILD_DIRNAME &&
    ../configure $COMMON_OPTIONS &&
    make -j4 all &&
    make_install install
fi;

cat <<EOF
Environment variables to save (.e.g. .${TARGET}.env):
export TARGET=${TARGET}
export PREFIX=${PREFIX}
export PATH=\$PATH:${PREFIX}/bin
EOF
