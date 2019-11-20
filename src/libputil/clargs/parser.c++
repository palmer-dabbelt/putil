/* Copyright (C) 2017 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */


#include "parser.h++"
#include <libputil/size_t.h++>
using namespace putil::clargs;

std::list<std::string> parser::argv_to_list(int argc, char **argv)
{
    auto out = std::list<std::string>();
    for (int i = 0; i < argc; ++i)
        out.push_back(argv[i]);
    return out;
}

void parser::parse(void)
{
    auto begin = _argv.begin();
    auto end = _argv.end();
    while (begin != end) {
        auto munch = 0_z;
        std::decay<decltype(_args.front())>::type munch_arg = nullptr;
        for (auto arg: _args) {
            auto mm = arg->munch(putil::make_forward_iterator(begin, end));
            if (mm != 0 && munch != 0)
                throw duplicate_argument(*begin, arg->debug(), munch_arg->debug());

            if (mm != 0) {
                munch = mm;
                munch_arg = arg;
            }
        }

        if (munch == 0) {
            throw invalid_argument(*begin);
        }

        for (auto i = 1_z; i <= munch; ++i) {
            begin++;
            if (i != munch && begin == end) {
                throw no_index_for_argument();
            }
        }
    }

    for (const auto& arg: _args)
        if (arg->validate() == false)
            throw missing_argument(arg->debug());
}
