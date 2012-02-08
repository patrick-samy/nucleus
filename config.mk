# Machine 
ARCH		:= ia-32
PLATFORM	:= ibm-pc

# Build tools
MAKE	      	:= make
CXX 	      	:= g++
LD	      	:= ld
AR		:= ar csr

GRUB_MKRESCUE 	:= grub-mkrescue
QEMU	      	:= qemu

MKDIR	      	:= mkdir
CP	      	:= cp -rf
RM	      	:= rm -rf
FIND	      	:= find
XARGS	      	:= xargs
SH		:= sh

# Options
QEMU_OPTIONS 	:= -no-reboot

# Directories
BOOT_DIR  	:= boot
SCRIPTS_DIR	:= scripts
LIB_DIR		:= lib
LIB_INCLUDE_DIR := $(LIB)/include
INCLUDE_DIR	:= include
SRC_DIR  	:= src
CORE_DIR	:= $(SRC_DIR)/core
ARCH_DIR	:= $(SRC_DIR)/arch/$(ARCH)
PLATFORM_DIR	:= $(ARCH_DIR)/$(PLATFORM)

# Modules
MODULES		:= $(SRC_DIR) $(CORE_DIR) $(ARCH_DIR) $(PLATFORM_DIR)

# Flags
CFLAGS		:= -I$(LIB_INCLUDE_DIR) -I$(INCLUDE_DIR)
CXXFLAGS 	:= -nostdlib -ffreestanding -fno-builtin -fno-exceptions -fno-rtti
LDFLAGS		:=

# Config
CONFIG_SCRIPT 	:= $(SCRIPTS_DIR)/config.sh
CONFIG_HEADER	:= config.hh

# Dependancies
DEPEND_SCRIPT	:= $(SCRIPTS_DIR)/depend.sh

# Output
BIN		:= atom.bin
IMG		:= atom.img
BUILD_DIR	:= tmp

