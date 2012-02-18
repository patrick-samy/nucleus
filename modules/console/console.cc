#include "console.hh"

extern "C"
void __cxa_pure_virtual()
{
}

extern "C"
int __cxa_guard_acquire(int *)
{

}

extern "C"
void __cxa_guard_release(int *)
{

}

namespace module
{
  Console::Console()
  {
    
  }

  Console::Console(Console& c)
  {

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

