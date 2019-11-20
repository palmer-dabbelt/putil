/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/collection.h++>
#include <vector>

int func(int i)
{
    return i+1;
}

int main()
{
    std::vector<int> in{1, 2, 3};
    std::vector<int> out = putil::collection::map(in, &func);

    for (size_t i = 0; i < std::min(in.size(), out.size()); ++i)
        if (in[i]+1 != out[i])
            return 2;

    if (in.size() != out.size())
        return 3;

    return 0;
}
