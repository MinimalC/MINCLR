/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_DateTime)
#define have_System_DateTime

typedef System_SSize System_Time;

export struct System_Type  System_TimeType;

typedef struct System_TimeSpan {

    System_Time sec;
    System_Time usec;

} * System_TimeSpan;

export struct System_Type  System_TimeSpanType;

typedef struct System_TimeSpec {

    System_Int32 sec;
    System_Int32 usec;

} * System_TimeSpec;

export struct System_Type  System_TimeSpecType;

typedef struct System_TimeZone {

    System_Int32 minutesWest;
    System_Int32 dstTime;

} * System_TimeZone;

export struct System_Type  System_TimeZoneType;

typedef struct System_DateTime {

    System_SSize yearday;

    System_Size second, minute, hour, monthday, month, year, weekday, day, leap;

} * System_DateTime;

export struct System_Type  System_DateTimeType;

export System_DateTime System_DateTime_now();

export System_String8 System_DateTime_toString(System_DateTime that);

#if defined(using_System)

#endif
#endif
