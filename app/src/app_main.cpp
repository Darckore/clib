#include "clib/clib.hpp"

int main(int argc, char** argv)
{
  clib::key k{ 1, [](int a, int b) { return a + b; } };
  const auto res = k.arg_count();

  clib::parser{ argc, argv };
  return 0;
}