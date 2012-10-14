#ifndef STD_STREAM_HXX_
# define STD_STREAM_HXX_

namespace std
{
    // ostream
    inline ostream& ostream::operator<<(streambuf* sb)
    {
        sentry s(*this);

        if (s)
        {
            if (sb)
            {
                ostreambuf_iterator it(*this);
                long                c = 0;

                for (; sb->sgetc() != EOF; ++it, ++c)
                {
                    *it = sb->sbumpc();
                    if (it.failed())
                        break;
                }

                if (c == 0)
                    setstate(ios_base::failbit);
            }
            else
                setstate(ios_base::badbit);
        }

        return (*this);
    }

    inline ostream& ostream::operator<<(ostream& (*pf)(ostream&))
    {
        return (pf(*this));
    }

    inline ostream& ostream::operator<<(ios& (*pf)(ios&))
    {
        pf(*this);

        return (*this);
    }

    inline ostream& ostream::operator<<(ios_base& (*pf)(ios_base&))
    {
        pf(*this);

        return (*this);
    }

    inline ostream& ostream::operator<<(bool val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(short val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), static_cast<long>(val))
                    .failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(unsigned short val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), static_cast<unsigned long>(val))
                    .failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(int val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), static_cast<long>(val)).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(unsigned int val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), static_cast<unsigned long>(val))
                    .failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(long val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(unsigned long val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(float val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), static_cast<double>(val))
                    .failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(double val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return (*this);
    }

    inline ostream& ostream::operator<<(long double val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }

        return (*this);
    }

    inline ostream& ostream::operator<<(const void* val)
    {
        sentry s(*this);

        if (s)
        {
            ostreambuf_iterator it(*this);
            num_put             p;

            if (p.put(it, *this, this->fill(), val).failed())
                this->setstate(ios_base::badbit | ios_base::failbit);
        }

        return (*this);
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

    inline ostream& ostream::seekp(streampos pos)
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

    // ostream::sentry
    inline ostream::sentry::operator bool() const
    {
        return ok_;
    }

    // global functions for ostream
    inline ostream& operator<<(ostream& out, char c)
    {
        ostream::sentry s(out);

        if (s)
        {
            ostreambuf_iterator it(out);
            
            *it = c;
            if (it.failed())
                out.setstate(ios_base::badbit | ios_base::failbit);
        }
        
        return out;
    }

    inline ostream& operator<<(ostream& out, signed char c)
    {
        ostream::sentry s(out);

        if (s)
        {
            ostreambuf_iterator it(out);

            *it = static_cast<char>(c);
            if (it.failed())
                out.setstate(ios_base::badbit | ios_base::failbit);
        }

        return out;
    }

    inline ostream& operator<<(ostream& out, unsigned char c)
    {
        ostream::sentry s(out);

        if (s)
        {
            ostreambuf_iterator it(out);
            
            *it = static_cast<char>(c);
            if (it.failed())
                out.setstate(ios_base::badbit | ios_base::failbit);
        }

        return out;
    }

    inline ostream& operator<<(ostream& out, const char* str)
    {
        ostream::sentry s(out);

        if (s)
        {
            ostreambuf_iterator it(out);

            while (*str != '\0')
            {
                *it++ = static_cast<char>(*str);

                if (it.failed())
                {
                    out.setstate(ios_base::badbit | ios_base::failbit);
                    break;
                }
            }
        }

        return out;
    }

    inline ostream& operator<<(ostream& out, const signed char* str)
    {
        ostream::sentry s(out);

        if (s)
            out << (const char*)str;

        return out;
    }

    inline ostream& operator<<(ostream& out, const unsigned char* str)
    {
        ostream::sentry s(out);

        if (s)
            out << (const char*)str;

        return out;
    }
    
    // ostreambuf_iterator
    inline ostreambuf_iterator& ostreambuf_iterator::operator=(char c)
    {
        if (!failed())
            last_ = buffer_->sputc(c);
        
        if (last_ == EOF)
            buffer_ = 0;

        return (*this);
    }

    inline ostreambuf_iterator& ostreambuf_iterator::operator*()
    {
        return (*this);
    }

    inline ostreambuf_iterator& ostreambuf_iterator::operator++()
    {
        return (*this);
    }
    
    inline ostreambuf_iterator& ostreambuf_iterator::operator++(int)
    {
        return (*this);
    }

    // num_put
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                           ios_base&            str,
                                           char                 fill,
                                           bool                 val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                           ios_base&            str,
                                           char                 fill,
                                           long                 val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                           ios_base&            str,
                                           char                 fill,
                                           unsigned long        val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                            ios_base&           str,
                                            char                fill,
                                            double              val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                           ios_base&            str,
                                           char                 fill,
                                           long double          val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::put(ostreambuf_iterator out,
                                           ios_base&            str,
                                           char                 fill,
                                           const void*          val) const
    {
        return do_put(out, str, fill, val);
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               bool                 val) const
    {
        long        length = val ? sizeof(num_put::true_string) : sizeof(num_put::false_string);
        const char* boolean_string = val ? num_put::true_string : num_put::false_string;
        
        if ((str.flags() & ios_base::boolalpha) == 0)
            return do_put(out, str, fill, (unsigned long)val);

        for (long i = 0; i < length - 1; ++i, ++out)
            *out = boolean_string[i];

        return out;
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               long                 val) const
    {
        if (val < 0)
            *out++ = '-';
        else if (str.flags() & ios_base::showpos)
            *out++ = '+';

        return do_put(out, str, fill, -val);
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               unsigned long        val) const
    {
        // TODO: Better than this ?
        unsigned long copy = val;
        unsigned long size = 1;

        if (str.flags() & ios_base::showbase)
            *out++ = '#';

        if ((str.flags() & ios_base::basefield) == ios_base::oct)
            *out++ = 'o';
        else if ((str.flags() & ios_base::basefield) == ios_base::hex)
        {
            if (str.flags() & ios_base::uppercase)
                *out++ = 'X';
            else
                *out++ = 'x';
        }

        while (val /= 10);
            size *= 10;

        do *out++ = copy / size;
        while ((copy %= size) && (size /= 10));

        return out;
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               double               val) const
    {
        // FIXME
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               long double          val) const
    {
        // FIXME
    }
    
    inline ostreambuf_iterator num_put::do_put(ostreambuf_iterator  out,
                                               ios_base&            str,
                                               char                 fill,
                                               const void*          val) const
    {
        // FIXME
    }
}

#endif /* !STD_STREAM_HXX_ */
