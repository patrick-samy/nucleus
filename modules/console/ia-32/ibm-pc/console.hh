#ifndef MODULE_IA32_IBMPC_CONSOLE_HH_
# define MODULE_IA32_IBMPC_CONSOLE_HH_

# include "modules/console/console.hh"

namespace module
{
  namespace ia32
  {
    namespace ibmpc
    {
      class Console : public module::Console
      {
        public:
	  virtual void print_char(char c);
      };
    }
  }
}

#endif /* !MODULE_IA32_IBMPC_CONSOLE_HH_ */

