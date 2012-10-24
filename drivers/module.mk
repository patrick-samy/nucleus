# TODO: Fix this !
# Sub-directories
#$(eval $(call add_subdirectory,video))
$(eval $(call add_sources,video/video.cc     \
                          video/ibm-pc/vga.cc))

# Build archive
$(eval $(call make_archive,drivers.a))

