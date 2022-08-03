/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Error)
#include "System.Error.h"
#endif
#if !defined(have_System_String8)
#include "System.String8.h"
#endif
#if !defined(have_System_Exception)
#define have_System_Exception

typedef System_fixed struct System_Exception {
    struct System_Object base;

    System_Error error;

    System_String8  message;

}  * System_Exception;

export struct System_Type  System_ExceptionType;

#define stack_System_Exception(MESSAGE)  { .base = stack_System_Object(System_Exception), .message = MESSAGE }
#define stack_System_Exception__error(ERROR, MESSAGE)  { .base = stack_System_Object(System_Exception), .error = ERROR, .message = MESSAGE }
#define new_System_Exception(MESSAGE)  (base_System_Exception_init((System_Exception)System_Memory_allocClass(typeof(System_Exception)), MESSAGE))

export thread System_Exception  System_Exception_current;

typedef System_Exception delegate(System_Exception_init)(System_Exception that, System_String8 message);
typedef void delegate(System_Exception_free)(System_Exception that);

export System_Bool  System_Exception_try(void);
export System_Bool  System_Exception_tryNot(void);
export void  System_Exception_throw(System_Exception that);
export void  System_Exception_terminate(System_Exception that) noreturn;
export System_Bool  stack_System_Exception_catch(System_Exception that, System_Type type);

export System_Exception  base_System_Exception_init(System_Exception that, System_String8 message);
/* export void  base_System_Exception_free(System_Exception that); */

#define System_Exception_init(o,...)  ((function_System_Exception_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Exception_init))(o, __VA_ARGS__)
#define System_Exception_free(o)  ((function_System_Exception_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_System_Exception_try() (System_Exception_current && System_Exception_current->base.type)
#define inline_System_Exception_tryNot() (!System_Exception_current || !System_Exception_current->base.type)

#if defined(using_System)
#if !defined(internal_System)
#endif
#define Exception  System_Exception
#define ExceptionType  System_ExceptionType
#define new_Exception  new_System_Exception
#define stack_Exception  stack_System_Exception

#define Exception_try  System_Exception_try
#define Exception_tryNot  System_Exception_tryNot
#define Exception_throw  System_Exception_throw
#define Exception_terminate  System_Exception_terminate
#define Exception_catch  System_Exception_catch

#define function_Exception_init  function_System_Exception_init
#define function_Exception_free  function_System_Exception_free
#define base_Exception_init  base_System_Exception_init
/* #define base_Exception_free  base_System_Exception_free */
#define Exception_init  System_Exception_init
#define Exception_free  System_Exception_free
#endif

#define System_try  if (inline_System_Exception_try()) goto __catch00;

#define System_try_throw(EXCEPTION)  System_Exception_throw((System_Exception)EXCEPTION); goto __catch00;

#define System_catch  if (inline_System_Exception_tryNot()) goto __finally00;\
__catch00: ;

#define System_catch_class(TYPE,THAT,ACTION)  do { struct TYPE ff(struct,THAT); TYPE THAT = &ff(struct,THAT);\
if (stack_System_Exception_catch((System_Exception)THAT, typeof(TYPE))) { ACTION ; } goto __finally00; } while (0);

#define System_throw(EXCEPTION)  System_Exception_throw((System_Exception)EXCEPTION); return;

#define System_throw_return(EXCEPTION)  System_Exception_throw((System_Exception)EXCEPTION); return null;

#define System_rethrow(THAT)  System_Exception_throw((System_Exception)THAT); goto __finally00;

#define System_terminate(EXCEPTION)  System_Exception_terminate((System_Exception)EXCEPTION);

#define System_finally \
__finally00: ;

#define System_finally_void  if (inline_System_Exception_try()) return;

#define System_finally_return  if (inline_System_Exception_try()) return null;

#if defined(using_System)
#define try  System_try
#define try_throw  System_try_throw
#define catch  System_catch
#define catch_class  System_catch_class
#define throw  System_throw
#define throw_return  System_throw_return
#define rethrow  System_rethrow
#define terminate  System_terminate
#define finally  System_finally
#define finally_void  System_finally_void
#define finally_return  System_finally_return
#endif
#endif
