# Sub-directories
$(eval $(call add_subdirectory,$(PLATFORM)))

# Add local sources
$(eval $(call add_sources,video.cc))

