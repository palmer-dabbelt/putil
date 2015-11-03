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

#include <libputil/collection.h++>

int func(int i)
{
    return i+1;
}

int main()
{
    std::vector<int> in{1, 2, 3};
    std::vector<int> out = putil::collection::map(in, &func);

    for (size_t i = 0; i < std::min(in.size(), out.size()); ++i)
        if (in[i]+1 != out[i])
            return 2;

    if (in.size() != out.size())
        return 3;

    return 0;
}
