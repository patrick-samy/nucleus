#Default rule
all: targets

# Sub-directories
$(eval $(call add_subdirectory,lib/libk))
$(eval $(call add_subdirectory,lib/libkxx))
$(eval $(call add_subdirectory,lib/libabi))
$(eval $(call add_subdirectory,$(ARCH_DIR)))
$(eval $(call add_subdirectory,core))
$(eval $(call add_subdirectory,drivers))
$(eval $(call add_subdirectory,modules))

$(eval $(call add_include,.))

$(eval $(call make_binary,atom.elf,				    \
			  $(ARCH_DIR)/arch-$(ARCH).a		    \
			  $(PLATFORM_DIR)/platform-$(PLATFORM).a    \
			  $(CORE_DIR)/core.a			    \
			  $(MODULES)                                \
                          $(DRIVERS_DIR)/drivers.a                  \
                          $(LIBABI_DIR)/libabi.a                    \
			  $(LIBKXX_DIR)/libkxx.a		    \
			  $(LIBK_DIR)/libk.a))

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

