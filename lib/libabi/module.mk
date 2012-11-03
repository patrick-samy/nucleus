# Add include directory
$(eval $(call add_include,src))

# Add subdirectories
$(eval $(call add_sources,src/cxa.c \
                          src/dso.c))

# Build archive
$(eval $(call make_archive,libabi.a))

