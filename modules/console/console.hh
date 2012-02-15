#ifndef MODULE_CONSOLE_HH_
# define MODULE_CONSOLE_HH_

namespace module
{
  class Console
  {
    public:
      Console& instance();

      void operator<< (const char* str);

    private:
      Console();
      Console(Console& c);

      void print_string(const char* str);

      virtual void print_char(char c) = 0;
      
      static Console& instance_;
  };
}

#endif /* !MODULE_CONSOLE_HH_ */

