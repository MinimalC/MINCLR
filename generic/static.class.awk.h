/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define have_Generic_T0  have_System_Object
#define class_Generic_T0  class_System_Object
#define Generic_T0Type  System_ObjectType
#endif
/*  GENERIC  */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0

export struct System_Type  Generic_T0Type;

#if defined(using_Generic)
#define T0Type  Generic_T0Type
#endif
#endif
