/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define have_Generic_T0  have_System_Object
#define Generic_T0Type  System_ObjectType
#endif
/*  GENERIC  */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0

typedef System_fixed struct Generic_T0 {
    struct System_Object base;

}  * Generic_T0;

export struct System_Type  Generic_T0Type;

typedef void delegate(Generic_T0_init)(Generic_T0 that);
typedef void delegate(Generic_T0_free)(Generic_T0 that);

export Generic_T0  new_Generic_T0();
export void  base_Generic_T0_init(Generic_T0 that);
export void  base_Generic_T0_free(Generic_T0 that);

#define Generic_T0_init(o)  ((function_Generic_T0_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define Generic_T0_free(o)  ((function_Generic_T0_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_Generic)
#define T0  Generic_T0
#define T0Type  Generic_T0Type

#define new_T0  new_Generic_T0
#define T0_init  Generic_T0_init
#define T0_free  Generic_T0_free
#define base_T0_init  base_Generic_T0_init
#define base_T0_free  base_Generic_T0_free
#define function_T0_init  function_Generic_T0_init
#define function_T0_free  function_Generic_T0_free
#endif
#endif
