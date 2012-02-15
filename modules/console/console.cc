#include "console.hh"

namespace module
{
  Console::Console()
  {

  }

  Console::Console(Console& c)
  {

  }
  
  Console& Console::instance()
  {
    return instance_;
  }

  void Console::print_string(const char* str)
  {
    while (*str != '\0')
      print_char(*(str++));
  }               

  void Console::operator<< (const char* str)
  {
    print_string(str);
  }
}

