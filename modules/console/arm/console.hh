#ifndef ARM_CONSOLE_HH_
# define ARM_CONSOLE_HH_

# include "modules/console/console.hh"

namespace arch
{
  class Console : public module::Console
  {
    public:
      void operator<<(const char* str);
      void operator<<(console_modifiers_e mod);
  };
}

#endif /* !MODULE_ARM_CONSOLE_HH_ */

