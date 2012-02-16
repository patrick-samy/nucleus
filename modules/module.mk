# Add subdirectories
$(eval $(call add_subdirectory,console))

# Add local sources
OBJS_$(D)	:= $(OBJS_./modules/console)

# Build archive
$(eval $(call make_archive,modules.a))

