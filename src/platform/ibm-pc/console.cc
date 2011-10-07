#include "platform/ibm-pc/console.hh"

namespace ibm_pc
{
	void Console::print_char(char c)
	{
		buffer[x_pos * width + y_pos] = c;

		if (++y_pos >= height)
		{
			++x_pos;
			y_pos = 0;
			x_pos = (x_pos >= width) ? 0 : x_pos;
		}
	}
}
