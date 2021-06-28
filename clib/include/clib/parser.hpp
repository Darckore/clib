#pragma once
#include "clib/keys.hpp"

namespace clib
{
  class lookup_table
  {
  public:
    using string_t = std::string_view;
    using key_map_t = std::unordered_map<string_t, const key_descr*>;
    using keyring_t = std::forward_list<key_descr>;

  public:
    CLASS_SPECIALS_NONE_CUSTOM(lookup_table);
   
  private:
    friend class parser;
    lookup_table() = default;

  public:


  private:
    keyring_t m_keyring;
    key_map_t m_long_names;
    key_map_t m_short_names;
  };


  class parser
  {
  public:
    using string_t = key_descr::string_t;
    using raw_t = std::span<char*>;

  public:
    CLASS_SPECIALS_NONE(parser);

    parser(int argc, char** argv) noexcept;

  public:

  private:
    lookup_table m_keys;
    raw_t m_input;
  };
}