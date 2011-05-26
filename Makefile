include config.mk

all: build floppy

build:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done

floppy:
	$(MKDIR) $(TMP_DIR)
	$(CP) $(BOOT_DIR) $(TMP_DIR);
	$(CP) $(CORE_DIR)/$(CORE_BIN) $(TMP_DIR)/$(BOOT_DIR);
	$(GRUB_MKRESCUE) --modules=multiboot --output=$(CORE_IMG) $(TMP_DIR)
	$(RM) $(TMP_DIR);

boot: all
	$(QEMU) $(QEMU_OPTIONS) -fda $(CORE_IMG)

clean:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(RM) $(TMP_DIR)

distclean: clean
	$(RM) $(CORE_IMG)
