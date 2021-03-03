#pragma once

namespace clib
{
  template <typename F>
  class key
  {
  public:
    key() = default;
    key(const key&) = delete;
    key(key&&) = default;
    key& operator=(const key&) = delete;
    key& operator=(key&&) = default;
    ~key() = default;

  public:
    using function_type = typename F;
    using size_type = size_t;

  public:
    constexpr key(size_type argCount, function_type func) :
      m_func{ std::move(func) },
      m_argCount{ argCount }
    {}

    template <typename... Args>
    constexpr auto operator()(Args&& ...args) const
    {
      return m_func( std::forward<Args>(args)... );
    }
    constexpr auto arg_count() const noexcept
    {
      return m_argCount;
    }

  private:
    function_type m_func{};
    size_type m_argCount{};
  };

  class arg_set
  {
  public:
    arg_set() = default;
    arg_set(const arg_set&) = delete;
    arg_set(arg_set&&) = default;
    arg_set& operator=(const arg_set&) = delete;
    arg_set& operator=(arg_set&&) = default;
    ~arg_set() = default;

  public:

  private:

  };

  class parser
  {
  public:
    parser() = default;
    parser(const parser&) = default;
    parser(parser&&) = default;
    parser& operator=(const parser&) = default;
    parser& operator=(parser&&) = default;
    ~parser() = default;

  public:
    parser(int /*argc*/, char** /*argv*/) {}

  private:

  };
}