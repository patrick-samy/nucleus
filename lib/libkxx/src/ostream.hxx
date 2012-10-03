#ifndef STD_STREAM_HXX_
# define STD_STREAM_HXX_

namespace std
{
    inline ostream& ostream::operator<<(bool val)
    {
        
    }

    inline ostream& ostream::operator<<(short val)
    {

    }

    inline ostream& ostream::operator<<(unsigned short val)
    {

    }

    inline ostream& ostream::operator<<(int val)
    {

    }

    inline ostream& ostream::operator<<(unsigned int val)
    {

    }

    inline ostream& ostream::operator<<(long val)
    {

    }

    inline ostream& ostream::operator<<(unsigned long val)
    {

    }

    inline ostream& ostream::operator<<(float val)
    {

    }

    inline ostream& ostream::operator<<(double val)
    {

    }

    inline ostream& ostream::operator<<(long double val)
    {

    }

    inline ostream& ostream::operator<<(const void* val)
    {

    }

    inline ostream& ostream::operator<<(streambuf* sb)
    {

    }

    inline ostream& ostream::operator<<(ostream& (*pf)(ostream&))
    {

    }

    inline ostream& ostream::operator<<(ios& (*pf)(ios&))
    {

    }

    inline ostream& ostream::operator<<(ios_base& (*pf)(ios_base&))
    {

    }

    inline ostream& ostream::operator<<(ostream& out, char c)
    {

    }

    inline ostream& ostream::operator<<(ostream& out, signed char c)
    {

    }

    inline ostream& ostream::operator<<(ostream& out, unsigned char c)
    {

    }

    inline ostream& ostream::operator<<(ostream& out, const char* s)
    {

    }

    inline ostream& ostream::operator<<(ostream& out, const signed char* s)
    {

    }

    inline ostream& ostream::operator<<(ostream& out, const unsigned char* s)
    {

    }

    inline ostream& ostream::put(char c)
    {
        ostreambuf_iterator it(*this);

        *it = c;
        if (it.failed())
            setstate(ios_base::badbit);

        return (*this);
    }

    inline ostream& ostream::write(const char* s, streamsize n)
    {
        if (n)
        {
            ostreambuf_iterator it(*this);

            for (; n; --n, ++it, ++s)
            {
                *it = *s;
                if (it.failed())
                {
                    setstate(ios_base::badbit);
                    break;
                }
            }
        }

        return (*this);
    }

    inline streampos ostream::tellp()
    {
        if (fail())
            return streampos(-1);

        return rdbuf()->pubseekoff(0, ios_base::cur, ios_base::out);
    }

    inline stream& ostream::seekp(streampos pos)
    {
        if (!fail())
        {
            if (rdbuf()->pubseekpos(pos, ios_base::out) == streampos(-1))
                setstate(ios_base::failbit);
        }

        return (*this);
    }

    inline ostream& ostream::seekp(streamoff off, ios_base::seekdir dir)
    {
        if (!fail())
            rdbuf()->pubseekoff(off, dir, ios_base::out);

        return (*this);
    }

    inline ostream& ostream::flush()
    {
        if (rdbuf())
        {
            if (rdbuf()->pubsync() == - 1)
                setstate(ios_base::badbit);
        }

        return (*this);
    }
}

#endif /* !STD_STREAM_HXX_ */
