/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include "textfile.h++"
#include <stdlib.h>
using namespace putil::filesystem;

#ifndef LINE_MAX
#define LINE_MAX 1024
#endif

void textfile::write(const std::string& data)
{
    if (_file.fputs(data.c_str()) < 0) {
        perror("unable to write to file");
        abort();
    }
}

std::vector<std::string> textfile::all_lines(void)
{
    char buf[LINE_MAX];
    std::vector<std::string> out;
    while (_file.fgets(buf, LINE_MAX) != NULL)
        out.push_back(buf);
    return out;
}
