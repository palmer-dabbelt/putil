/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__CLARGS__ARGUMENTS_HXX
#define PCAD__CLARGS__ARGUMENTS_HXX

#include "from_string.h++"
#include "parser.h++"
#include <libputil/collection.h++>
#include <libputil/collection/forward_iterator.h++>
#include <libputil/memory.h++>
#include <string>

namespace putil {
    namespace clargs {
        /* The interface the parser has into arguments. */
        class generic_argument {
        private:
            parser& _parser;
            const std::string _help;

        public:
            generic_argument(parser& p, std::string help)
            : _parser(p),
              _help(help)
            {}

            /* Run after parsing, returns true if all constraints on this
             * argument type were met. */
            virtual bool validate(void) const = 0;

            /* Run during parsing.  Called with a list view, returns the number
             * of entries that can be parsed off the argument list by argument
             * type.  This doesn't have to be a maximal munch. */
            virtual size_t munch(const putil::forward_iterator<std::string>& args) = 0;

            /* Some debug info about this argument. */
            virtual std::string debug(void) const = 0;
        };

        /* A list of arguments, all of the same type.  Each argument is
         * prefixed by a single argument switch. */
        template<typename T>
        class named_list_argument:
            public generic_argument,
            public putil::collection::list<T> {
        private:
            const putil::collection::list<std::string> _names;

        public:
            named_list_argument(
                parser &p,
                const putil::collection::list<std::string>& n,
                const std::string& h)
            : generic_argument(p, h),
              _names(n)
            {}

            virtual bool validate(void) const { return true; }

            virtual size_t munch(const putil::forward_iterator<std::string>& args) {
                for (const auto& name: _names) {
                    if (name == args[0]) {
                        this->push_back(from_string<T>(args[1]));
                        return 2;
                    }
                }
                return 0;
            }

            virtual std::string debug(void) const { return *(_names.begin()); }
        };

        /* Arguments which are a list of some type, but which are required to
         * exist.  This is simply a constrained version of the regular list
         * argument. */
        template<typename T>
        class required_named_list_argument:
            public named_list_argument<T> {
        public:
            required_named_list_argument(
                parser &p,
                const putil::collection::list<std::string>& n,
                const std::string& h)
            : named_list_argument<T>(p, n, h)
            {}

            virtual bool validate(void) const { return this->size() > 0; }
        };

        /* Arguments which consist of a single value that has a name. */
        template<typename T>
        class named_arg_argument:
            public generic_argument {
        private:
            const putil::collection::list<std::string> _names;

        protected:
            std::shared_ptr<T> _value;

        public:
            named_arg_argument(
                parser &p,
                const putil::collection::list<std::string>& n,
                const std::string& h)
            : generic_argument(p, h),
              _names(n),
              _value(nullptr)
            {}

            virtual T value(void) { return *_value; }
            virtual bool validate(void) const { return true; }

            virtual size_t munch(const putil::forward_iterator<std::string>& args) {
                for (const auto& name: _names) {
                    if (name == args[0]) {
                        _value = std::make_shared<T>(from_string<T>(args[1]));
                        return 2;
                    }
                }
                return 0;
            }

            virtual std::string debug(void) const { return *(_names.begin()); }
        };

        template<typename T>
        class required_named_arg_argument:
            public named_arg_argument<T> {
        public:
            required_named_arg_argument(
                parser &p,
                const putil::collection::list<std::string>& n,
                const std::string& h)
            : named_arg_argument<T>(p, n, h)
            {}

            virtual bool validate(void) const { return this->_value != nullptr; }
        };
    }
}

namespace std {
    static inline std::string to_string(const std::string& str) { return str; }

    template <typename T>
    string to_string(const std::shared_ptr<putil::clargs::named_arg_argument<T>>& arg)
    { return to_string(arg->value()); }

    template <typename T>
    string to_string(const std::shared_ptr<putil::clargs::required_named_arg_argument<T>>& arg)
    { return to_string(arg->value()); }
}

#endif
