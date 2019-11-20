/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

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
            friend class lockfile;

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
            int flock(int operation);

            /* man 3 */
            int fputs(const std::string& s);
            int feof(void);
            char *fgets(char *s, int size);
        };
    }
}

#endif
