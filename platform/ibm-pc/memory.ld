OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH("i386")

/* Kernel memory layout */
MEMORY
{
  code  : org = 0x1000000, len = 1M
  data  : org = 0x20000, len = 1M
  heap  : org = 0x3000, len = 4K
  stack : org = 0x2000, len = 4K
}
