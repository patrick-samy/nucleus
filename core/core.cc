#include "core/macros.hh"
#include module(console)

#define ever (;;)

void main()
{
  platform::Console& c = platform::Console::instance();

  c << platform::Console::CYAN;
  c << platform::Console::LIGHT;
  c << "Atom kernel loaded.\n";

  for ever;
}
