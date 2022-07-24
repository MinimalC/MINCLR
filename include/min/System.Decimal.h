/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#define have_System_Decimal

#define System_Decimal_Capacity_DEFAULT  126
export const System_Size  System_Decimal_Capacity;

typedef System_fixed struct System_Decimal {
    System_Int8  precision;
    System_UInt8  value[System_Decimal_Capacity_DEFAULT];
    System_UInt8  null;
} * System_Decimal;

#define stack_System_Decimal()  { }

export struct System_Type  System_DecimalType;

export void  System_Decimal_carryOver(System_Decimal  that, System_UInt8 digits);
export void  System_Decimal_init__UInt8(System_Decimal  that, System_UInt8 UInt8);
export void  System_Decimal_init__UInt16(System_Decimal  that, System_UInt16 UInt16);
export void  System_Decimal_init__UInt32(System_Decimal  that, System_UInt32 UInt32);
export void  System_Decimal_init__UInt64(System_Decimal  that, System_UInt64 UInt64);
export void  System_Decimal_init__Int8(System_Decimal  that, System_Int8 Int8);
export void  System_Decimal_init__Int16(System_Decimal  that, System_Int16 Int16);
export void  System_Decimal_init__Int32(System_Decimal  that, System_Int32 Int32);
export void  System_Decimal_init__Int64(System_Decimal  that, System_Int64 Int64);
export void  System_Decimal_toString8__stack(System_Decimal  that, System_Char8 array[System_Decimal_Capacity_DEFAULT + 1]);
export void  System_Decimal_set_Precision(System_Decimal  that, System_Int8 precision);
export System_Int8  System_Decimal_get_Precision(System_Decimal  that);

/* export void System_Decimal_add(System_Decimal that, System_Decimal other);
export void System_Decimal_subtract(System_Decimal that, System_Decimal other);
export void System_Decimal_divide(System_Decimal that, System_Decimal other);
export void System_Decimal_multiply(System_Decimal that, System_Decimal other); */

#define inline_System_Decimal_carryOver(string,digits)  \
    /* if digits > System_Decimal_Capacity_DEFAULT - 2 { throw Exception } */\
    for (System_Size i = 0; i < digits; ++i) {\
        while (*(string - i) > 9) { *(string - i - 1) += 1; *(string - i) -= 10; } }

#if defined(using_System)
#if !defined(have_System_Internal)
#define System_Decimal_carryOver  inline_System_Decimal_carryOver
#endif
#define Decimal  System_Decimal
#define DecimalType  System_DecimalType
#endif
#endif
