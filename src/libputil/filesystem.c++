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

#include "filesystem.h++"
#include <iostream>
#include <unistd.h>

int putil::filesystem::mkdir_p(const std::string& path, mode_t mode)
{
    return mkdirat_p(AT_FDCWD, path, mode);
}

int putil::filesystem::mkdirat_p(int dirfd, const std::string& path, mode_t m)
{
    for (size_t i = 1; i < path.length(); ++i) {
        if (path[i] != '/')
            continue;

        auto dirname = path.substr(0, i);
        std::cerr << "Creating " << dirname << "\n";
        auto out = mkdirat(dirfd, dirname.c_str(), m);
        if (out == -1 && errno != EEXIST)
            return out;
    }

    auto out = mkdirat(dirfd, path.c_str(), m);
    if (out == -1 && errno != EEXIST)
        return out;

    return 0;
}
