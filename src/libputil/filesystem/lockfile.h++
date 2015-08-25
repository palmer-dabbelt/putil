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

#ifndef PUTIL__FILESYSTEM__LOCKFILE_HXX
#define PUTIL__FILESYSTEM__LOCKFILE_HXX

#include "file.h++"

namespace putil {
    namespace filesystem {
        /* A wrapper for lock files.  This is a RAII sort of thing
         * that uses flock() to allow for reader/writer locks as
         * implemented by the filesystem. */
        class lockfile {
        private:
            file _file;

        public:
            lockfile(const std::string& path, bool write)
                : _file(path, 0777)
                { _file.flock(write ? LOCK_EX : LOCK_SH); }
            ~lockfile(void)
                { _file.flock(LOCK_UN); }

        public:
            /* Friendly names for the constructors. */
            static lockfile rdlock(const std::string& path)
                { return lockfile(path, false); }
            static lockfile rwlock(const std::string& path)
                { return lockfile(path, true); }
        };
    }
}

#endif
