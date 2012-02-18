#include "modules/console/arm/console.hh"

namespace arm 
{
  void Console::operator<<(const char* str)
  {
    module::Console::operator<<(str);
  }

  void Console::operator<<(console_modifiers_e mod)
  {
  }
}

