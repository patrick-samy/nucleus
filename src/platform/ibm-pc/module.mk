LDFLAGS	+= -T src/platform/ibm-pc/linker.lds

SRC	+= src/platform/ibm-pc/console.cc \
	   src/platform/ibm-pc/loader.S
