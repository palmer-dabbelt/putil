/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/filesystem/textfile.h++>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        abort();

    auto file = putil::filesystem::textfile(argv[1], 0770);

    auto lines = file.convert_lines<float>(
        12,
        0.0f,
        [](std::string line) { return std::stof(line); }
    );

    for (const auto& f: lines) {
        printf("%f\n", f);
    }

    return 0;
}
