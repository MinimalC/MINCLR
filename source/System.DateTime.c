/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_DateTime)
#include <min/System.DateTime.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/** class System_DateTime  **/

struct System_Type System_TimeType = { .base = { .type = typeof(System_Type) }, .name = "Time", .size = sizeof(System_Time) };

struct System_Type System_TimeSpanType = { .base = { .type = typeof(System_Type) }, .name = "TimeSpan", .size = sizeof(struct System_TimeSpan) };

struct System_Type System_TimeZoneType = { .base = { .type = typeof(System_Type) }, .name = "TimeZone", .size = sizeof(struct System_TimeZone) };

struct System_Type System_DateTimeType = { .base = { .type = typeof(System_Type) }, .name = "DateTime", .size = sizeof(struct System_DateTime) };

System_String8 System_DateTime_toString(System_DateTime that) {

    return System_String8_format("{0:uint}.{1:uint}.{2:uint} {3:uint}:{4:uint}:{5:uint}", 6,
        that->monthday, that->month, that->year, that->hour, that->minute, that->second);
}

System_DateTime System_DateTime_now(void) {

    System_SSize yday;
    System_Size  sec, min, hour, mday, mon, year, wday, days, leap;

    System_Time t = System_Syscall_time();

    /* the calculation is valid for positive time_t only */

    if (t < 0) {
        t = 0;
    }

    days = t / 86400;
    sec = t % 86400;

    /*
     * no more than 4 year digits supported,
     * truncate to December 31, 9999, 23:59:59
     */

    if (days > 2932896) {
        days = 2932896;
        sec = 86399;
    }

    /* January 1, 1970 was Thursday */

    wday = (4 + days) % 7;

    hour = sec / 3600;
    sec %= 3600;
    min = sec / 60;
    sec %= 60;

    /*
     * the algorithm based on Gauss' formula,
     * see src/core/ngx_parse_time.c
     */

    /* days since March 1, 1 BC */
    days = days - (31 + 28) + 719527;

    /*
     * The "days" should be adjusted to 1 only, however, some March 1st's go
     * to previous year, so we adjust them to 2.  This causes also shift of the
     * last February days to next year, but we catch the case when "yday"
     * becomes negative.
     */

    year = (days + 2) * 400 / (365 * 400 + 100 - 4 + 1);

    yday = days - (365 * year + year / 4 - year / 100 + year / 400);

    if (yday < 0) {
        leap = (year % 4 == 0) && (year % 100 || (year % 400 == 0));
        yday = 365 + leap + yday;
        year--;
    }

    /*
     * The empirical formula that maps "yday" to month.
     * There are at least 10 variants, some of them are:
     *     mon = (yday + 31) * 15 / 459
     *     mon = (yday + 31) * 17 / 520
     *     mon = (yday + 31) * 20 / 612
     */

    mon = (yday + 31) * 10 / 306;

    /* the Gauss' formula that evaluates days before the month */

    mday = yday - (367 * mon / 12 - 30) + 1;

    if (yday >= 306) {

        year++;
        mon -= 10;

        /*
         * there is no "yday" in Win32 SYSTEMTIME
         *
         * yday -= 306;
         */

    } else {

        mon += 2;

        /*
         * there is no "yday" in Win32 SYSTEMTIME
         *
         * yday += 31 + 28 + leap;
         */
    }

    System_DateTime that = System_Memory_allocClass(typeof(System_DateTime));
    that->yearday = yday;
    that->second = sec;
    that->minute = min; 
    that->hour = hour;
    that->monthday = mday;
    that->month = mon;
    that->year = year;
    that->weekday = wday;
    that->day = days;
    that->leap = leap;
    return that;
}
