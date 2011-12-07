include config.mk

# Initialize sources variable
SRC :=

# Include modules description
include $(patsubst %, %/module.mk, $(MODULES))

# Substitution to build OBJS variable
OBJS := $(patsubst %.cc, %.o, $(filter %.cc, $(SRC))) \
$(patsubst %.S,%.o, $(filter %.S,$(SRC)))

# Produce the binary
$(BIN): $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

$(IMG): $(BIN)
	$(RM) $(BUILD_DIR)
	$(MKDIR) $(BUILD_DIR)
	$(CP) $(BOOT_DIR) $(BUILD_DIR)
	$(CP) $(BIN) $(BUILD_DIR)/$(BOOT_DIR)
	$(GRUB_MKRESCUE) --modules=multiboot --output=$(IMG) $(BUILD_DIR)
	$(RM) $(BUILD_DIR)

# Build config header
$(CONFIG_HEADER):
	$(SH) $(CONFIG_SCRIPT) $(ARCH) $(PLATFORM) > $(INCLUDE_DIR)/$(CONFIG_HEADER)

# Build object files
%.o: %.cc
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.S
	$(CXX) -c $< -o $@

# Build dependencies files
%.d: %.cc
	$(SH) $(DEPEND_SCRIPT) `dirname $*.cc` $(CFLAGS) $*.cc > $@

%.d: %.S
	$(SH) $(DEPEND_SCRIPT) `dirname $*.S` $(CFLAGS) $*.S > $@

# Include dependancies files
include $(OBJS:.o=.d) 

# Common rules
all: $(IMG)

boot: all
	$(QEMU) $(QEMU_OPTIONS) -fda $(IMG)

clean:
	$(FIND) . -name '*.o' -exec rm -rf {} \;
	$(FIND) . -name '*.d' -exec rm -rf {} \;
	$(RM) $(IMG) $(BIN)
	$(RM) $(BUILD_DIR)
	$(RM) $(INCLUDE_DIR)/$(CONFIG_HEADER)

distclean: clean

