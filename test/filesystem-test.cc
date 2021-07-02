// Formatting library for C++ - filesystem types formatting tests
//
// Copyright (c) 2012 - present, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#include "fmt/std.h"

#include "gtest-extra.h"  // EXPECT_THROW_MSG

#if __cplusplus >= 201703L

TEST(std_test, filesystem_path_empty) {
    std::filesystem::path path;
    EXPECT_EQ(fmt::format("{}", path), "");
}

TEST(std_test, filesystem_path_simple) {
    std::filesystem::path path{"/etc/passwd"};
    EXPECT_EQ(fmt::format("{}", path), "/etc/passwd");
}

#endif
