# Sub-directories

# Add local sources
$(eval $(call add_sources,platform.cc))

# Build archive
$(eval $(call make_archive,platform-$(PLATFORM).a))
