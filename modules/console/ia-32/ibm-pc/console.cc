#include "modules/console/ia-32/ibm-pc/console.hh"

namespace module
{
  static Console& Console::instance_(*(new ia32::ibmpc::Console()));

  namespace ia32
  {
    namespace ibmpc
    {
      void Console::print_char(char c)
      {
        static char *buffer = (char *)0xb8000;

        buffer[0] = c;
      }
    }
  }
}

