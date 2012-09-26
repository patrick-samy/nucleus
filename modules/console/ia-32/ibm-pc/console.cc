#include "modules/console/ia-32/ibm-pc/console.hh"

namespace platform 
{
  static const int modifiers[Console::MODIFIER_NB] =
  {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    (1 << 3),
  };

  Console& Console::instance()
  {
    static Console instance;

    return instance;
  }

  Console::Console()
  {
    this->clear();
  }

  void Console::operator<<(const char* str)
  {
    module::Console::operator<<(str);
  }

  void Console::operator<<(console_modifiers_e mod)
  {
    modifier_ |= modifiers[(unsigned int) mod];
  }

  void Console::print_char(char c)
  {
    static console_char_t 	*buffer = (console_char_t *) 0xb8000;
    static unsigned int 	row_nb = 25;
    static unsigned int 	col_nb = 80;

    if (c == '\n')
    {
      col_ = 0;
      ++row_;

      return;
    }

    buffer[row_ * row_nb + col_].ch = c;
    buffer[row_ * row_nb + col_].fg = modifier_;

    if (++col_ >= col_nb)
    {
      ++row_;
      col_ = 0;
      row_ = (row_ >= row_nb) ? 0 : row_ + 1;
    }
  }

  void Console::clear()
  {
    static console_char_t 	*buffer = (console_char_t *) 0xb8000;
    static unsigned int 	row_nb = 25;
    static unsigned int 	col_nb = 80;

    for (unsigned int i = 0; i < row_nb; ++i)
    {
      for (unsigned int j = 0; j < col_nb; ++j)
      {
        buffer[i * row_nb + j].ch = 0;
      }
    }
  }
}

