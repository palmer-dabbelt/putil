/* Copyright (C) 2017 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include "from_string.h++"
using namespace putil::clargs;

namespace putil {
    namespace clargs {
        template<>
        std::string from_string<std::string>(const std::string& str)
        { return str; }
    }
}
