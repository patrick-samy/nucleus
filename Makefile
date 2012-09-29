include build.conf

# Build tools
AS			:= $(CROSS_COMPILE)as
LD 			:= $(CROSS_COMPILE)ld
CC 			:= $(CROSS_COMPILE)gcc
CXX			:= $(CROSS_COMPILE)g++
CPP			:= $(CROSS_COMPILE)gcc -E
AR 			:= $(CROSS_COMPILE)ar
NM 			:= $(CROSS_COMPILE)nm
STRIP			:= $(CROSS_COMPILE)strip
OBJCOPY			:= $(CROSS_COMPILE)objcopy
OBJDUMP			:= $(CROSS_COMPILE)objdump

# Rule helpers
CCOMP			= $(CC) -MD $(CFLAGS) -o $@ -c $<
CXXCOMP			= $(CXX) -MD $(CFLAGS) $(CXXFLAGS) -o $@ -c $<
LLINK			= $(AR) csr $@ $^
LINK			= $(LD) $(LDFLAGS) -o $@ $^

# Deactivate default rules
MAKEFLAGS               := -rR --warn-undefined-variables

# Directories
LIBK_DIR		:= lib/libk
LIBKXX_DIR		:= lib/libkxx
CORE_DIR		:= core
ARCH_DIR		:= arch/$(ARCH)
PLATFORM_DIR	        := $(ARCH_DIR)/$(PLATFORM)
MODULES_DIR		:= modules
SCRIPTS_DIR		:= scripts

# Flags
CFLAGS			:=
CXXFLAGS 		:= -nostdinc -nostdlib -ffreestanding -fno-builtin \
-fno-exceptions -fno-rtti -std=c++0x -O2
LDFLAGS			:=

# Config
CONFIG_SCRIPT           := $(SCRIPTS_DIR)/config.sh
CONFIG_HEADER	        := config.hh

# Dependancies
DEPEND_SCRIPT	        := $(SCRIPTS_DIR)/depend.sh

# Include the macros
include mk/macros.mk

# Include the top-level rules.mk
include rules.mk

