#include "modules/console/arm/omap/console.hh"

namespace platform 
{
  Console& Console::instance()
  {
    static Console instance;

    return instance;
  }


  void Console::print_char(char c)
  {
    volatile static unsigned int* const buffer = (unsigned int *) 0x48020000;

    *buffer = (unsigned int) c;
  }
}

