#pragma once
#include "clib/keys.hpp"
#include "clib/parser.hpp"

namespace clib
{
  class clib_root
  {
  private:
    using key_type = key;
    using string_type = key::string_type;
    using key_store = std::unordered_map<string_type, key_type>;

  public:
    CLASS_SPECIALS_NONE(clib_root);

    clib_root(int argc, char** argv);

  public:
    bool has_key(string_type name) const noexcept;
    
    template <key_type::kind K>
    bool has_key(string_type name) const noexcept
    {
      auto k = lookup(name);
      return k && k->what_is() == K;
    }

  private:
    key_type* lookup(string_type name) noexcept;
    const key_type* lookup(string_type name) const noexcept;

  private:
    key_store m_keys;
    parser m_parser;
  };
}