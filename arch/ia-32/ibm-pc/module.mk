LDFLAGS	+= -T arch/ia-32/ibm-pc/linker.lds

SRC	+= arch/ia-32/ibm-pc/console.cc \
	   arch/ia-32/ibm-pc/loader.S
