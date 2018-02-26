/* Copyright 2017 Palmer Dabbelt <palmer@dabbelt.com> */

#ifndef PCAD__UTIL__COLLECTION__UMAP_HXX
#define PCAD__UTIL__COLLECTION__UMAP_HXX

#include <iostream>
#include <unordered_map>

namespace putil {
    namespace collection {
        template <typename key_type, typename value_type>
        class umap:
            private std::unordered_map<key_type, value_type> {

        public:
            value_type get(const key_type& key) const
            {
                auto l = this->find(key);
                if (l == this->end()) {
                    std::cerr << "Unable to find " << key << "\n";
                    abort();
                }
                return l->second;
            }

            const list<value_type> values(void) const
            {
                return map([](auto p){ return p.second; });
            }

            template <typename func>
            auto map(func f) const
            {
                auto out = list<decltype(f(this->first()))>();
                for (const auto& i: *this)
                    out.push_back(f(i));
                return out;
            }

        private:
            /* This is really here just to get the type of */
            auto first(void) const
            {
                for (const auto& i: *this)
                    return i;
            }
        };
    }
}

#endif
