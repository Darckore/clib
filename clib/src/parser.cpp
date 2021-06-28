#include "clib/parser.hpp"

namespace clib
{
  parser::parser(int argc, char** argv) noexcept :
    m_input{ argv, static_cast<raw_t::size_type>(argc) }
  {
  }
}