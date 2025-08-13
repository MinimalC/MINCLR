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

export System_String8 System_DateTime_toString(System_DateTime that);
export System_String8 System_DateTime_now_toString();
export System_DateTime System_DateTime_now();
export void stack_System_DateTime_now(System_DateTime that);

#if defined(using_System)
#define DateTime  System_DateTime
#define DateTimeType  System_DateTimeType
#define DateTime_toString  System_DateTime_toString
#define DateTime_now_toString  System_DateTime_now_toString
#define DateTime_now  System_DateTime_now
#define stack_DateTime_now  stack_System_DateTime_now
#endif
#endif
