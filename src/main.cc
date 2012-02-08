#include "config.hh"
#include "arch/ia-32/ibm-pc/console.hh"

#define ever (;;)

void main()
{
  platform::Console c;

  c << "[Atom] Starting kernel...\n";

  //for ever;
}
