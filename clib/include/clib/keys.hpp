#pragma once

namespace clib
{
  class key
  {
  public:
    using string_type = std::string_view;

    enum class kind : uint8_t
    {
      cl_switch,    // -s
      cl_value,     // -v=something
      cl_opt_value, // -ov[=something]
      cl_action,    // can associate a function with this one
    };
    using enum kind;

    CLASS_SPECIALS_NODEFAULT(key);

  private:
    friend class clib_root;
    explicit key(kind k);

  public:
    kind what_is() const noexcept;

  private:
    kind m_kind;
  };
}