# Version
VERSION		:= 0.1

# Default target architecture to i386
ARCH	 	?= ia-32
PLATFORM 	?= ibm-pc

# Build tools
AS 		:= $(CROSS_COMPILE)as
LD 		:= $(CROSS_COMPILE)ld
CC 		:= $(CROSS_COMPILE)gcc
CXX 		:= $(CROSS_COMPILE)g++
CPP 		:= $(CC) -E
AR 		:= $(CROSS_COMPILE)ar
NM 		:= $(CROSS_COMPILE)nm
STRIP 		:= $(CROSS_COMPILE)strip
OBJCOPY 	:= $(CROSS_COMPILE)objcopy
OBJDUMP 	:= $(CROSS_COMPILE)objdump

# Rule helpers
CCOMP		= $(CC) $(CFLAGS) -o $@ -c $<
CXXCOMP		= $(CXX) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<
CDEPS		= $(DEPEND_SCRIPT) `dirname $*.cc` $(CFLAGS) $*.cc > $@
LLINK		= $(AR) csr $@ $^
LINK		= $(CC) $(CFLAGS) -o $@ $^

# Directories
CORE_DIR	:= core
ARCH_DIR	:= arch/$(ARCH)
PLATFORM_DIR	:= $(ARCH_DIR)/$(PLATFORM)
BUILD_DIR	:= build

# Flags
CFLAGS		:=
CXXFLAGS 	:= -nostdlib -ffreestanding -fno-builtin -fno-exceptions -fno-rtti -O2
LDFLAGS		:=

# Config
CONFIG_SCRIPT 	:= $(BUILD_DIR)/config.sh
CONFIG_HEADER	:= config.hh

# Dependancies
DEPEND_SCRIPT	:= $(BUILD_DIR)/depend.sh

# Modules
MODULES		:= $(CORE_DIR) $(ARCH_DIR) $(PLATFORM_DIR)

# Include the macros
include build/macros.mk

# Include the top-level rules.mk
include rules.mk

