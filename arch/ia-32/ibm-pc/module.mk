# Sub-directories

# Adding ld script
LDFLAGS 	+= -T $(D)/linker.lds

# Add local sources

# Build archive
$(eval $(call make_archive,platform-$(PLATFORM).a))

