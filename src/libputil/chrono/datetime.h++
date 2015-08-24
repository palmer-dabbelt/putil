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

#ifndef LIBPUTIL__CHRONO__DATETIME_HXX
#define LIBPUTIL__CHRONO__DATETIME_HXX

#include <memory>
#include <string>

namespace putil {
    namespace chrono {
        /* Stores both the date and the time, with the option to
         * format these dates as many different formats. */
        class datetime {
        private:
            /* The returned error code that came from parsing this
             * date. */
            int _error;

            /* The canonical date format: UNIX time, stored in UTC. */
            const uint64_t _unix;

        public:
            /* Parses the given string into a date. */
            datetime(const std::string to_parse);

            /* Returns this date, pretty printed in the current local
             * timezone.  This is roughly 2822, but with a timezone
             * abbreviation in there as well as the hour offset. */
            const std::string local(void) const;

            /* Returns this date, pretty printed in the UTC (or whatever
             * comes out of gmtime()...).  This is roughly 2822, but with
             * a timezone abbreviation in there as well as the hour
             * offset. */
            const std::string gm(void) const;

            /* Returns the time as an integer.  This is effectively just
             * UNIX time. */
            uint64_t unix(void) const;

            /* Returns the time as a string, which just contains the
             * decimal representation of the UNIX time above. */
            const std::string unix_str(void) const;

            /* Prints DD/MM, the day/month format. */
            const std::string ddmm(void) const;

        public:
            /* Creates a new date that represents the time right now. */
            static std::shared_ptr<datetime> now(void);
        };
    }
}

#endif
