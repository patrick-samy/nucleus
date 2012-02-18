.global _start
_start:
	LDR sp, =stack_top
	BL main
	B .
