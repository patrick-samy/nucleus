#!/bin/sh

ARCH_NAMESPACE=`eval echo $1 | sed 's/-//'`
PLATFORM_NAMESPACE=`eval echo $2 | sed 's/-//'`

echo "#ifndef CONFIG_HH_"
echo "# define CONFIG_HH_"
echo

echo "namespace $ARCH_NAMESPACE { }"
echo "namespace $PLATFORM_NAMESPACE { }"

echo "namespace arch = $ARCH_NAMESPACE;"
echo "namespace platform = $PLATFORM_NAMESPACE;"

echo
echo "#endif /* !CONFIG_HH_ */"

