#!/bin/sh

ARCH=$1
PLATFORM=$2
BUILD_TYPE=$3

if [ $BUILD_TYPE = 'debug' ]; then
    DEBUG='# undef NDEBUG'
else
    DEBUG='# define NDEBUG'
fi

ARCH_NAMESPACE=${ARCH/-/_}
PLATFORM_NAMESPACE=${PLATFORM/-/_}

cat <<EOF
#ifndef CONFIG_HH_
# define CONFIG_HH_

${DEBUG}

# define __arch__ $ARCH
# define __platform__ $PLATFORM

namespace arch {}
namespace platform {}

#endif /* !CONFIG_HH_ */
EOF
