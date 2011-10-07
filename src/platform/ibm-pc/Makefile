include ../../../config.mk
include sources.mk

build: $(LIB)

%a: $(OBJS)
	$(AR) $(LIB) $(OBJS)

%o: %cc
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

%o: %S
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

clean:
	for I in $(SUBDIRS);		\
	do				\
		$(MAKE) -C $$I $@;	\
	done
	$(RM) $(OBJS) $(LIB)
