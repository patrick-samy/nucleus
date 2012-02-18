#include "modules/console/arm/realview-pbx-a9/console.hh"

namespace realview_pbx_a9
{
  Console& Console::instance()
  {
    static Console instance;

    return instance;
  }


  void Console::print_char(char c)
  {
    volatile static unsigned int* const buffer = (unsigned int *) 0x10009000;

    *buffer = (unsigned int) c;
  }
}

