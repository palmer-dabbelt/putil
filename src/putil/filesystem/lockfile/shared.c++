/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/filesystem/lockfile.h++>
#include <stdlib.h>

int main(int argc, const char **argv)
{
    if (argc != 2)
        abort();

    auto lock = putil::filesystem::lockfile::rdlock(argv[1]);
}
