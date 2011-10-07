include ../config.mk
include sources.mk

build:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(LD) $(LIBS) -o $(CORE_BIN) $(LD_FLAGS)

clean:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(RM) $(CORE_BIN)
