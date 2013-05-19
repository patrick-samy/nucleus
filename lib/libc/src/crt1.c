/** Multi-Architecture C runtime initilization & entry point of the kernel
 */
void __start(void)
{
  extern void* __stack;

  __init();
  main();
  __fini();

  /* Exit point */
  /* FIXME: call platform shutdown */


  /*
   * Actual entry point of the function to avoid the
   * compiler-generated prologue which requires the stack pointer to
   * be initialized while this is the purpose of this function.
   * Can't be written with a C label since they are not exported.
   */
  asm (".global _start;"
       "_start:");

  /*
   * GCC syntax to inialize the stack pointer as defined by the ABI,
   * portable as long as sp register is defined for every architecture
   * targeted (ok so far :)).  volatile applies to the pointer, to
   * avoid the compiler to optimize-out this unused variable.
   */
  register void* volatile sp asm ("sp") = (void*) &__stack;

  /*
   * The next step for userland crt files is to create a stack frame,
   * which is the purpose of a function prologue, so let's use the one
   * generated with this function and thus, again (stack pointer
   * initialization), delegate ABI stuffs to the compiler
   */
  __start(); /* shouldn't return */

  /*
   * Hack to optimize-out the compiler-generated function's epilog to
   * cut off the function here.
   */
  for (;;)
    ;
}
