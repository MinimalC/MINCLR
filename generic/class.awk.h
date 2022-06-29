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

#define struct_Generic_T0  struct class_Generic_T0
typedef fixed struct_Generic_T0 {
    struct_System_Object base;

}  * Generic_T0;

#define stack_Generic_T0()  { .base = stack_System_Object(Generic_T0) }

export struct_System_Type  Generic_T0Type;

typedef Generic_T0 delegate(Generic_T0_init)(Generic_T0 that);
typedef void delegate(Generic_T0_free)(Generic_T0 that);

#define Generic_T0_new  Generic_T0_new__00

export Generic_T0  Generic_T0_new();
export Generic_T0  base_Generic_T0_init(Generic_T0 that);
export void  base_Generic_T0_free(Generic_T0 that);

#define Generic_T0_init(o)  ((function_Generic_T0_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define Generic_T0_free(o)  ((function_Generic_T0_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_Generic_T0_new()  (base_Generic_T0_init(inline_System_Object_allocClass(Generic_T0)))

#if !defined(have_Generic_internal)
#undef  Generic_T0_new
#define Generic_T0_new  inline_Generic_T0_new
#endif

#if defined(using_Generic)
#define struct_T0  struct_Generic_T0
#define stack_T0  stack_Generic_T0
#define T0  Generic_T0
#define T0Type  Generic_T0Type

#define T0_new  Generic_T0_new

#define T0_init  Generic_T0_init
#define T0_free  Generic_T0_free
#define base_T0_init  base_Generic_T0_init
#define base_T0_free  base_Generic_T0_free
#define function_T0_init  function_Generic_T0_init
#define function_T0_free  function_Generic_T0_free
#endif

#endif
