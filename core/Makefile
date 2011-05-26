include ../config.mk
include sources.mk

build: $(OBJS)
	$(LD) $^ -o $(CORE_BIN) $(LD_FLAGS)

%o: %c
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

%o: %S
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

clean:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(RM) $(OBJS) $(CORE_BIN)
