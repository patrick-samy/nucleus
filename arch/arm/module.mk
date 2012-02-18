# Sub-directories
$(eval $(call add_subdirectory,$(PLATFORM)))

# Add local sources

# Build archive
$(eval $(call make_archive,arch-$(ARCH).a))

