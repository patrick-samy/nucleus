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
            // Inner class for console buffers
            class Buffer : public std::streambuf
            {
                // methods
                public:
                    // constructor
                    Buffer();
                    // destructor
                    virtual ~Buffer();
                    // initialize
                    void init(Console* c, std::streamsize size);
                    // getters
                    char* get_begin();
                    char* get_end();
                    // inherited from std::streambuf
                    virtual std::streamsize xsputn(const char* s, std::streamsize n);
                    virtual std::streambuf* setbuf(char* s, std::streamsize n);
                    virtual std::streampos seekoff(std::streamoff           offset,
                                                   std::ios_base::seekdir   direction);
                    virtual std::streampos seekpos(std::streampos sp);
                    virtual int sync();

                // attributes
                private:
                    Console*        console_;
                    std::streamsize size_;
                    // TODO: Fix this using the allocator when implemented
                    //       or template by the size.
                    char            output_buffer_[80 * 25];
            };

        // methods
        public:
            // constructor
            Console(unsigned int rows, unsigned int cols);
            // getters & setters
            std::streambuf& get_streambuf();
            // display
            void flush_streambuf();

        private:
            void put(char c);

        // attributes
        private:
            Buffer          streambuf_;
            unsigned int    width_;
            unsigned int    height_;
            unsigned int    row_;
            unsigned int    col_;
    };
}

#endif /* !PLATFORM_CONSOLE_HH_ */

