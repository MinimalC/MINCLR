/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_error)
#include "System.error.h"
#endif
#if !defined(have_System_Exception)
#define have_System_Exception

#define struct_System_Exception  struct System_Exception
typedef fixed struct_System_Exception {
    struct_System_Object base;

    System_error error;

    System_string8  message;

}  * System_Exception;

export struct_System_Type  System_ExceptionType;

#define stack_System_Exception()  (struct_System_Exception){ .base = stack_System_Object(System_Exception) }

export thread System_Exception  System_Exception_current;

typedef System_Exception delegate(System_Exception_init)(System_Exception that, System_string8 message);
typedef void delegate(System_Exception_free)(System_Exception that);

export void  System_Exception_throw(System_Exception that);
export void  System_Exception_terminate(System_Exception that) noreturn;

export System_Exception  base_System_Exception_init(System_Exception that, System_string8 message);
/* export void  base_System_Exception_free(System_Exception that); */
export System_Exception  System_Exception_get_current();
export void  System_Exception_set_current(System_Exception that);

#define System_Exception_init(o,...)  ((function_System_Exception_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Exception_init))(o, __VA_ARGS__)
#define System_Exception_free(o)  ((function_System_Exception_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define new_System_Exception(MESSAGE)  (base_System_Exception_init((System_Exception)System_Memory_allocClass(typeof(System_Exception)), MESSAGE))
#define new_System_Exception__error()  (System_Exception)(base_System_Object_init((System_Object)System_Memory_allocClass(typeof(System_Exception))))

#if defined(using_System)
#define struct_Exception  struct_System_Exception
#define Exception  System_Exception
#define ExceptionType  System_ExceptionType

#define Exception_new  System_Exception_new
#define Exception_throw  System_Exception_throw
#define Exception_terminate  System_Exception_terminate

#define function_Exception_init  function_System_Exception_init
#define function_Exception_free  function_System_Exception_free
#define base_Exception_init  base_System_Exception_init
/* #define base_Exception_free  base_System_Exception_free */
#define Exception_init  System_Exception_init
#define Exception_free  System_Exception_free
#define Exception_get_current  System_Exception_get_current
#define Exception_set_current  System_Exception_set_current
#endif


#define try  if (System_Exception_current) goto __catch00;

#define catch  if (!System_Exception_current) goto __finally00; __catch00: ;

#define catch_class(TYPE,THAT,ACTION)  TYPE THAT = inline_System_Object_asInstanceof(System_Exception_current, TYPE);\
    if (THAT) { System_Object_addReference((System_Object)THAT); System_Exception_set_current(null); ACTION ; System_Memory_freeClass(&THAT); }

#define finally  __finally00: ;

#define finally_return(RETURN)  if (System_Exception_current) return RETURN ;

#define throw(EXCEPTION)  { System_Exception_throw(EXCEPTION); return; }

#define throw_return(EXCEPTION)  { System_Exception_throw(EXCEPTION); return System_null; }

#define throw_terminate  System_Exception_terminate


#endif
