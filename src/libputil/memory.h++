/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__UTIL__MEMORY_HXX
#define PCAD__UTIL__MEMORY_HXX

#include <memory>

namespace std {
    template<typename T>
    auto begin(const std::shared_ptr<T>& p)
    { return begin(*p); }
    
    template<typename T>
    auto end(const std::shared_ptr<T>& p)
    { return end(*p); }
}

#endif
