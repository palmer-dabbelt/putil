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

#ifndef LIBPUTIL__FILESYSTEM__FILE_HXX
#define LIBPUTIL__FILESYSTEM__FILE_HXX

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

namespace putil {
    namespace filesystem {
        /* Represents a native target file object. */
        class file {
            /* Most classes should't use this at all, so pretty much
             * all the methods are going be protected.  If you're
             * thinking of this then you should probably go and use
             * one of the inner classes instead. */
            friend class textfile;

        private:
            int _fd;
            FILE *_file;

        public:
            /* Opens a file by a path, which is relative if it doesn't
             * start with a '/'. */
            file(const std::string& name, mode_t mode);

            ~file(void);

        protected:
            /* man 2 */

            /* man 3 */
            int fputs(const std::string& s);
            
        };
    }
}

#endif
