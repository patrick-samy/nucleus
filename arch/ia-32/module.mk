# Sub-directories
$(eval $(call add_subdirectory,$(PLATFORM)))

# Build archive
$(eval $(call make_archive,arch-$(ARCH).a))
