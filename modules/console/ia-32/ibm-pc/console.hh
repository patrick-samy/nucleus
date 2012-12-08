#ifndef PLATFORM_CONSOLE_HH_
# define PLATFORM_CONSOLE_HH_

# include <iostream>
# include <drivers/video/ibm-pc/vga.hh>

namespace platform 
{
    // Class for VGA consoles on IBM-PC
    class Console
    {
        // enumerations
        public:
            enum e_message_type
            {
                INFO,
                WARNING,
                ERROR
            };

            enum e_verbose_level
            {
                // fatal errors and messages
                VERBOSE_LEVEL_NORMAL,
                // warnings
                VERBOSE_LEVEL_INFO,
                // all
                VERBOSE_LEVEL_DEBUG,
            };

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
                    virtual std::streamsize xsputn(const char*      s,
                                                   std::streamsize  n);
                    virtual std::streambuf* setbuf(char* s, std::streamsize n);
                    virtual std::streampos seekoff(std::streamoff           o,
                                                   std::ios_base::seekdir   d);
                    virtual std::streampos seekpos(std::streampos sp);
                    virtual int sync();

                // attributes
                private:
                    Console*        console_;
                    // TODO: Fix this using the allocator when implemented
                    //       or template by the size.
                    char            output_buffer_[80 * 25];
                    std::streamsize size_;
            };

        // methods
        public:
            // constructor
            Console(unsigned int rows, unsigned int cols);
            // getters & setters
            std::streambuf& get_streambuf();
            void set_verbose_level(e_verbose_level l);
            // console management
            void clear();
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
            e_verbose_level verbose_level_; 
    };

    // ostream operator overload for console modifier
    std::ostream& operator<<(std::ostream& out, Console::e_message_type l);
}

#endif /* !PLATFORM_CONSOLE_HH_ */

