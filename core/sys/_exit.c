/* Stub version of _exit.  */

#include <limits.h>
#include "config.h"
#include <_ansi.h>
#include <_syslist.h>

_VOID
_DEFUN (_exit, (rc),
	int rc)
{
  /* Convince GCC that this function never returns.  */
  for (;;)
    ;
}
