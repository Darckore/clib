#pragma once

namespace clib
{
  class key_descr
  {
  public:


  public:
    using string_t = std::string;

  public:
    CLASS_SPECIALS_NODEFAULT_NOCOPY(key_descr);

    key_descr(string_t name, string_t help) noexcept :
      m_name{ std::move(name) },
      m_help{ std::move(help) }
    {}

  private:
    string_t m_help;
    string_t m_name;
  };
}