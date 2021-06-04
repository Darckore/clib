#include "clib/clib.hpp"

namespace clib
{
  clib_root::clib_root(int argc, char** argv) :
    m_parser{ argc, argv }
  {
  }

}
