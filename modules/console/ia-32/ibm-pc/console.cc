#include "modules/console/ia-32/ibm-pc/console.hh"

namespace module
{
  namespace ia32
  {
    namespace ibmpc
    {
      module::Console& Console::instance()
      {
        static Console instance;

	return instance;
      }

      void Console::print_char(char c)
      {
        static char *buffer = (char *)0xb8000;

        buffer[0] = c;
      }
    }
  }
}

