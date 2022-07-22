/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Error)
#include "System.Error.h"
#endif
#if !defined(have_System_Exception)
#define have_System_Exception


typedef fixed struct System_Exception {
    struct System_Object base;

    System_Error error;

    System_String8  message;

}  * System_Exception;

export struct System_Type  System_ExceptionType;

#define stack_System_Exception()  (struct System_Exception){ .base = stack_System_Object(System_Exception) }
#define new_System_Exception(MESSAGE)  (base_System_Exception_init((System_Exception)System_Memory_allocClass(typeof(System_Exception)), MESSAGE))

export thread System_Exception  System_Exception_current;

typedef System_Exception delegate(System_Exception_init)(System_Exception that, System_String8 message);
typedef void delegate(System_Exception_free)(System_Exception that);

export void  System_Exception_throw(System_Exception that);
export void  System_Exception_terminate(System_Exception that) noreturn;

export System_Exception  base_System_Exception_init(System_Exception that, System_String8 message);
/* export void  base_System_Exception_free(System_Exception that); */
export System_Exception  System_Exception_get_current();
export void  System_Exception_set_current(System_Exception that);

#define System_Exception_init(o,...)  ((function_System_Exception_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Exception_init))(o, __VA_ARGS__)
#define System_Exception_free(o)  ((function_System_Exception_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_System)

#define Exception  System_Exception
#define ExceptionType  System_ExceptionType

#define new_Exception  new_System_Exception
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
    if (THAT) { System_Memory_addReference((System_Object)THAT); System_Exception_set_current(null); ACTION ; System_Memory_free(THAT); }

#define finally  __finally00: ;

#define finally_return(RETURN)  if (System_Exception_current) return RETURN ;

#define throw(EXCEPTION)  { System_Exception_throw(EXCEPTION); return; }

#define throw_return(EXCEPTION)  { System_Exception_throw(EXCEPTION); return null; }

#define throw_terminate  System_Exception_terminate


#endif
