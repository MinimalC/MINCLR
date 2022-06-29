/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#define have_System_decimal

#define System_decimal_Capacity_DEFAULT  128
export const System_size  System_decimal_Capacity;

#define System_decimal  struct s_System_decimal
System_decimal {
    System_int8  precision;
    System_uint8  value[System_decimal_Capacity_DEFAULT + 1];
};

#define stack_System_decimal()  { }

export struct_System_Type  System_decimalType;

export void  System_decimal_carryOver(System_decimal  * that, System_uint8 digits);
export void  System_decimal_init__uint8(System_decimal  * that, System_uint8 uint8);
export void  System_decimal_init__uint16(System_decimal  * that, System_uint16 uint16);
export void  System_decimal_init__uint32(System_decimal  * that, System_uint32 uint32);
export void  System_decimal_init__uint64(System_decimal  * that, System_uint64 uint64);
export void  System_decimal_init__int8(System_decimal  * that, System_int8 int8);
export void  System_decimal_init__int16(System_decimal  * that, System_int16 int16);
export void  System_decimal_init__int32(System_decimal  * that, System_int32 int32);
export void  System_decimal_init__int64(System_decimal  * that, System_int64 int64);
export void  System_decimal_tostring8__stack(System_decimal  * that, System_char8 array[System_decimal_Capacity_DEFAULT + 1]);
export void  System_decimal_set_Precision(System_decimal  * that, System_int8 precision);
export System_int8  System_decimal_get_Precision(System_decimal  * that);

/* export void System_decimal_add(System_decimal that, System_decimal other);
export void System_decimal_subtract(System_decimal that, System_decimal other);
export void System_decimal_divide(System_decimal that, System_decimal other);
export void System_decimal_multiply(System_decimal that, System_decimal other); */

#define inline_System_decimal_carryOver(string,digits)  \
    /* if digits > System_decimal_Capacity_DEFAULT - 2 { throw Exception } */\
    for (System_size i = 0; i < digits; ++i) {\
        while (*(string - i) > 9) { *(string - i - 1) += 1; *(string - i) -= 10; } }

#if defined(using_System)
#define decimal  System_decimal
#define decimalType  System_decimalType
#endif
#endif
