/* Copyright (C) 2018 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <libputil/clargs.h++>

int main(int argc, char **argv)
{
    try {
        auto parser = putil::clargs::parser(argc, argv);
        auto input = parser.required_named_arg<std::string>({"-i", "--input"}, "input file name");
        parser.parse();

        std::cout << std::to_string(input) << "\n";
    } catch (const putil::clargs::exception &e) {
        std::cerr << e.message() << std::endl;
        abort();
    }

    return 0;
}
