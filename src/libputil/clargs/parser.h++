/* Copyright (C) 2017 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */


#ifndef PCAD__CLARGS__PARSER_HXX
#define PCAD__CLARGS__PARSER_HXX

namespace putil {
    namespace clargs {
        class parser;
    }
}

#include "arguments.h++"
#include "exceptions.h++"
#include <libputil/memory.h++>
#include <list>

namespace putil {
    namespace clargs {
        /* Parses command-line arguments. */
        class parser {
        private:
            const std::list<std::string> _argv;
            std::list<std::shared_ptr<generic_argument>> _args;
            std::list<std::string> _unparsed;

        public:
            parser(int argc, char** argv)
            : _argv(argv_to_list(argc-1, argv+1)),
              _args(),
              _unparsed(_argv)
            {
            }

        public:
            /* Various argument handling helpers.  They're just plumbing to
             * generate the relevant types. */
            template<typename T>
            auto named_list(
                std::list<std::string> names,
                std::string help)
            {
                return insert(
                    std::make_shared<named_list_argument<T>>(
                        *this,
                        names,
                        help)
                    );
            }

            template<typename T>
            auto required_named_list(
                std::list<std::string> names,
                std::string help)
            {
                return insert(
                    std::make_shared<required_named_list_argument<T>>(
                        *this,
                        names,
                        help)
                    );
            }

            template<typename T>
            auto named_arg(
                std::list<std::string> names,
                std::string help)
            {
                return insert(
                    std::make_shared<named_arg_argument<T>>(
                        *this,
                        names,
                        help)
                    );
            }

            template<typename T>
            auto required_named_arg(
                std::list<std::string> names,
                std::string help)
            {
                return insert(
                    std::make_shared<required_named_arg_argument<T>>(
                        *this,
                        names,
                        help)
                    );
            }

        public:
            void parse(void);

        private:
            template<class T>
            std::shared_ptr<T> insert(std::shared_ptr<T> item) {
                _args.push_back(item);
                return item;
            }

            static std::list<std::string> argv_to_list(int argc, char **argv);
        };
    }
}

#endif
