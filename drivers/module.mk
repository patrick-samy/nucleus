# Sub-directories
$(eval $(call add_subdirectory,video))

# Build archive
$(eval $(call make_archive,drivers.a))

