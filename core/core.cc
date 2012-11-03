#include <iostream>
#include <core/core.hh>
#include module(console)

#define ever (;;)

namespace core
{
    void main()
    {
        std::kout << "[atom] hello world " << 2 << '.' << 0 << " !"; 

        for ever;
    }
}
