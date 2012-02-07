#ifndef HAL_CPU_HH_
# define HAL_CPU_HH_

namespace hal
{
	class Cpu
	{
		public:
			void activate_paging();
			void shutdown();

		private:
	}
}

#endif /* !HAL_CPU_HH_ */
