#ifndef PLATFORM_CONSOLE_HH_
# define PLATFORM_CONSOLE_HH_

# include <streambuf>
# include <drivers/video/ibm-pc/vga.hh>

namespace platform 
{
    // Class for VGA consoles on IBM PC
    class Console
    {
        // types
        private:
            class Buffer;

            // methods
        public:
            // constructor
            Console(unsigned int rows, unsigned int cols);
            // getters & setters
            std::streambuf& get_streambuf();
            // display
            void flush();

        private:
            void put(char c);

            // attributes
        private:
            Buffer&          streambuf_;
            unsigned int    width_;
            unsigned int    height_;
            unsigned int    row_;
            unsigned int    col_;
    };

    // Inner class for console buffers
    class Console::Buffer : public std::streambuf
    {
        // methods
        public:

    };
}

#endif /* !PLATFORM_CONSOLE_HH_ */

