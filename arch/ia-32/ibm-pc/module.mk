# Sub-directories

# Adding ld script
LDFLAGS 	+= -T $(D)/linker.lds

# Add local sources
$(eval $(call add_sources,console.cc))

# Build archive
$(eval $(call make_archive,platform-$(PLATFORM).a))

