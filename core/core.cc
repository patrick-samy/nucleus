#include "config.hh"
#include "modules/console/console.hh"

#define ever (;;)

void __cxa_pure_virtual()
{
  for ever;
}

void main()
{
  module::Console& c;

  c << "[Atom] Starting kernel...\n";

  for ever;
}
