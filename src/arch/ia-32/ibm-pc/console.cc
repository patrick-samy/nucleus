#include "arch/ia-32/ibm-pc/console.hh"

namespace ibmpc
{
	Console::Console()
          : buffer((console_char_t *) 0xb8000),
            x_pos(0),
            y_pos(0)
	{
          for (int i = 0; i < 80 * 25; ++i)
            buffer[i].ch = 0;
	}

	void Console::print_char(char c)
	{
		int width = 80;
		int height = 25;

                if (c == '\n')
                {
                  x_pos = 0;
                  ++y_pos;
                  return;
                }

		buffer[y_pos * width + x_pos].ch = c;

		if (++x_pos >= width)
		{
			++y_pos;
			x_pos = 0;
			y_pos = (y_pos >= height) ? 0 : y_pos + 1;
		}
	}
}
