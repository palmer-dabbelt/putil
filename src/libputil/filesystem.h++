/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PUTIL__FILESYSTEM_H
#define PUTIL__FILESYSTEM_H

#include <fcntl.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>

namespace putil {
    namespace filesystem {
        /* Recursively creates a directory tree, much the same as
         * 'mkdir -p'. */
        int mkdir_p(const std::string& path, mode_t mode);
        int mkdirat_p(int dirfd, const std::string& path, mode_t mode);
    }
}

#include "filesystem/lockfile.h++"
#include "filesystem/textfile.h++"

#endif
