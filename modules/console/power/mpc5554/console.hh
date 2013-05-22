#ifndef PPC_MPC5554_CONSOLE_HH_
# define PPC_MPC5554_CONSOLE_HH_

namespace platform
{
  class Console
  {
    public:
	static Console& instance();

    private:
      virtual void print_char(char c);
  };
}

#endif /* !PPC_MPC5554_CONSOLE_HH_ */
