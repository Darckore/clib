#pragma once

// std headers we'll most likely be using
#include <cstddef>
#include <type_traits>
#include <utility>

#include <iostream>
#include <fstream>

#include <string>
#include <string_view>

#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <filesystem>
#include <memory>
#include <stdexcept>

#include <algorithm>
#include <concepts>

// just because it is often needed everywhere
using namespace std::literals;

// third-party headers
#include "fmt/core.h"
#include "fmt/color.h"
#include "fmt/compile.h"

// macros
#define CLIB_SPECIALS_ALL(clName)\
  clName() = default;\
  clName(const clName&) = default;\
  clName& operator=(const clName&) = default;\
  clName(clName&&) = default;\
  clName& operator=(clName&&) = default;\
  ~clName() = default

#define CLIB_SPECIALS_NOCOPY(clName)\
  clName() = default;\
  clName(const clName&) = delete;\
  clName& operator=(const clName&) = delete;\
  clName(clName&&) = default;\
  clName& operator=(clName&&) = default;\
  ~clName() = default

#define CLIB_SPECIALS_NODEFAULT(clName)\
  clName() = delete;\
  clName(const clName&) = default;\
  clName& operator=(const clName&) = default;\
  clName(clName&&) = default;\
  clName& operator=(clName&&) = default;\
  ~clName() = default

#define CLIB_SPECIALS_NODEFAULT_NOCOPY(clName)\
  clName() = delete;\
  clName(const clName&) = delete;\
  clName& operator=(const clName&) = delete;\
  clName(clName&&) = default;\
  clName& operator=(clName&&) = default;\
  ~clName() = default

#define CLIB_SPECIALS_NONE(clName)\
  clName() = delete;\
  clName(const clName&) = delete;\
  clName& operator=(const clName&) = delete;\
  clName(clName&&) = delete;\
  clName& operator=(clName&&) = delete;\
  ~clName() = default