/*
 * Copyright (C) 2015 Palmer Dabbelt
 *   <palmer@dabbelt.com>
 *
 * This file is part of putil
 * 
 * putil is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * putil is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with putil.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "datetime.h++"
#include <gitdate.h>
#include <time.h>
#include <stdlib.h>

using namespace putil::chrono;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

static inline struct timespec unix2ts(const time_t t)
{
    struct timespec out;
    out.tv_sec = t;
    out.tv_nsec = 0;
    return out;
}

datetime::datetime(const struct timespec& ts)
    : _error(0),
      _ts(ts)
{
}

datetime::datetime(const std::shared_ptr<datetime>& dt)
    : _error(dt->_error),
      _ts(dt->_ts)
{
}

datetime::datetime(const std::string to_parse)
    : _error(0),
      _ts(unix2ts(gitdate::approxidate_careful(to_parse.c_str(), &_error)))
{
}

const std::string datetime::local(void) const
{
    time_t time = this->unix_seconds();

    struct tm tm;
    localtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%a, %d %b %Y %T %Z (%z)", &tm);

    return buffer;
}

const std::string datetime::gm(void) const
{
    time_t time = this->unix_seconds();

    struct tm tm;
    gmtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%a, %d %b %Y %T %Z (%z)", &tm);

    return buffer;
}

time_t datetime::unix_seconds(void) const
{
    return _ts.tv_sec;
}

uint64_t datetime::unix_nanoseconds(void) const
{
    return _ts.tv_sec * (1000 * 1000 * 1000) + _ts.tv_nsec;
}

const std::string datetime::ddmm(void) const
{
    time_t time = this->unix_seconds();

    struct tm tm;
    localtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%m/%d", &tm);

    return buffer;
}

datetime datetime::now(clockid_t id)
{
    struct timespec ts;
    if (clock_gettime(id, &ts)) {
        perror("clock_gettime() failed");
        abort();
    }

    return datetime(ts);
}

