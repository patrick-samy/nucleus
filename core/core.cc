#include <iostream>
#include <core/core.hh>
#include module(console)

#define ever (;;)

namespace core
{
    void main()
    {
        // hello
        std::kout << platform::Console::INFO << "[nucleus] hello world " << 2 << '.' << 0 << " !" << std::endl;

        std::kout << platform::Console::WARNING << "[device] poll failed, retrying in 10 sec..." << std::endl;
        std::kout << platform::Console::ERROR << "[cpu] interrupt #3 not handled." << std::endl;
        
        // going to sleep
        std::kout << platform::Console::INFO << "[nucleus] going to sleep...";
        for ever;
    }
}
