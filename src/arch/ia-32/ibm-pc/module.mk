LDFLAGS	+= -T src/arch/ia-32/ibm-pc/linker.lds

SRC	+= src/arch/ia-32/ibm-pc/console.cc \
	   src/arch/ia-32/ibm-pc/loader.S
