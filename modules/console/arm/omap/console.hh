#ifndef ARM_OMAP_CONSOLE_HH_
# define ARM_OMAP_CONSOLE_HH_

//# include "modules/console/arm/console.hh"

namespace platform
{
  class Console// : public arm::Console
  {
    public:
	static Console& instance();

    private:
      virtual void print_char(char c);
  };
}

#endif /* !ARM_OMAP_CONSOLE_HH_ */
