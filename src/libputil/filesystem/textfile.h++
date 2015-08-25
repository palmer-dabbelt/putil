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

#ifndef PUTIL__FILESYSTEM__TEXTFILE_HXX
#define PUTIL__FILESYSTEM__TEXTFILE_HXX

#include "file.h++"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

namespace putil {
    namespace filesystem {
        /* A wrapper for text files that allows them to be somewhat
         * easily read. */
        class textfile {
        private:
            file _file;

        public:
            /* Opens a text file, given the path to that file. */
            textfile(const std::string& filename, mode_t mode = 0777)
                : _file(filename, mode)
                {}

        public:
            ~textfile(void) {}

        public:
            /* Writes a line to this file at the current position. */
            void write(const std::string& data);
        };
    }
}

#endif
