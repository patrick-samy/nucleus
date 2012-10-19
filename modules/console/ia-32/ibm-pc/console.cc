#include <modules/console/ia-32/ibm-pc/console.hh>

namespace platform 
{
    Console::Console(unsigned int rows, unsigned int cols)
      : streambuf_(rows * cols),
        width_(cols),
        height_(rows),
        row_(0),
        col_(0)
    {
    }

    inline streambuf& get_streambuf()
    {
        return streambuf_;
    }

    void Console::flush()
    {
    }

    void Console::put(char c)
    {
        platform::Vga::instance().put(row_, col_++, c);
        
        if (col_ >= width)
        {
            col_ = 0;
            if (++row_ >= height)
                row_ = 0;
        }
    }
}

