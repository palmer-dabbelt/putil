/*
 * Copyright (C) 2018 Palmer Dabbelt
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

#include <libputil/clargs.h++>

int main(int argc, char **argv)
{
    try {
        auto parser = putil::clargs::parser(argc, argv);
        auto input = parser.required_named_arg<std::string>({"-i", "--input"}, "input file name");
        parser.parse();

        std::cout << std::to_string(input) << "\n";
    } catch (const putil::clargs::exception &e) {
        std::cerr << e.message() << std::endl;
        abort();
    }

    return 0;
}
