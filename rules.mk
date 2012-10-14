#Default rule
all: targets

# Sub-directories
$(eval $(call add_subdirectory,lib/libk))
$(eval $(call add_subdirectory,lib/libkxx))
$(eval $(call add_subdirectory,modules))
$(eval $(call add_subdirectory,core))
$(eval $(call add_subdirectory,$(ARCH_DIR)))

$(eval $(call add_include,.))

$(eval $(call make_binary,atom.elf,				    \
			  $(LIBK_DIR)/libk.a			    \
			  $(LIBKXX_DIR)/libkxx.a		    \
			  $(PLATFORM_DIR)/platform-$(PLATFORM).a    \
			  $(ARCH_DIR)/arch-$(ARCH).a		    \
			  $(CORE_DIR)/core.a			    \
			  $(MODULES_DIR)/modules.a))

$(CORE_DIR)/$(CONFIG_HEADER):
	sh $(CONFIG_SCRIPT) $(ARCH) $(PLATFORM) > $@

# Generic rules
%.o: %.c
	$(CCOMP)

%.o: %.cc
	$(CXXCOMP)

%.o: %.S
	$(CCOMP)

# Misc rules
.SUFFIXES:

.PHONY: targets
targets: $(BINARIES)

.PHONY: clean
clean:
	rm -rf $(CLEAN)

