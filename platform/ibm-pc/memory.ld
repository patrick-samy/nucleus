OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH("i386")

/* Kernel memory layout */
MEMORY
{
  code  : org = 0x1000000, len = 1M
  data  : org = 0x20000, len = 1M
  stack : org = 0x10000, len = 4K
}
