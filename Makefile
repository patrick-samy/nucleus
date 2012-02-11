include config.mk

# Include modules description
include $(patsubst %, %/module.mk, $(MODULES))

# Substitution to build OBJS variable
OBJS := $(patsubst %.cc, %.o, $(filter %.cc, $(SRC))) \
$(patsubst %.S,%.o, $(filter %.S,$(SRC)))

# Produce the binary
$(BIN): $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

# Build config header
$(CONFIG_HEADER):
	sh $(CONFIG_SCRIPT) $(ARCH) $(PLATFORM) > $(INCLUDE_DIR)/$(CONFIG_HEADER)

# Build object files
%.o: %.cc
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.S
	$(CXX) -c $< -o $@

# Build dependencies files
%.d: %.cc
	sh $(DEPEND_SCRIPT) `dirname $*.cc` $(CFLAGS) $*.cc > $@

%.d: %.S
	sh $(DEPEND_SCRIPT) `dirname $*.S` $(CFLAGS) $*.S > $@

# Include dependancies files
include $(OBJS:.o=.d) 

# Common rules
all: $(BUILD_OUTPUT)

clean:
	find . -name '*.o' -exec rm -rf {} \;
	find . -name '*.d' -exec rm -rf {} \;
	rm -rf $(BUILD_OUTPUT)
	rm -rf $(BUILD_DIR)
	rm -rf $(INCLUDE_DIR)/$(CONFIG_HEADER)

distclean: clean

