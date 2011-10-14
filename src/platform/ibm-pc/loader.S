.section .multiboot
	.align		4
	.long		0x1badb002
	.long		0x7
	.long		-(0x1badb002 + 0x7)

.global k_entry

.global __cxa_pure_virtual

__cxa_pure_virtual:
	nop
	jmp	__cxa_pure_virtual

k_entry:
	push %ebx	/* multiboot info */
	push %eax	/* magic */
	call main	/* kernel entry point */
