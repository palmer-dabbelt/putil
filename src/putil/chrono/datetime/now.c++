/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/chrono/datetime.h++>
#include <iostream>

int main()
{
    std::cout << putil::chrono::datetime::now().unix_seconds() << "\n";
    return 0;
}
