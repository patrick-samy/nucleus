# Add subdirectories
#$(eval $(call add_subdirectory,src))

# Add local sources
$(eval $(call add_sources,console.cc core.cc))

# Build archive
$(eval $(call make_archive,core.a))

