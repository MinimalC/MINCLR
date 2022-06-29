/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_uint8
/* GENERIC */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_auto_Generic_T0)
#define have_auto_Generic_T0

export struct_System_Type  Generic_T0Type;

##if Type == "uint64"
##set b2L = 64
##set b4L = 32
##set b8L = 22
##set b16L = 16
##set b10L = 20
##else if Type == "uint32"
##set b2L = 32
##set b4L = 16
##set b8L = 11
##set b16L = 8
##set b10L = 10
##else if Type == "uint16"
##set b2L = 16
##set b4L = 8
##set b8L = 6
##set b16L = 4
##set b10L = 5
##else if Type == "uint8"
##set b2L = 8
##set b4L = 4
##set b8L = 3
##set b16L = 2
##set b10L = 3
##else
##error "Unknown Type. System.uint.awk implements uint8, uint16, uint32 and uint64"
##endif

#define Generic_T0_string8base2Length_DEFAULT  #b2L
#define Generic_T0_string8base4Length_DEFAULT  #b4L
#define Generic_T0_string8base8Length_DEFAULT  #b8L
#define Generic_T0_string8base16Length_DEFAULT  #b16L
#define Generic_T0_string8base10Length_DEFAULT  #b10L

export System_boolean  Generic_T0_isPrintable(Generic_T0 that);
export System_size  Generic_T0_tostring8base2__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base2Length_DEFAULT + 1]);
export System_size  Generic_T0_tostring8base4__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base4Length_DEFAULT + 1]);
export System_size  Generic_T0_tostring8base8__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base8Length_DEFAULT + 1]);
export System_size  Generic_T0_tostring8base16__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base16Length_DEFAULT + 1]);
export System_size  Generic_T0_tostring8base10__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base10Length_DEFAULT + 1]);
export Generic_T0  Generic_T0_parsebase10(System_string8 that);
#define inline_Generic_T0_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_Generic)
#define T0Type  Generic_T0Type
#define T0_isPrintable  Generic_T0_isPrintable
#endif
#endif
