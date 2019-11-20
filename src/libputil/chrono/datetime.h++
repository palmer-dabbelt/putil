/* Copyright (C) 2015 Palmer Dabbelt <palmer@dabbelt.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef LIBPUTIL__CHRONO__DATETIME_HXX
#define LIBPUTIL__CHRONO__DATETIME_HXX

#include <memory>
#include <string>
#include <time.h>

namespace putil {
    namespace chrono {
        /* Stores both the date and the time, with the option to
         * format these dates as many different formats. */
        class datetime {
        private:
            /* The returned error code that came from parsing this
             * date. */
            int _error;

            /* The canonical date format: number of microseconds since
             * the UNIX epoch. */
            const struct timespec _ts;

        public:
            /* Whatever, just don't screw it up.  This should all be
             * std::chrono now. */
            datetime(const struct timespec& ts);

        public:
            /* Copy a datetime from various formats. */
            datetime(const std::shared_ptr<datetime>& dt);

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
            time_t unix_seconds(void) const;

            /* Returns the time, scaled a a number of nanoseconds (not
             * a residual). */
            uint64_t unix_nanoseconds(void) const;

            /* Prints DD/MM, the day/month format. */
            const std::string ddmm(void) const;

        public:
            /* Creates a new date that represents the time right now,
             * as provided by the given clock source. */
            static datetime now(clockid_t id = CLOCK_REALTIME);
        };
    }
}

#endif
