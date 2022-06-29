/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define have_Generic_T0  have_System_Object
#define class_Generic_T0  class_System_Object
#define Generic_T0Type  System_ObjectType
#endif
/*  GENERIC  */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.h"
#endif
#if !defined(have_auto_Generic_T0)
#define have_auto_Generic_T0

export struct_System_Type  Generic_T0Type;

#if defined(using_Generic)
#define T0Type  Generic_T0Type
#endif

#endif
