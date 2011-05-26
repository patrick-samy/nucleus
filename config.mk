# Build tools
MAKE	      	= make
CXX 	      	= g++
LD	      	= ld

GRUB_MKRESCUE 	= grub-mkrescue
QEMU	      	= qemu

MKDIR	      	= mkdir
CP	      	= cp -rf
RM	      	= rm -rf
FIND	      	= find
XARGS	      	= xargs

# Flags
CXX_FLAGS 	= -nostdlib -ffreestanding -fno-builtin -fno-exceptions -fno-rtti

# Options
QEMU_OPTIONS 	= -no-reboot

# Output
CORE_BIN  	= core.bin
CORE_IMG  	= core.img
TMP_DIR	  	= tmp

# Directories
CORE_DIR  	= core
BOOT_DIR  	= boot

SUBDIRS		= $(CORE_DIR) core
