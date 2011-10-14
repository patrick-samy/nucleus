include config.mk

# Modules
MODULES := src/core src/architecture/$(ARCH) src/platform/$(PLATFORM)

# Initialize sources variable
SRC := src/main.cc

# Include modules description
include $(patsubst %, %/module.mk, $(MODULES))

# Substitution to build OBJS variable
OBJS := $(patsubst %.cc, %.o, $(filter %.cc, $(SRC))) \
$(patsubst %.S,%.o, $(filter %.S,$(SRC)))

# Produce the binary
$(BIN): $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS) 

$(IMG): $(BIN)
	$(MKDIR) $(BUILD_DIR)
	$(CP) $(BOOT_DIR) $(BUILD_DIR)
	$(CP) $(SRC_DIR)/$(CORE_BIN) $(BUILD_DIR)/$(BOOT_DIR)
	$(GRUB_MKRESCUE) --modules=multiboot --output=$(CORE_IMG) $(BUILD_DIR)
	$(RM) $(BUILD_DIR)

# Build object files
%.o: %.cc
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.S
	$(CXX) -c $< -o $@

# Include dependancies files
include $(OBJ:.o=.d)

# Build dependencies files
%.d: %.cc
	sh depend.sh `dirname $*.cc` $(CFLAGS) $*.cc > $@

# Common rules
all: $(IMG)

boot: all
	$(QEMU) $(QEMU_OPTIONS) -fda $(IMG)

clean:
	$(FIND) . -name '*.o' -exec rm -rf {} \;
	$(RM) $(IMG) $(BIN)

distclean: clean

