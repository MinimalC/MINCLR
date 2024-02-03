/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_ErrorCode)
#include "System.ErrorCode.h"
#endif
#if !defined(have_System_String8)
#include "System.String8.h"
#endif
#if !defined(have_System_Exception)
#define have_System_Exception

typedef System_fixed struct System_Exception {
    struct System_Object base;

    System_ErrorCode error;

    System_String8  message;

}  * System_Exception;

export struct System_Type  System_ExceptionType;
export struct System_Type  System_IOExceptionType;
export struct System_Type  System_NotSupportedExceptionType;
export struct System_Type  System_NotImplementedExceptionType;
export struct System_Type  System_ArgumentExceptionType;
export struct System_Type  System_InvalidExceptionType;

export System_Exception  System_Exception_current;

typedef void delegate(System_Exception_init)(System_Exception that, System_String8 message);

export void  base_System_Exception_init(System_Exception that, System_String8 message);
export void  base_System_Exception_free(System_Exception that);
export void  System_Exception_throw(System_Exception that);
export void  System_Exception_terminate(System_Exception that) noreturn;
export System_Bool  System_Exception_catch(System_Exception * that, System_Type type);
export System_Bool  System_Exception_catch__any(System_Exception * that, System_Type type, System_Bool any);

export System_Exception  new_System_Exception(System_String8 message);
export System_Exception  new_System_IOException(System_String8 message);
export System_Exception  new_System_NotSupportedException(System_String8 message);
export System_Exception  new_System_NotImplementedException(System_String8 message);
export System_Exception  new_System_ArgumentException(System_String8 message);
export System_Exception  new_System_InvalidException(System_String8 message);

#define System_Exception_init(o,...)  ((function_System_Exception_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Exception_init))(o, __VA_ARGS__)
#define System_Exception_free(o)  ((function_System_Exception_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_System)
#if !defined(System_internal)
#endif
#define Exception  System_Exception
#define ExceptionType  System_ExceptionType
#define new_Exception  new_System_Exception

#define Exception_throw  System_Exception_throw
#define Exception_terminate  System_Exception_terminate
#define Exception_catch  System_Exception_catch

#define function_Exception_init  function_System_Exception_init
#define function_Exception_free  function_System_Exception_free
#define base_Exception_init  base_System_Exception_init
#define base_Exception_free  base_System_Exception_free
#define Exception_init  System_Exception_init
#define Exception_free  System_Exception_free
#endif
#endif
