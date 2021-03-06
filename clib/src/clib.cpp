#include "clib/clib.hpp"

namespace clib
{
  clib_root::clib_root(int argc, char** argv) :
    m_parser{ argc, argv }
  {
  }

  bool clib_root::has_key(string_type name) const noexcept
  {
    return static_cast<bool>(lookup(name));
  }
  clib_root::key_type* clib_root::lookup(string_type name) noexcept
  {
    return utils::mutate(std::as_const(*this).lookup(name));
  }
  const clib_root::key_type* clib_root::lookup(string_type name) const noexcept
  {
    auto found = m_keys.find(name);
    return found != m_keys.end()
      ? &found->second
      : nullptr;
  }
}
