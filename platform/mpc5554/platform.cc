#include <core/core.hh>

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
  core::main();
}
