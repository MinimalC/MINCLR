/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_UInt8
/* GENERIC */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0

export struct System_Type  Generic_T0Type;

##if Type == "UInt64"
##set b2L = 64
##set b4L = 32
##set b8L = 22
##set b16L = 16
##set b10L = 20
##else if Type == "UInt32"
##set b2L = 32
##set b4L = 16
##set b8L = 11
##set b16L = 8
##set b10L = 10
##else if Type == "UInt16"
##set b2L = 16
##set b4L = 8
##set b8L = 6
##set b16L = 4
##set b10L = 5
##else if Type == "UInt8"
##set b2L = 8
##set b4L = 4
##set b8L = 3
##set b16L = 2
##set b10L = 3
##else
##error "Unknown Type. System.uint.awk implements UInt8, UInt16, UInt32 and UInt64"
##endif

#define Generic_T0_String8base2Length_DEFAULT  #b2L
#define Generic_T0_String8base4Length_DEFAULT  #b4L
#define Generic_T0_String8base8Length_DEFAULT  #b8L
#define Generic_T0_String8base16Length_DEFAULT  #b16L
#define Generic_T0_String8base10Length_DEFAULT  #b10L

export System_Bool  Generic_T0_isPrintable(Generic_T0 that);
export System_Size  stack_Generic_T0_toString8base2(Generic_T0 that, System_Char8 array[Generic_T0_String8base2Length_DEFAULT + 1]);
export System_Size  stack_Generic_T0_toString8base4(Generic_T0 that, System_Char8 array[Generic_T0_String8base4Length_DEFAULT + 1]);
export System_Size  stack_Generic_T0_toString8base8(Generic_T0 that, System_Char8 array[Generic_T0_String8base8Length_DEFAULT + 1]);
export System_Size  stack_Generic_T0_toString8base16(Generic_T0 that, System_Char8 array[Generic_T0_String8base16Length_DEFAULT + 1]);
export System_Size  stack_Generic_T0_toString8base10(Generic_T0 that, System_Char8 array[Generic_T0_String8base10Length_DEFAULT + 1]);
export Generic_T0  Generic_T0_parsebase10(System_String8 that);
#define inline_Generic_T0_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
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
