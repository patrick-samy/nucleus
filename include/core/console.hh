#ifndef CORE_CONSOLE_HH_
# define CORE_CONSOLE_HH_

namespace core
{
	public:
		const int endl = 1; 

	class Console
	{	
		public:
			void print_string(char* str);

			void operator<< (char* str);

			virtual void print_char(char c) = 0;

		private:
	};
}

#endif /* !CORE_CONSOLE_HH_ */
