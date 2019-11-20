/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

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
