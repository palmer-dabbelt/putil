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

#include <libputil/filesystem/textfile.h++>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        abort();

    auto file = putil::filesystem::textfile(argv[1], 0770);

    char *lineptr = NULL;
    size_t n;
    while (getline(&lineptr, &n, stdin) > 0)
        file.write(lineptr);

    return 0;
}
