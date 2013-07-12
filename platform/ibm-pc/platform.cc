#include "core/core.hh"

class test
{
  public:
    int toto = 42;
    test();
    ~test();
};

test::test()
  : toto (33)
{
}

test::~test()
{
  toto = 0;
}


test o{};

extern "C" void main()
{
  o.toto += o.toto;
    // Initialize platform
    // platform::Console console(25, 80);

    // platform::Vga::instance().set_mode(platform::Vga::MODE_TEXT_80x25);
    // platform::Vga::instance().set_bg_modifier(platform::Vga::MODIFIER_BLACK);
    // platform::Vga::instance().set_fg_modifier(platform::Vga::MODIFIER_WHITE);
    // std::cout.rdbuf(&console.get_streambuf());
    // console.clear();

    // Call core entry point
    core::main();
}
