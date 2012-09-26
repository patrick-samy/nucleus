# Add include directory
$(eval $(call add_include,include))

# Add subdirectories
$(eval $(call add_sources,src/ios_base.cc))

# Build archive
$(eval $(call make_archive,libkxx.a))

