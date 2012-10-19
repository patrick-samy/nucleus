# Add subdirectories
$(eval $(call add_subdirectory,console/$(ARCH)/$(PLATFORM)))

# Build archive
$(eval $(call make_archive,modules.a))

