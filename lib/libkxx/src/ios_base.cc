#include <ios_base>

namespace std
{
	ios_base::ios_base()
	{
	}

	ios_base::~ios_base()
	{
	}

	ios_base& ios_base::operator=(const ios_base&)
	{
	}

    void ios_base::init(void* buffer)
    {
        buffer_ = buffer;
        state_ = buffer_ ? ios_base::goodbit : ios_base::badbit;
        format_flags_ = ios_base::skipws | dec; 
        width_ = 0;
        precision_ = 6;
    }
}
