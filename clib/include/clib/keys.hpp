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

    CLIB_SPECIALS_NODEFAULT_NOCOPY(key);

  private:
    friend class clib_root;
    key(int) {} //placeholder
  };
}