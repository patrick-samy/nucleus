include config.mk

all: build floppy

build:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done

floppy: build
	$(MKDIR) $(BUILD_DIR)
	$(CP) $(BOOT_DIR) $(BUILD_DIR);
	$(CP) $(SRC_DIR)/$(CORE_BIN) $(BUILD_DIR)/$(BOOT_DIR);
	$(GRUB_MKRESCUE) --modules=multiboot --output=$(CORE_IMG) $(BUILD_DIR)
	$(RM) $(BUILD_DIR);

boot: all
	$(QEMU) $(QEMU_OPTIONS) -fda $(CORE_IMG)

clean:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(RM) $(BUILD_DIR)

distclean: clean
	$(RM) $(CORE_IMG)
