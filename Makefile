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
CCOMP			= $(CC) -MD $(CPPFLAGS) $(CFLAGS) -c $< -o $@
CXXCOMP			= $(CXX) -MD $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
LLINK			= $(AR) csr $@ $^
LINK			= $(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Deactivate default rules and show warnings
MAKEFLAGS               := --no-builtin-rules --no-builtin-variables  	\
			   --warn-undefined-variables

# Directories
LIB_DIR			:= lib
LIBKXX_DIR		:= lib/libkxx
LIBC_DIR		:= lib/libc
CORE_DIR		:= core
ARCH_DIR		:= arch/$(ARCH)
PLATFORM_DIR	        := platform/$(PLATFORM)
DRIVERS_DIR		:= drivers
MODULES_DIR		:= modules
SCRIPTS_DIR		:= scripts

# Flags
CPPFLAGS                := $(if $(filter $(BUILD_TYPE), release), -O2 -g0) \
			   $(if $(filter $(BUILD_TYPE), debug), -O0 -g3)
CFLAGS			:=
CXXFLAGS 		:= -ffreestanding -std=gnu++11
ASFLAGS                 :=
LDFLAGS			:= -B$(LIBC_DIR)/src -static                      \
                           -T $(ROOT_DIR)/$(PLATFORM_DIR)/memory.ld       \
                           -T $(ROOT_DIR)/nucleus.ld -Wl,-Map=nucleus.map
CLEAN			+= nucleus.map
TARGET_ARCH             :=
TARGET_MACH             :=

# Config
CONFIG_SCRIPT           := $(SCRIPTS_DIR)/config.sh
CONFIG_HEADER	        := config.hh

# Include the macros
include $(ROOT_DIR)/mk/macros.mk

# Include the top-level rules.mk
include $(ROOT_DIR)/rules.mk
