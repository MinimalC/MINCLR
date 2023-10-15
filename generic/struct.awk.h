/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#endif
/* Type1 required */
/*  GENERIC  */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0

typedef System_fixed struct Generic_T0 {

} * Generic_T0;

export struct System_Type  Generic_T0Type;

export void  Generic_T0_init(Generic_T0 that);

#if defined(using_Generic)
#define T0  Generic_T0
#define T0Type  Generic_T0Type

#endif
#endif
#if !defined(have_Generic1_T1)
#define have_Generic1_T1

typedef System_fixed struct Generic1_T1 {
    struct System_Object base;

    Generic_T0 value;

}  * Generic1_T1;

export struct System_Type  Generic1_T1Type;

typedef void delegate(Generic1_T1_init)(Generic1_T1 that, Generic_T0 value);
typedef void delegate(Generic1_T1_free)(Generic1_T1 that);

export Generic1_T1  new_Generic1_T1(Generic_T0 value);
export void  base_Generic1_T1_init(Generic1_T1 that, Generic_T0 value);
export void  base_Generic1_T1_free(Generic1_T1 that);

#define Generic1_T1_init(o,...)  ((function_Generic1_T1_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic1_T1_init))(o, __VA_ARGS__)
#define Generic1_T1_free(o)  ((function_Generic1_T1_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_Generic1)

#define T1  Generic1_T1
#define T1Type  Generic1_T1Type
#define new_T1  new_Generic1_T1
#define T1_init  Generic1_T1_init
#define T1_free  Generic1_T1_free
#define base_T1_init  base_Generic1_T1_init
#define base_T1_free  base_Generic1_T1_free
#define function_T1_init  function_Generic1_T1_init
#define function_T1_free  function_Generic1_T1_free
#endif
#endif