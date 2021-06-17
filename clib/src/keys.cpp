#include "clib/keys.hpp"

namespace clib
{
  key::key(kind k) :
    m_kind{ k }
  {
  }

  key::kind key::what_is() const noexcept
  {
    return m_kind;
  }
}