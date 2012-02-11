#include "core/console.hh"

namespace core
{
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
