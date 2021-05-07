#pragma once

namespace clib
{
  class parser
  {
  public:
    parser() = delete;
    parser(const parser&) = delete;
    parser& operator=(const parser&) = delete;
    parser(parser&&) = delete;
    parser& operator=(parser&&) = delete;

    parser(int argc, char** argv);

  private:

  };
}