#pragma once

namespace clib
{
  class parser
  {
  public:
    CLIB_SPECIALS_NONE(parser);

  private:
    friend class clib_root;
    parser(int argc, char** argv);

  private:

  };
}