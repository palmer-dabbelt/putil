/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#include "from_string.h++"
using namespace putil::clargs;

namespace putil {
    namespace clargs {
        template<>
        std::string from_string<std::string>(const std::string& str)
        { return str; }
    }
}
