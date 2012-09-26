# Add subdirectories

# Add local sources
$(eval $(call add_sources,console.cc 		\
			  $(ARCH)/console.cc			\
			  $(ARCH)/$(PLATFORM)/console.cc))

# Build archive

