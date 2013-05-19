ENTRY(_start)
INPUT(core/core.a)
STARTUP(crt1.o)
SECTIONS
{
  .rela.text : { *(.rela.text) *(.rela.gnu.linkonce.t*) }
  .rela.data : { *(.rela.data) *(.rela.gnu.linkonce.d*) }
  .rela.rodata : { *(.rela.rodata) *(.rela.gnu.linkonce.r*) }
  .rela.got : { *(.rela.got) }
  .rela.got1 : { *(.rela.got1) }
  .rela.got2 : { *(.rela.got2) }
  .rela.ctors : { *(.rela.ctors) }
  .rela.dtors : { *(.rela.dtors) }
  .rela.init : { *(.rela.init) }
  .rela.fini : { *(.rela.fini) }
  .rela.bss : { *(.rela.bss) }
  .rela.plt : { *(.rela.plt) }
  .rela.sdata : { *(.rela.sdata2) }
  .rela.sbss : { *(.rela.sbss2) }
  .rela.sdata2 : { *(.rela.sdata2) }
  .rela.sbss2 : { *(.rela.sbss2) }

  .text :
  {
    *(.text)
    *(.gnu.warning)
    *(.gnu.linkonce.t*)
  } > code

  .init : { *(.init) } > code
  .fini : { *(.fini) } > code
  _etext = .;

  .rodata : { *(.rodata) *(.gnu.linkonce.r*) } > data
  .rodata1 : { *(.rodata1) } > data
  .gcc_except_table : { *(.gcc_except_table) } > data

  .sdata2 : { *(.sdata2) } > data
  .sbss2 : { *(.sbss2) } > data

  .data :
  {
    *(.data)
    *(.gnu.linkonce.d*)
    CONSTRUCTORS
  } > data
  .data1 : { *(.data1) } > data

  .ctors :
  {
    PROVIDE (__CTOR_LIST__ = .);
    *(.ctors)
    PROVIDE (__CTOR_END__ = .);
  } > data

  .dtors :
  {
    PROVIDE (__DTOR_LIST__ = .);
    *(.dtors)
    PROVIDE (__DTOR_END__ = .);
  } > data

  .sdata :
  {
    *(.sdata)
    _edata  =  .;
    PROVIDE (edata = .);
  } > data

  .sbss :
  {
    PROVIDE (__sbss_start = .);
    *(.sbss)
    *(.scommon)
    PROVIDE (__sbss_end = .);
  } > data

  .bss :
  {
     PROVIDE (__bss_start = .);
    *(.dynbss)
    *(.bss)
    *(COMMON)
    _end = . ;
    PROVIDE (end = .);
  } > data

  .stack :
  {
    PROVIDE(__stack_bottom = .);
    PROVIDE(__stack = ABSOLUTE(.));
  } > stack

  /* These are needed for ELF backends which have not yet been
     converted to the new style linker.  */
  .stab 0 : { *(.stab) }
  .stabstr 0 : { *(.stabstr) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* These must appear regardless of  .  */
}
