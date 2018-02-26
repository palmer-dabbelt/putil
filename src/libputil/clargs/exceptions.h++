/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__CLARGS__EXCEPTIONS_HXX
#define PCAD__CLARGS__EXCEPTIONS_HXX

#include <memory>
#include <string>

namespace putil {
    namespace clargs {
        class exception {
        private:
            const std::string _message;

        public:
            exception(const std::string& message)
            : _message(message)
            {}

            virtual std::string message(void) const
            { return _message; }
        };

        class invalid_argument: public exception {
        public:
            invalid_argument(const std::string& arg)
            : exception("invalid argument: " + arg)
            {}
        };

        class missing_argument: public exception {
        public:
            missing_argument(const std::string parse)
            : exception("no argument specified for " + parse)
            {}
        };

        class duplicate_argument: public exception {
        public:
            duplicate_argument(
                const std::string& clarg,
                const std::string& parse_a,
                const std::string& parse_b)
            : exception("internal error: command-line argument " + clarg + " parses via both " + parse_a + " and " + parse_b)
            {}
        };

        class no_index_for_argument: public exception {
        public:
            no_index_for_argument(void)
            : exception("argument parsing terminated with end of array")
            {}
        };
    }
}

#endif
