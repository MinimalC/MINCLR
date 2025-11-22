/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_Int8
/* GENERIC */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0
enum {
##if Type == "Int64"
    Generic_T0_String8Capacity_base2 = 64 + 1,
    Generic_T0_String8Capacity_base4 = 32 + 1,
    Generic_T0_String8Capacity_base8 = 22 + 1,
    Generic_T0_String8Capacity_base16 = 16 + 1,
    Generic_T0_String8Capacity_base10 = 20 + 1,
##else if Type == "Int32"
    Generic_T0_String8Capacity_base2 = 32 + 1,
    Generic_T0_String8Capacity_base4 = 16 + 1,
    Generic_T0_String8Capacity_base8 = 11 + 1,
    Generic_T0_String8Capacity_base16 = 8 + 1,
    Generic_T0_String8Capacity_base10 = 10 + 1,
##else if Type == "Int16"
    Generic_T0_String8Capacity_base2 = 16 + 1,
    Generic_T0_String8Capacity_base4 = 8 + 1,
    Generic_T0_String8Capacity_base8 = 6 + 1,
    Generic_T0_String8Capacity_base16 = 4 + 1,
    Generic_T0_String8Capacity_base10 = 5 + 1,
##else if Type == "Int8"
    Generic_T0_String8Capacity_base2 = 8 + 1,
    Generic_T0_String8Capacity_base4 = 4 + 1,
    Generic_T0_String8Capacity_base8 = 3 + 1,
    Generic_T0_String8Capacity_base16 = 2 + 1,
    Generic_T0_String8Capacity_base10 = 3 + 1,
##else
##error "Unknown Type. System.int.awk implements Int8, Int16, Int32 and Int64."
##endif
};
export struct System_Type  Generic_T0Type;
export System_Bool  Generic_T0_isPrintable(Generic_T0 that);
#define inline_Generic_T0_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_Generic_T0_toString8base2(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base2 + 1]);
export System_Size  stack_Generic_T0_toString8base4(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base4 + 1]);
export System_Size  stack_Generic_T0_toString8base8(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base8 + 1]);
export System_Size  stack_Generic_T0_toString8base16(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base16 + 1]);
export System_Size  stack_Generic_T0_toString8base10(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base10 + 1]);;
export System_String8  Generic_T0_toString8base2(Generic_T0 that);
export System_String8  Generic_T0_toString8base4(Generic_T0 that);
export System_String8  Generic_T0_toString8base8(Generic_T0 that);
export System_String8  Generic_T0_toString8base16(Generic_T0 that);
export System_String8  Generic_T0_toString8base10(Generic_T0 that);
#if defined(using_Generic)
#define T0Type  Generic_T0Type
#define T0_isPrintable  Generic_T0_isPrintable
#define stack_T0_toString8base2  stack_Generic_T0_toString8base2
#define stack_T0_toString8base4  stack_Generic_T0_toString8base4
#define stack_T0_toString8base8  stack_Generic_T0_toString8base8
#define stack_T0_toString8base16  stack_Generic_T0_toString8base16
#define stack_T0_toString8base10  stack_Generic_T0_toString8base10
#endif
#endif
