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


typedef fixed struct System_Exception {
    struct System_Object base;

    System_Error error;

    System_String8  message;

}  * System_Exception;

export struct System_Type  System_ExceptionType;

#define stack_System_Exception(MESSAGE)  { .base = stack_System_Object(System_Exception), .message = MESSAGE }
#define stack_System_Exception__error(ERROR, MESSAGE)  { .base = stack_System_Object(System_Exception), .error = ERROR, .message = MESSAGE }
#define new_System_Exception(MESSAGE)  (base_System_Exception_init((System_Exception)System_Memory_allocClass(typeof(System_Exception)), MESSAGE))

typedef struct System_ReservedException {
    struct System_Exception base;

    System_Size __reserved[8];
} * System_ReservedException;

export thread struct System_ReservedException  System_Exception_current;

export thread System_Char8 System_Exception_message[System_String8_formatLimit_VALUE];

typedef System_Exception delegate(System_Exception_init)(System_Exception that, System_String8 message);
typedef void delegate(System_Exception_free)(System_Exception that);

export void  System_Exception_throw(System_Exception that);
export void  System_Exception_terminate(System_Exception that) noreturn;
export System_Bool  stack_System_Exception_catch(System_Exception that, System_Type type);

export System_Exception  base_System_Exception_init(System_Exception that, System_String8 message);
/* export void  base_System_Exception_free(System_Exception that); */

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


#define try  if (System_Exception_current.base.base.type) goto __catch00;

#define catch  if (!System_Exception_current.base.base.type) goto __finally00;\
__catch00: ;

#define catch_class(TYPE,THAT,ACTION)  do { struct TYPE ff(struct,THAT) = { 0 }; TYPE THAT = &ff(struct,THAT); if (stack_System_Exception_catch((System_Exception)THAT, typeof(TYPE))) { ACTION } goto __finally00; } while (0);

#define throw(EXCEPTION)  System_Exception_throw((System_Exception)EXCEPTION); return;

#define throw_return(EXCEPTION)  System_Exception_throw((System_Exception)EXCEPTION); return null;

#define rethrow(THAT)  System_Exception_throw((System_Exception)THAT); goto __finally00;

#define terminate(EXCEPTION)  System_Exception_terminate((System_Exception)EXCEPTION);

#define finally  \
__finally00: ;

#define finally_void  if (System_Exception_current.base.base.type) return;

#define finally_return  if (System_Exception_current.base.base.type) return null;

#endif
