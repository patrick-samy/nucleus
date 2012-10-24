#ifndef PLATFORM_VGA_HH_
# define PLATFORM_VGA_HH_

# include <cstdint>
# include <drivers/video/video.hh>

namespace platform
{
    // Class for video graphics array driver
    class Vga : public driver::Video
    {
        // enumeration
        enum mode_e
        {
            MODE_TEXT_80x25,
            MODE_GRAPHICS
        };

        enum modifier_e
        {
            MODIFIER_ESCAPE     = 255,
            MODIFIER_CLEAR      = 1,
            MODIFIER_COLOR      = 2,
            MODIFIER_SETX       = 3,
            MODIFIER_SETY       = 4,
            MODIFIER_BLACK      = 0,
            MODIFIER_BLUE       = 1,
            MODIFIER_GREEN      = 2,
            MODIFIER_CYAN       = 3,
            MODIFIER_RED        = 4,
            MODIFIER_MAGENTA    = 5,
            MODIFIER_YELLOW     = 6,
            MODIFIER_WHITE      = 7,
            MODIFIER_BLINK      = (1 << 7),
            MODIFIER_LIGHT      = (1 << 3)
        };

        // types
        typedef struct
        {
            uint8_t ch;
            uint8_t fg:4;
            uint8_t bg:4;
        } buffer_char_t;
        
        // constants
        static constexpr buffer_char_t* buffer_text_80x25 = (buffer_char_t*)0xb8000;

        // methods
        public:
            // singleton accessor
            static Vga& instance();
            // inherited from video driver class
            
            // vga related methods
            void set_mode(mode_e m);
            void clear();
            // text buffer methods
            void set_modifier(modifier_e m);
            void set_cursor(unsigned int row, unsigned int col);
            void put(unsigned int row, unsigned int col, char c);

        private:
            // constructors
            Vga();
            Vga(const Vga&);
            // implementation related
            void put(unsigned int row, unsigned int col, buffer_char_t c);

        // attributes
        private:
            mode_e          mode_;
            modifier_e      modifier_;
    };
}

#endif /* !PLATFORM_VGA_HH_ */
