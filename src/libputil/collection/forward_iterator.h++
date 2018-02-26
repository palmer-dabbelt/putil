/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__UTIL__FORWARD_ITERATOR_HXX
#define PCAD__UTIL__FORWARD_ITERATOR_HXX

#include <list>

namespace putil {
    /* I want to be able to iterate through containers of various sorts
     * without exposing whatever uses the iterator to the type of the
     * class.  This double-template lets me do so.  forward_iterator only
     * knows the type of values, while forward_iterator_t is templated on
     * the type of the iterator. */
    template <typename value>
    class forward_iterator {
    public:
        virtual value operator[](size_t index) const = 0;
    };

    template <typename iterator>
    class forward_iterator_t:
        public forward_iterator<typename iterator::value_type>
        {
    private:
        using value = typename iterator::value_type;
        const iterator _begin, _end;

    public:
        forward_iterator_t(
            const iterator& begin,
            const iterator& end
        ) : _begin(begin),
            _end(end)
        {}

    public:
        virtual value operator[](size_t index) const
        {
            iterator it = _begin;
            for (auto i = decltype(index)(0); i < index; ++i)
                it++;
            return *it;
        }
    };

    /* A utility function to build a forward iterator. */
    template <typename T>
    auto make_forward_iterator(const T& begin, const T& end)
    { return forward_iterator_t<T>(begin, end); }
}

#endif
