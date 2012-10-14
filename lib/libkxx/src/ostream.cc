#include <ostream>

namespace std
{
    // num_put
    num_put::num_put(size_t refs)
    {
        // FIXME
    }
    
    num_put::~num_put()
    {
    }

    // ostreambuf_iterator
    ostreambuf_iterator::ostreambuf_iterator(ostream& s)
      : buffer_(s.rdbuf())
    {
    }

    ostreambuf_iterator::ostreambuf_iterator(streambuf* s)
      : buffer_(s)
    {
    }

    // ostream
    ostream::ostream(streambuf* sb)
    {
        init(sb);
    }

    ostream::~ostream()
    {
    }
}
