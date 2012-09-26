# Add local sources
$(eval $(call add_sources,core.cc))

# Build archive
$(eval $(call make_archive,core.a))

