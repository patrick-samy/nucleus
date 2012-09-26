#ifndef IA32_IBMPC_CONSOLE_HH_
# define IA32_IBMPC_CONSOLE_HH_

# include "modules/console/console.hh"

namespace platform 
{
  class Console : public module::Console
  {
    private:
      typedef struct console_char
      {
        char ch;
        char fg:4;
        char bg:4;
      } __attribute__((packed)) console_char_t;

    public:
      static Console& 	instance();

      void operator<<(const char* str);
      void operator<<(console_modifiers_e mod);

      void print_char(char c);
      void clear();

    private:
      Console();

    private:
      int		modifier_;
      unsigned int	row_;
      unsigned int	col_;
  };
}

#endif /* !MODULE_IA32_IBMPC_CONSOLE_HH_ */

