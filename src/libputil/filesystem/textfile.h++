/* Copyright (C) 2015-2016 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PUTIL__FILESYSTEM__TEXTFILE_HXX
#define PUTIL__FILESYSTEM__TEXTFILE_HXX

#include "file.h++"
#include <functional>
#include <vector>

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

            /* Reads a single line from this file. */
            std::string read(void);

            /* Reads every line in a text file, returning them as an array. */
            std::vector<std::string> all_lines(void);

            /* Reads every line in a text file, converting it to the given
             * type.  This will produce a vector of exactly "line_count"
             * elements, resorting to "default_value" when the text file runs
             * out of lines. */
            template<typename E>
            std::vector<E> convert_lines(
                size_t line_count,
                E default_value,
                std::function<E(std::string)> convert)
            {
                auto lines = this->all_lines();
                auto out = std::vector<E>();
                for (size_t i = 0; i < std::min(line_count, lines.size()); ++i)
                    out.push_back(convert(lines[i]));
                while (out.size() < line_count)
                    out.push_back(default_value);
                return out;
            }
        };
    }
}

#endif
