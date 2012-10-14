#ifndef STD_STREAMBUF_HXX_
# define STD_STREAMBUF_HXX_

namespace std
{
    // streampos
    inline streampos::operator streamoff() const
    {
        return offset_;
    }

    inline streampos& streampos::operator+=(streamoff offset)
    {
        offset_ += offset;

        return (*this);
    }

    inline streampos  streampos::operator+(streamoff offset) const
    {
        streampos t(*this);

        t += offset;

        return t;
    }
    
    inline streampos&  streampos::operator-=(streamoff offset)
    {
        offset_ -= offset;

        return (*this);
    }

    inline streampos  streampos::operator-(streamoff offset) const
    {
        streampos t(*this);

        t -= offset;

        return t;
    }

    // streambuf
    inline streambuf* streambuf::pubsetbuf(char* s, streamsize n)
    {
        return setbuf(s, n);
    }

    inline streampos streambuf::pubseekoff(streamoff            offset,
                                           ios_base::seekdir    direction,
                                           ios_base::openmode   mode)
    {
       return seekoff(offset, direction, mode); 
    }

    inline streampos streambuf::pubseekpos(streampos            seek_position,
                                           ios_base::openmode   mode)
    {
        return seekpos(seek_position, mode);
    }

    inline int streambuf::pubsync()
    {
        return sync();
    }

    inline streamsize streambuf::in_avail()
    {
        if (input_current_position_ < input_end_position_)
            return static_cast<streamsize>
                (input_end_position_ - input_current_position_);
        
        return showmanyc();
    }

    inline int streambuf::snextc()
    {
        if (sbumpc() == EOF)
            return EOF;
        
        return sgetc();
    }

    inline int streambuf::sbumpc()
    {
        if (input_current_position_ == input_end_position_)
            return uflow();

        return int(*input_current_position_++); 
    }

    inline int streambuf::sgetc()
    {
        if (input_current_position_ == input_end_position_)
            return underflow();
        
        return int(*input_current_position_);
    }

    inline streamsize streambuf::sgetn(char* s, streamsize n)
    {
        return xsgetn(s, n);
    }

    inline int streambuf::sputbackc(char c)
    {
        if ((input_begin_position_ == input_current_position_) ||
            (c != input_current_position_[-1]))
            return pbackfail(int(c));

        return int(*--input_current_position_);
    }

    inline int streambuf::sungetc()
    {
        if (input_begin_position_ == input_current_position_)
            return pbackfail();

        return int(*--input_current_position_);
    }

    inline int streambuf::sputc(char c)
    {
        if (output_current_position_ == output_end_position_)
            return overflow(int(c));

        *output_current_position_++ = c;

        return int(c);
    }

    inline streamsize streambuf::sputn(const char* s, streamsize n)
    {
        return xsputn(s, n);
    }

    inline char* streambuf::eback() const
    {
        return input_begin_position_;
    }

    inline char* streambuf::gptr() const
    {
        return input_current_position_;
    }

    inline char* streambuf::egptr() const
    {
        return input_end_position_;
    }

    inline void streambuf::gbump(int n)
    {
        input_current_position_ += n;
    }

    inline void streambuf::setg(char* gbeg, char* gnext, char* gend)
    {
        input_begin_position_ = gbeg;
        input_current_position_ = gnext;
        input_end_position_ = gend;
    }

    inline streamsize streambuf::showmanyc()
    {
        return 0;
    }

    inline streamsize streambuf::xsgetn(char* s, streamsize n)
    {
        int         c;
        streamsize  i = 0;

        for (; i < n; ++i, ++s)
        {
            if (input_current_position_ < input_end_position_)
                *s = *input_current_position_++;
            else if ((c = uflow()) != EOF)
                *s = char(c);
            else
                break;
        }

        return i;
    }

    inline int streambuf::underflow()
    {
        return EOF;
    }

    inline int streambuf::uflow()
    {
        if (underflow() == EOF)
            return EOF;

        return int(*input_current_position_++);
    }

    inline int streambuf::pbackfail(int c)
    {
        return EOF;
    }

    inline char* streambuf::pbase()
    {
        return input_begin_position_;
    }

    inline char* streambuf::pptr()
    {
        return input_current_position_;
    }

    inline char* streambuf::epptr()
    {
        return input_end_position_;
    }

    inline void streambuf::pbump(int n)
    {
        output_current_position_ += n;
    }

    inline void streambuf::setp(char* pbeg, char* pend)
    {
        output_begin_position_ = pbeg;
        output_current_position_ = pbeg;
        output_end_position_ = pend;
    }

    inline streamsize streambuf::xsputn(const char* s, streamsize n)
    {
        streamsize i = 0;
        
        for (; i < n; ++i, ++s)
        {
            if (output_current_position_ < output_end_position_)
                *output_current_position_++ = *s;
            else if (overflow(*s) == EOF)
                break;
        }

        return i;
    }

    inline int streambuf::overflow(int c)
    {
        return EOF;
    }

    inline streambuf* streambuf::setbuf(char*, streamsize)
    {
        return this;
    }

    inline streampos streambuf::seekoff(streamoff,
                                        ios_base::seekdir,
                                        ios_base::openmode)
    {
        return streampos(streamoff(-1));
    }

    inline streampos streambuf::seekpos(streampos, ios_base::openmode)
    {
        return streampos(streamoff(-1));
    }

    inline int streambuf::sync()
    {
        return 0;
    }
}

#endif /* !STD_STREAMBUF_HXX_ */
