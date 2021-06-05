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

// utils submodule
#include "../utils/utils.hpp"