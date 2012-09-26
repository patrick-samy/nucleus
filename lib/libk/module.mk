# Add subdirectories
$(eval $(call add_subdirectory,src))

# Add local sources
#$(eval $(call add_sources,XXX.c))

# Build archive
$(eval $(call make_archive,libk.a))

