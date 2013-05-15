# Source Files
$(eval $(call add_sources,src/crt1.c))

# Build archive
$(eval $(call make_archive,libc.a))
