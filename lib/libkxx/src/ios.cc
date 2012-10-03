#include <ios>

namespace std
{
    ios::ios()
    {
    }

    ios::ios(streambuf* buffer)
    {
        init(buffer);
    }

    ios::~ios()
    {
    }
}
