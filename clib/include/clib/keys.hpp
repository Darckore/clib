#pragma once

namespace clib
{
  class key
  {
  public:
    enum class kind : uint8_t
    {
      cl_switch,    // -s
      cl_value,     // -v=something
      cl_opt_value, // -ov[=something]
      cl_action,    // can associate a function with this one
    };

    key() = delete;
    key(const key&) = delete;
    key& operator=(const key&) = delete;
    key(key&&) = default;
    key& operator=(key&&) = default;
  };
}