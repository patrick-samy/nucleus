#ifndef MODULE_CONSOLE_HH_
# define MODULE_CONSOLE_HH_

namespace module
{
  class Console
  {
    public:
      virtual Console& instance() = 0;

      void operator<< (const char* str);

    protected:
      Console();
      Console(Console& c);

    private:
      void print_string(const char* str);

      virtual void print_char(char c) = 0;
  };
}

#endif /* !MODULE_CONSOLE_HH_ */
