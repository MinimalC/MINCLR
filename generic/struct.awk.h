/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#endif
/* Type1 required */
/*  GENERIC  */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.h"
#endif
#if !defined(have_auto_Generic_T0)
#define have_auto_Generic_T0

#define Generic_T0  struct s_Generic_T0
Generic_T0 {

};

#define stack_Generic_T0()  { }

__export struct_System_Type  Generic_T0Type;

#if defined(using_Generic)
#define stack_T0  stack_Generic_T0
#define __T0  Generic_T0
#define __T0Type  Generic_T0Type
#endif

#endif
#if !defined(have_auto_Generic1_T1)
#define have_auto_Generic1_T1

#define struct_Generic1_T1  struct class_Generic1_T1
typedef __fixed struct_Generic1_T1 {
    struct_System_Object base;

    Generic_T0 value;

}  * Generic1_T1;

#define stack_Generic1_T1(__value)  { .base = stack_System_Object(Generic1_T1), .value = __value, }

__export struct_System_Type  Generic1_T1Type;

typedef Generic1_T1 __delegate(Generic1_T1_init)(Generic1_T1 that, Generic_T0 value);
typedef System_void __delegate(Generic1_T1_free)(Generic1_T1 that);

#define Generic1_T1_new  Generic1_T1_new__01

__export Generic1_T1  Generic1_T1_new(Generic_T0 value);
__export Generic1_T1  base_Generic1_T1_init(Generic1_T1 that, Generic_T0 value);
__export System_void  base_Generic1_T1_free(Generic1_T1 that);

#define Generic1_T1_init(o,...)  ((function_Generic1_T1_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic1_T1_init))(o, __VA_ARGS__)
#define Generic1_T1_free(o)  ((function_Generic1_T1_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_Generic1_T1_new(value)  (base_Generic1_T1_init(inline_System_Object_allocClass(Generic1_T1), value))

#if !defined(have_Generic1_internal)
#undef  Generic1_T1_new
#define Generic1_T1_new  inline_Generic1_T1_new
#endif

#if defined(using_Generic1)
#define struct_T1  struct_Generic1_T1
#define stack_T1  stack_Generic1_T1
#define __T1  Generic1_T1
#define __T1Type  Generic1_T1Type

#define __T1_new  Generic1_T1_new

#define __T1_init  Generic1_T1_init
#define __T1_free  Generic1_T1_free
#define base_T1_init  base_Generic1_T1_init
#define base_T1_free  base_Generic1_T1_free
#define function_T1_init  function_Generic1_T1_init
#define function_T1_free  function_Generic1_T1_free
#endif

#endif
