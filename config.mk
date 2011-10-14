# Build tools
MAKE	      	= make
CXX 	      	= g++
LD	      	= ld
AR		= ar csr

GRUB_MKRESCUE 	= grub-mkrescue
QEMU	      	= qemu

MKDIR	      	= mkdir
CP	      	= cp -rf
RM	      	= rm -rf
FIND	      	= find
XARGS	      	= xargs

# Options
QEMU_OPTIONS 	= -no-reboot

# Output
BIN		= core.bin
IMG		= core.img
BUILD_DIR	= tmp

# Machine 
ARCH		= ia-32
PLATFORM	= ibm-pc

# Directories
BOOT_DIR  	= boot
INCLUDE_DIR	= include
SRC_DIR  	= src
CORE_DIR	= core
ARCH_DIR	= architecture/$(ARCH)
PLATFORM_DIR	= platform/$(PLATFORM)

SUBDIRS		= $(SRC_DIR)	# Root source directory

# Flags
CFLAGS		= -I$(INCLUDE_DIR)
CXXFLAGS 	= -nostdlib -ffreestanding -fno-builtin -fno-exceptions -fno-rtti
LDFLAGS		=

