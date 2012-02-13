# Sub-directories
$(eval $(call add_subdirectory,$(PLATFORM)))

# Add local sources
$(eval $(call add_sources,loader.S))

# Build archive
$(eval $(call make_archive,arch-$(ARCH).a))

