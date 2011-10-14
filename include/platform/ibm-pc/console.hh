#ifndef PLATFORM_CONSOLE_HH_
# define PLATFORM_CONSOLE_HH_

#include "core/console.hh"

namespace ibm_pc
{
	class Console : public core::Console
	{
		typedef struct console_char
		{
			char ch;
			char fg:4;
			char bg:4;
		} __attribute__((packed)) console_char_t;

		public:
			Console();
			virtual void print_char(char c);

		private:
			console_char_t* const 	buffer;			
			int			x_pos;
			int			y_pos;
	};
}

#endif /* !PLATFORM_CONSOLE_HH_ */

