# Add subdirectories
$(eval $(call add_sources,$(ARCH)/$(PLATFORM)/console.cc))

# Make archive
$(eval $(call make_archive,console.a))
