#include "console.hh"

namespace core
{
	static const Console cout;

	void Console::print_string(const char* str)
	{
		while (*(str++) != '\0')
			print_char(*str);
	}

	void Console::operator<< (char* str)
	{
		print_string(str);
	}
}
