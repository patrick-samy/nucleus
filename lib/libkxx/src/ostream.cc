#include <ostream>

namespace std
{
    ostream::ostream(streambuf* sb)
    {
        init(sb);
    }

    ostream::~ostream()
    {
    }
}
