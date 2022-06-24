/* Gemeinfrei. Public Domain. */
/* GENERIC */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.h"
#endif
#if !defined(have_auto_Generic_T0)
#define have_auto_Generic_T0

/* interface Generic.T0 */

#define struct_Generic_T0  struct class_Generic_T0
typedef __fixed struct_Generic_T0 { } * Generic_T0;
__export struct_System_Type  Generic_T0Type;

/* typedef System_void  __delegate(Generic_T0_method)(Generic_T0 that, System_String arg1); */

/* __export System_void  base_Generic_T0_method(Generic_T0 that, System_String arg1); */

/* #define Generic_T0_method(o,...)  ((function_Generic_T0_method)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0_method))(o, __VA_ARGS__) */

#if defined(using_Generic)
#define struct_T0  struct_Generic_T0
#define __T0  Generic_T0
#define __T0Type  Generic_T0Type

/* #define function_T0_method  function_Generic_T0_method
     #define base_T0_method      base_Generic_T0_method
        #define __T0_method           Generic_T0_method */
#endif
#endif
