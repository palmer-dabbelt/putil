/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/filesystem.h++>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("%s needs 2 args\n", argv[0]);
        return 1;
    }

    auto out = putil::filesystem::mkdir_p(argv[1], 0777);
    if (out != 0)
        perror("unable to mkdir_p");
    return out;
}
