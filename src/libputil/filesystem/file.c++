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

#include "file.h++"
using namespace putil::filesystem;


file::file(const std::string& filename, mode_t mode)
{
    _fd = open(filename.c_str(), O_RDWR | O_CREAT, mode);
    if (_fd < 0) {
        perror("unable to open fd");
        abort();
    }

    _file = fdopen(_fd, "w+");
    if (_file == NULL) {
        perror("unable to open fd");
        abort();
    }
}

file::~file(void)
{
    fclose(_file);
    _file = NULL;
    _fd = -1;
}

int file::fputs(const std::string& s)
{
    return ::fputs(s.c_str(), _file);
}
