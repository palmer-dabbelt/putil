/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include "filesystem.h++"
#include <iostream>
#include <unistd.h>

int putil::filesystem::mkdir_p(const std::string& path, mode_t mode)
{
    return mkdirat_p(AT_FDCWD, path, mode);
}

int putil::filesystem::mkdirat_p(int dirfd, const std::string& path, mode_t m)
{
    for (size_t i = 1; i < path.length(); ++i) {
        if (path[i] != '/')
            continue;

        auto dirname = path.substr(0, i);
        auto out = mkdirat(dirfd, dirname.c_str(), m);
        if (out == -1 && errno != EEXIST)
            return out;
    }

    auto out = mkdirat(dirfd, path.c_str(), m);
    if (out == -1 && errno != EEXIST)
        return out;

    return 0;
}
