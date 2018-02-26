#ifndef PCAD__UTIL__SIZE_T_HXX
#define PCAD__UTIL__SIZE_T_HXX

#include <cstdint>

constexpr std::size_t operator "" _z (unsigned long long n)
{ return n; }

#endif
