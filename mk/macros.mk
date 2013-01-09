# Initialize some variables
D:= $(ROOT_DIR)

# Define macros
define add_subdirectory
DIR		:= $$(D)/$1
SP		:= $$(SP).x

DIRSTACK_$$(SP)	:= $$(D)
D		:= $$(DIR)
include		$$(DIR)/module.mk
D		:= $$(DIRSTACK_$$(SP))
SP		:= $$(basename $$(SP))
endef

define add_include
CPPFLAGS 	:= $$(CPPFLAGS) -I$$(D)/$1
endef

define add_include_abs
CPPFLAGS 	:= $$(CPPFLAGS) -I$1
endef

define add_sources
SOURCES_$$(D)	:= $1

OBJS_$$(D)	:= $$(SOURCES_$$(D):%.c=%.o)
OBJS_$$(D)	:= $$(OBJS_$$(D):%.cc=%.o)
OBJS_$$(D)	:= $$(OBJS_$$(D):%.S=%.o)
OBJS_$$(D)	:= $$(OBJS_$$(D):%.o=$$(D)/%.o)

OBJS_$$(D)	:= $$(subst $$(ROOT_DIR)/,,$$(OBJS_$$(D)))

DEPS_$$(D) 	:= $$(OBJS_$$(D):%.o=%.d)

CLEAN		:= $$(CLEAN) $$(OBJS_$$(D)) $$(DEPS_$$(D))

-include $$(DEPS_$$(D))
endef

define make_archive
$$(subst $$(ROOT_DIR)/,,$$(D))/$1: $$(OBJS_$$(D))
	@mkdir -p `dirname $$@`
	$$(LLINK)

CLEAN		:= $$(CLEAN) $$(D)/$1
endef

define make_binary
BINARY		:= $1
SOURCES		:= $2
BINARIES 	:= $$(BINARIES) $1
CLEAN		:= $$(CLEAN) $1

$$(BINARY): $$(SOURCES)
	$$(LINK)
endef
