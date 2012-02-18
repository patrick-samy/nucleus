ENTRY(_start)

SECTIONS
{
	. = 0x80000000;

	.loader . :
	{
		arch/arm/omap/loader.o(.text)
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
}
