#include <iostream>
#include <core/core.hh>
#include module(console)

namespace std
{
    //std::ostream kout;
}

void main()
{
    // Initialize platform
    //platform::Console console(25, 80);
    
    //std::kout.set_streambuf(&console.get_streambuf());

    // Call core entry point
    core::main();
}
