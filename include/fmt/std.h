// Formatting library for C++ - filesystem support
//
// Copyright (c) 2012 - present, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#ifndef FMT_STD_H_
#define FMT_STD_H_

//#include <algorithm>
//#include <chrono>
//#include <ctime>
//#include <locale>
//#include <sstream>
#if __cplusplus >= 201703L
#include <filesystem>
#endif

#include "format.h"

FMT_BEGIN_NAMESPACE
FMT_MODULE_EXPORT_BEGIN

// filesystem

#if __cplusplus >= 201703L
struct formatter<std::filesystem::path, char> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        // No format options are currently supported.
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

  template <typename FormatContext>
      auto format(const std::filesystem::path &path,
              FormatContext& ctx) -> decltype(ctx.out()) {

#if defined(WIN32)
      // This will copy, but we need a narrow character string
      return format_to(ctx.out(), "{}", path.string());
#else // WIN32
      // Using std::filesystem::path::native() means that no copies
      // are required.
      return format_to(ctx.out(), "{}", path.native());
#endif // !WIN32
  }
};
#endif // __cplusplus >= 201703L

FMT_MODULE_EXPORT_END
FMT_END_NAMESPACE

#endif  // FMT_STD_H_
