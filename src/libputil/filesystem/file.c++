/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include "file.h++"
#include <sys/file.h>
#include <stdlib.h>
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

int file::flock(int operation)
{
    return ::flock(_fd, operation);
}

int file::fputs(const std::string& s)
{
    return ::fputs(s.c_str(), _file);
}

int file::feof(void)
{
    return ::feof(_file);
}

char *file::fgets(char *s, int size)
{
    return ::fgets(s, size, _file);
}
