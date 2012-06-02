# Default rule
all: targets

# Sub-directories
$(eval $(call add_subdirectory,core))
$(eval $(call add_subdirectory,$(ARCH_DIR)))
$(eval $(call add_subdirectory,modules))

$(eval $(call add_include,.))

$(eval $(call make_binary,atom.elf,				 		\
			  $(PLATFORM_DIR)/platform-$(PLATFORM).a	\
			  $(ARCH_DIR)/arch-$(ARCH).a		 		\
			  $(CORE_DIR)/core.a			 			\
			  $(MODULES_DIR)/modules.a))

$(CORE_DIR)/$(CONFIG_HEADER):
	sh $(CONFIG_SCRIPT) $(ARCH) $(PLATFORM) > $@

CLEAN		:= $(CLEAN) $(CORE_DIR)/$(CONFIG_HEADER)

# Actual generic rules
%.o: %.c
	$(CCOMP)

%.o: %.cc
	$(CXXCOMP)

%.o: %.S
	$(CCOMP)

%.d: %.c
	$(CDEPS)

%.d: %.cc
	$(CDEPS)

%: %.o
	$(LINK)

# Misc rules
.PHONY: targets
targets: $(BINARIES)

.PHONY: clean
clean:
	rm -rf $(CLEAN)

