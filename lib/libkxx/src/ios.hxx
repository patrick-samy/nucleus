#ifndef STD_IOS_HXX_
# define STD_IOS_HXX_

namespace std
{
    inline void ios::init(void* buffer)
    {
        ios_base::init(buffer);
        state_ = buffer_ ? ios_base::goodbit : ios_base::badbit;
        fill_ = ' ';
    }

    inline bool ios::good() const
    {
        return (state_ == 0);
    }

    inline bool ios::eof() const
    {
        return (state_ & ios::eofbit);
    }

    inline bool ios::fail() const
    {
        return (state_ & ios::failbit);
    }

    inline bool ios::bad() const
    {
        return (state_ & ios::badbit);
    }

    inline bool ios::operator!() const
    {
        return fail();
    }

    inline ios::operator void*() const
    {
        if (fail() || bad())
            return nullptr;

        return buffer_;
    }

    inline ios_base::iostate ios::rdstate() const
    {
        return state_;
    }

    inline void ios::setstate(iostate state)
    {
        state_ = state;
    }

    inline void ios::clear(iostate state)
    {
        if (buffer_)
            state_ = state;
        else
            state_ = state | badbit;
    }

    inline ios& ios::copyfmt(const ios& rhs)
    {
        fill_ = rhs.fill_;
    }

    inline char ios::fill() const
    {
        return fill_;
    }

    inline char ios::fill(char ch)
    {
        char old_ch = fill_;

        fill_ = ch;

        return old_ch;
    }

    inline streambuf* ios::rdbuf() const
    {
        return static_cast<streambuf*>(buffer_);
    }

    inline streambuf* ios::rdbuf(streambuf* sb)
    {
        streambuf* old_buffer = rdbuf();

        buffer_ = sb;

        return old_buffer;
    }
}

#endif /* !STD_IOS_HXX_ */
