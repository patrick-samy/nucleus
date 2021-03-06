#Default rule
all: targets

# Sub-directories
$(eval $(call add_subdirectory,$(ARCH_DIR)))
$(eval $(call add_subdirectory,$(PLATFORM_DIR)))
$(eval $(call add_subdirectory,core))
$(eval $(call add_subdirectory,drivers))
$(eval $(call add_subdirectory,modules))
$(eval $(call add_subdirectory,$(LIBC_DIR)))

$(eval $(call add_include,.))

$(eval $(call add_include_abs,.)) # needed to find core/config.hh

$(eval $(call make_binary,nucleus.elf,                            \
                          $(ARCH_DIR)/arch-$(ARCH).a              \
                          $(PLATFORM_DIR)/platform-$(PLATFORM).a  \
                          $(CORE_DIR)/core.a                      \
                          $(MODULES)                              \
                          $(DRIVERS_DIR)/drivers.a))

$(CORE_DIR)/$(CONFIG_HEADER):
	sh $(CONFIG_SCRIPT) $(ARCH) $(PLATFORM) > $@

# Generic rules
VPATH := $(ROOT_DIR)
%.o: %.c $(DEPENDENCIES)
	@mkdir -p `dirname $@`
	$(CCOMP)

%.o: %.cc $(DEPENDENCIES)
	@mkdir -p `dirname $@`
	$(CXXCOMP)

%.o: %.S $(DEPENDENCIES)
	@mkdir -p `dirname $@`
	$(CCOMP)

# Misc rules
.SUFFIXES:

.PHONY: targets
targets: $(TARGETS)

.PHONY: clean
clean:
	rm -rf $(CLEAN)

.PHONY: distclean
distclean: clean
	rm -rf $(DISTCLEAN)
