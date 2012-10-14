# Add include directory
$(eval $(call add_include,src))
$(eval $(call add_include,../libk/src))

# Add subdirectories
$(eval $(call add_sources,src/ios_base.cc   \
                          src/ios.cc        \
                          src/streambuf.cc))

# Build archive
$(eval $(call make_archive,libkxx.a))

