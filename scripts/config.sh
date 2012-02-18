#!/bin/sh

ARCH=$1
PLATFORM=$2

ARCH_NAMESPACE=`eval echo $ARCH | sed 's/-/_/g'`
PLATFORM_NAMESPACE=`eval echo $PLATFORM | sed 's/-/_/g'`

echo "#ifndef CONFIG_HH_"
echo "# define CONFIG_HH_"
echo

echo "#define __arch__ $ARCH"
echo "#define __platform__ $PLATFORM"

echo "namespace $ARCH_NAMESPACE { }"
echo "namespace $PLATFORM_NAMESPACE { }"

echo "namespace arch = $ARCH_NAMESPACE;"
echo "namespace platform = $PLATFORM_NAMESPACE;"

echo
echo "#endif /* !CONFIG_HH_ */"

