#pragma once
#include "clib/keys.hpp"
#include "clib/parser.hpp"

namespace clib
{
  class parser;

  class clib_root
  {
  public:
    CLIB_SPECIALS_NONE(clib_root);

    clib_root(int argc, char** argv);

  public:


  private:
    using key_type = key;
    using key_store = std::unordered_map<key_type::string_type, key_type>;

  private:
    key_store m_keys;
    parser m_parser;
  };
}