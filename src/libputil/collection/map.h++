/* Copyright (C) 2017 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PUTIL__COLLECTION_COLLECTION_HXX
#define PUTIL__COLLECTION_COLLECTION_HXX

#include <vector>
#include <algorithm>
#include <functional>

namespace putil {
    namespace collection {
        /* A functional map. */
        template <class V, typename F>
        static inline auto map(const V& v, const F f)
            -> std::vector<decltype(f(std::declval<typename V::value_type>()))>
        {
            std::vector<decltype(f(std::declval<typename V::value_type>()))> o;
            std::transform(v.begin(), v.end(), std::back_inserter(o), f);
            return o;
        }
    }
}

#endif
