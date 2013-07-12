#include <core/core.hh>

class test
{
  public:
    int toto = 42;
    test();
};

test::test()
  : toto (33)
{
}

test o {};

extern "C" void main()
{
  o.toto *= 2;
  core::main();
}
