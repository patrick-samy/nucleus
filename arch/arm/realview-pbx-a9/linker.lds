ENTRY(_start)

SECTIONS
{
	. = 0x10000;

	.loader . :
	{
		arch/arm/realview-pbx-a9/loader.o(.text)
	}

	.text :
	{
		*(.text)
	}

	.data :
	{
		*(.data)
	}

	.bss :
	{
		*(.bss)
	}

	. = . + 0x1000;

	stack_top = .;
}

