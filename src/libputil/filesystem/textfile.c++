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

#include "textfile.h++"
using namespace putil::filesystem;

static inline const char *mode2str(mode_t mode)
{
    switch (mode) {
    case O_RDONLY:
        return "r";
    case O_WRONLY:
        return "w";
    case O_RDWR:
        return "w+";
    }

    return "";
}

void textfile::write(const std::string& data)
{
    if (this->fputs(data.c_str()) < 0) {
        perror("unable to write to file");
        abort();
    }
}
