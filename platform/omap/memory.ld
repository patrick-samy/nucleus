/* Default linker script, for normal executables */
/* Kernel memory layout */
MEMORY
{
  code  : org = 0xc000000, len = 1M
  data  : org = 0x20000, len = 1M
  stack : org = 0x1000, len = 4K
}
