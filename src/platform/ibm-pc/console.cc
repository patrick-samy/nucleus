#include "platform/ibm-pc/console.hh"

namespace ibm_pc
{
	Console::Console()
	   : buffer((console_char_t *) 0xb8000)
	{
	}

	void Console::print_char(char c)
	{
		int width = 80;
		int height = 25;

		buffer[x_pos * width + y_pos].ch = c;

		if (++y_pos >= height)
		{
			++x_pos;
			y_pos = 0;
			x_pos = (x_pos >= width) ? 0 : x_pos;
		}
	}
}
