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
        format_flags_ = skipws | dec; 
        width_ = 0;
        precision_ = 6;
    }
}
