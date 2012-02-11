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

# Directories
SCRIPTS_DIR	:= scripts
INCLUDE_DIR	:= include
CORE_DIR	:= core
ARCH_DIR	:= arch/$(ARCH)
PLATFORM_DIR	:= $(ARCH_DIR)/$(PLATFORM)
BUILD_DIR	:= build

# Flags
CFLAGS		:= -I$(INCLUDE_DIR) -O2
CXXFLAGS 	:= -nostdlib -ffreestanding -fno-builtin -fno-exceptions -fno-rtti -O2
LDFLAGS		:=

# Config
CONFIG_SCRIPT 	:= $(SCRIPTS_DIR)/config.sh
CONFIG_HEADER	:= config.hh

# Dependancies
DEPEND_SCRIPT	:= $(SCRIPTS_DIR)/depend.sh

# Modules
MODULES		:= $(CORE_DIR) $(ARCH_DIR) $(PLATFORM_DIR)

# Output
BUILD_OUTPUT	:= atom.bin

