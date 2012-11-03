#include <iostream>
#include <core/core.hh>
#include module(console)

namespace std
{
    std::ostream kout;
}

void main()
{
    // Initialize platform
    platform::Console console(25, 80);

    platform::Vga::instance().set_mode(platform::Vga::MODE_TEXT_80x25);
    platform::Vga::instance().set_modifier(platform::Vga::MODIFIER_WHITE);
    std::kout.set_streambuf(&console.get_streambuf());
    console.clear();

    // Call core entry point
    core::main();
}
