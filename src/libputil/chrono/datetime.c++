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

using namespace putil::chrono;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

datetime::datetime(const std::string to_parse)
    : _error(0),
      _unix(gitdate::approxidate_careful(to_parse.c_str(), &_error))
{
}

const std::string datetime::local(void) const
{
    time_t time = _unix;

    struct tm tm;
    localtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%a, %d %b %Y %T %Z (%z)", &tm);

    return buffer;
}

const std::string datetime::gm(void) const
{
    time_t time = _unix;

    struct tm tm;
    gmtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%a, %d %b %Y %T %Z (%z)", &tm);

    return buffer;
}

uint64_t datetime::unix(void) const
{
    return _unix;
}

const std::string datetime::ddmm(void) const
{
    time_t time = _unix;

    struct tm tm;
    localtime_r(&time, &tm);

    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%m/%d", &tm);

    return buffer;
}

std::shared_ptr<datetime> datetime::now(void)
{
    time_t tod;
    time(&tod);

    struct tm tm;
    localtime_r(&tod, &tm);

    char rfc_2822_date[BUFFER_SIZE];
    strftime(rfc_2822_date, BUFFER_SIZE, "%a, %d %b %Y %T %z", &tm);

    return std::make_shared<datetime>(rfc_2822_date);
}
