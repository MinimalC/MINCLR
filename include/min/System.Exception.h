/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Exception)
#define have_System_Exception

#define struct_System_Exception  struct class_System_Exception
typedef __fixed struct_System_Exception {
    struct_System_Object base;

    System_string8  message;

}  * System_Exception;

__export struct_System_Type  System_ExceptionType;

#define stack_System_Exception()  (struct_System_Exception){ .base = stack_System_Object(System_Exception) }

__export __thread System_Exception  System_Exception_current;

typedef System_Exception __delegate(System_Exception_init)(System_Exception that, System_string8 message);
typedef System_void __delegate(System_Exception_free)(System_Exception that);

__export System_Exception  System_Exception_new(System_string8 message);
__export System_void  System_Exception_throw(System_Exception that);
__export System_void  System_Exception_terminate(System_Exception that) __noreturn;

__export System_Exception  base_System_Exception_init(System_Exception that, System_string8 message);
/* __export System_void  base_System_Exception_free(System_Exception that); */
__export System_Exception  System_Exception_get_current();
__export System_void  System_Exception_set_current(System_Exception that);

#define System_Exception_init(o,...)  ((function_System_Exception_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Exception_init))(o, __VA_ARGS__)
#define System_Exception_free(o)  ((function_System_Exception_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_System_Exception_new(__message)  (base_System_Exception_init(inline_System_Object_allocClass(System_Exception), __message))

#if defined(using_System)
#define struct_Exception  struct_System_Exception
#define __Exception  System_Exception
#define __ExceptionType  System_ExceptionType

#define __Exception_new  System_Exception_new
#define __Exception_throw  System_Exception_throw
#define __Exception_terminate  System_Exception_terminate

#define function_Exception_init  function_System_Exception_init
#define function_Exception_free  function_System_Exception_free
#define base_Exception_init  base_System_Exception_init
/* #define base_Exception_free  base_System_Exception_free */
#define __Exception_init  System_Exception_init
#define __Exception_free  System_Exception_free
#define __Exception_get_current  System_Exception_get_current
#define __Exception_set_current  System_Exception_set_current
#endif


#define __try  if (System_Exception_current) goto __catch00;

#define __catch  if (!System_Exception_current) goto __finally00; __catch00: ;

#define __catch_class(__TYPE,__that,__statements)  __TYPE __that = inline_System_Object_asType(System_Exception_current, __TYPE);\
    if (__that) { System_Object_addReference((System_Object)__that); System_Exception_set_current(__null); __statements ; inline_System_Object_freeClass(&__that); }

#define __finally  __finally00: ;

#define __finally_return(__return)  if (System_Exception_current) return __return ;

#define __throw(__exception)  { System_Exception_throw(__exception); return; }

#define __throw_return(__exception)  { System_Exception_throw(__exception); return System_null; }

#define __throw_terminate  System_Exception_terminate


#endif
