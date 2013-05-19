#include <cstdio>
#include <modules/console/ia-32/ibm-pc/console.hh>

namespace platform
{
    // Console
    Console::Console(unsigned int rows, unsigned int cols)
      : width_(cols),
        height_(rows),
        row_(0),
        col_(0)
    {
        streambuf_.init(this, cols * rows);
    }

    std::streambuf& Console::get_streambuf()
    {
        return streambuf_;
    }

    void Console::set_verbose_level(e_verbose_level l)
    {
        verbose_level_ = l;
    }

    void Console::flush_streambuf()
    {
        char* it = streambuf_.get_begin();
        char* end = streambuf_.get_end();

        for (; it != end; ++it)
            this->put(*it);
    }

    void Console::clear()
    {
        Vga::instance().clear();
    }

    void Console::put(char c)
    {
        if (c == '\n')
        {
            ++row_;
            col_ = 0;
            return;
        }
        else
            Vga::instance().put(row_, col_++, c);

        if (col_ >= width_)
        {
            col_ = 0;
            if (++row_ >= height_)
                row_ = 0;
        }
    }

    // Console::Buffer
    Console::Buffer::Buffer()
      : console_(nullptr),
        size_(0)
    {
    }

    Console::Buffer::~Buffer()
    {
    }

    void Console::Buffer::init(Console* c, std::streamsize size)
    {
        console_ = c;
        size_ = size;

        this->setp(output_buffer_, output_buffer_ + size);
    }

    char* Console::Buffer::get_begin()
    {
        return this->pbase();
    }

    char* Console::Buffer::get_end()
    {
        return this->pptr();
    }

    std::streamsize Console::Buffer::xsputn(const char* s, std::streamsize n)
    {
        std::streamsize i;

        for (i = 0;  i < n; ++i)
        {
            if (this->sputc(s[i]) == EOF)
                break;
        }

        return i;
    }

    std::streambuf* Console::Buffer::setbuf(char* s, std::streamsize n)
    {
        // TODO: Fix this when the buffer is properly allocated
        //output_buffer_ = s;
        size_ = n;

        this->setp(s, s + n);

        return this;
    }

    std::streampos Console::Buffer::seekoff(std::streamoff          offset,
                                            std::ios_base::seekdir  direction)
    {
        std::streampos pos(std::streamoff(-1));

        switch (direction)
        {
            case std::ios_base::beg:
                pos = 0;
                break;

            case std::ios_base::cur:
                pos = this->pptr() - this->pbase();
                break;

            case std::ios_base::end:
                pos = this->epptr() - this->pbase();
                break;

            default:
                break;
        }

        return (this->seekpos(pos + offset));
    }

    std::streampos Console::Buffer::seekpos(std::streampos pos)
    {
        if ((pos < 0) || (pos >= this->epptr() - this->pbase()))
            return -1;

        // output_current_position_ = output_begin_position_ + pos;

        return pos;
    }

    int Console::Buffer::sync()
    {
        console_->flush_streambuf();
        this->setp(this->pbase(), this->epptr());

        return 0;
    }

    // ostream operator overload for console modifier
    std::ostream& operator<<(std::ostream& out, Console::e_message_type m)
    {
        switch (m)
        {
            case Console::INFO:
                Vga::instance().set_fg_modifier(Vga::MODIFIER_WHITE);
                break;
            case Console::WARNING:
                Vga::instance().set_fg_modifier(Vga::MODIFIER_YELLOW);
                break;
            case Console::ERROR:
                Vga::instance().set_fg_modifier(Vga::MODIFIER_RED);
                break;
        }

        return out;
    }
}
