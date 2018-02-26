/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__CLARGS__FROM_STRING_HXX
#define PCAD__CLARGS__FROM_STRING_HXX

#include <string>

namespace putil {
    namespace clargs {
        /* I need to convert various arguments from strings to other types as
         * part of command-line argument parsing.  I handle that via
         * specializations of */
        template <typename T> T from_string(const std::string& str);
    }
}

#endif
