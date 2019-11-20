/* Copyright (C) 2017 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PCAD__UTIL__COLLECTION__LIST_HXX
#define PCAD__UTIL__COLLECTION__LIST_HXX

#include <list>
#include <iostream>

namespace putil {
    /* I want to be able to do functional collections right now in C++, so
     * I'm adding a handful of extra methods to the STL containers so I can
     * do that. */
    namespace collection {
        template <typename value_type>
        class list: public std::list<value_type> {
        public:
            /* Unfortunately we still have to duplicate _all_ the
             * constructors of std::list so this is a transparent drop-in.
             * */
            explicit list(void)
            : std::list<value_type>()
            {}

            explicit list(size_t n)
            : std::list<value_type>(n)
            {}

            explicit list(size_t n, const value_type& val)
            : std::list<value_type>(n, val)
            {}

            template <class InputIterator>
            list (InputIterator first, InputIterator last)
            : std::list<value_type>(first, last)
            {}

            list(const list<value_type> &l)
            : std::list<value_type>(l)
            {}

            list(const list<value_type> &&l)
            : std::list<value_type>(l)
            {}

            list(const std::list<value_type> &l)
            : std::list<value_type>(l)
            {}

            list(const std::list<value_type> &&l)
            : std::list<value_type>(l)
            {}

            list(std::initializer_list<value_type> il)
            : std::list<value_type>(il)
            {}

            template <class ForwardIterator>
            list (ForwardIterator i)
            : std::list<value_type>(begin(i), end(i))
            {}

        public:
            auto head(void) const {
                auto first = this->begin();
                return *first;
            }

            auto rest(void) const {
                auto second = this->begin();
                second++;
                return list(second, this->end());
            }

        public:
            /* Converts these into functional collections so I can use them
             * sanely. */
            template <typename func>
            auto map(func f) {
                auto out = list<decltype(f(value_type()))>();
                for (const auto& i: *this)
                    out.push_back(f(i));
                return out;
            }

            template <typename func>
            auto reduce(func f) {
                auto out = list<decltype(f(value_type(), value_type()))>();
                auto prev = this->head();
                for (const auto& next: this->rest()) {
                    prev = f(prev, next);
                }
                return prev;
            }
        };
    }
}

#endif
