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

#ifndef PUTIL__FILESYSTEM_H
#define PUTIL__FILESYSTEM_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>

namespace putil {
    namespace filesystem {
        /* Recursively creates a directory tree, much the same as
         * 'mkdir -p'. */
        int mkdir_p(const std::string& path, mode_t mode);
        int mkdirat_p(int dirfd, const std::string& path, mode_t mode);
    }
}

#endif