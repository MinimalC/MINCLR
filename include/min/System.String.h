/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#define have_System_String

typedef System_fixed struct System_String {

    System_Size length;

    System_String8 value;

}  * System_String;

export struct System_Type  System_StringType;

export void System_String_free(System_String that);
export System_UInt64 System_String_getSipHash(System_String that);

#endif
