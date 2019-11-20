/* Copyright (C) 2014 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PCAD__UTIL__SIZE_T_HXX
#define PCAD__UTIL__SIZE_T_HXX

#include <cstdint>

constexpr std::size_t operator "" _z (unsigned long long n)
{ return n; }

#endif
