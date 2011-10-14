#ifndef CORE_CONSOLE_HH_
# define CORE_CONSOLE_HH_

namespace core
{
	class Console
	{	
		public:
			void print_string(const char* str);

			void operator<< (const char* str);

			virtual void print_char(const char c) = 0;

		private:
	};
}

#endif /* !CORE_CONSOLE_HH_ */
