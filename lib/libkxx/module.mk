# Add include directory
$(eval $(call add_include,src))
$(eval $(call add_include,../libk/src))

# Add subdirectories
$(eval $(call add_sources,src/ios_base.cc   \
                          src/ios.cc        \
                          src/ostream.cc    \
                          src/streambuf.cc  \
                          src/new.cc))

# Build archive
$(eval $(call make_archive,libkxx.a))

