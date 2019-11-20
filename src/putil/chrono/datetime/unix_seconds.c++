/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/chrono/datetime.h++>
#include <iostream>

int main(int argc, const char **argv)
{
    if (argc != 2)
        return 1;

    std::cout << putil::chrono::datetime(argv[1]).unix_seconds() << "\n";
    return 0;
}
