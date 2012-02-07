#ifndef HAL_VIDEO_BUFFER_HH_
# define HAL_VIDEO_BUFFER_HH_

namespace hal
{
	class VideoBuffer
	{
		public:
			enum VideoMode
			{
				TEXT,
				GRAPHIC
			};

		public:
			void set_mode(VideoMode mode) = 0;		
			void put_char() = 0;
			void plot_pixel() = 0;
	};
}

#endif /* !HAL_VIDEO_BUFFER_HH_ */
