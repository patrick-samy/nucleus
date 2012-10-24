#include <ostream>

namespace std
{
    // ostream
    ostream::ostream()
    {
    }
    
    ostream::ostream(streambuf* sb)
    {
        init(sb);
    }

    ostream::~ostream()
    {
    }

    
    // ostream::sentry
    ostream::sentry::sentry(ostream& os)
      : ok_(os.good()),
        os_(os)
    {
    }

    ostream::sentry::~sentry()
    {
        if (os_.rdbuf() && os_.good() && (os_.flags() & ios_base::unitbuf))
        {
            if (os_.rdbuf()->pubsync() == -1)
                os_.setstate(ios_base::badbit);
        }
    }

    // num_put
    num_put::num_put(long refs)
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
}
