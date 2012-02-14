.section .multiboot
	.align		4
	.long		0x1badb002
	.long		0x7
	.long		-(0x1badb002 + 0x7)

.global k_entry

k_entry:
	push %ebx	/* multiboot info */
	push %eax	/* magic */
	call main	/* kernel entry point */
        cli
        hlt

