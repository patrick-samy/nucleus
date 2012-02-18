#ifndef ARM_REALVIEW_PBX_A9_CONSOLE_HH_
# define ARM_REALVIEW_PBX_A9_CONSOLE_HH_

# include "modules/console/arm/console.hh"

namespace realview_pbx_a9
{
  class Console : public arm::Console
  {
    public:
	static Console& instance();

    private:
      virtual void print_char(char c);
  };
}

#endif /* !ARM_REALVIEW_PBX_A9_CONSOLE_HH_ */
