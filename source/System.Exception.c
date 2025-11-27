/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(code_System_Exception)
#define code_System_Exception

/** struct System_Exception **/

export thread System_Exception System_Exception_current = null;

void  System_Exception_print(System_Exception that) {
    if (!that) return;
    Type type = that->base.type;
    if (!type) return;

    if (that->message && that->error)
        Console_writeLine("throws {0:string}: error {2:string}({1:uint}): {3:string}", 4, type->name, that->error, enum_getName(typeof(System_ErrorCode), that->error), that->message);
    else if (that->message)
        Console_writeLine("throws {0:string}: {1:string}", 2, type->name, that->message);
    else if (that->error)
        Console_writeLine("throws {0:string}: error {2:string}({1:uint})", 3, type->name, that->error, enum_getName(typeof(System_ErrorCode), that->error));
    else
        Console_writeLine("throws {0:string}", 1, type->name);
}

/** function System_Exception_throw 
    Throws a System_Exception.
**/
void  System_Exception_throw(System_Exception that) {
    Console_assert(that);

    if (System_Exception_current) 
        System_Memory_free(System_Exception_current);

    System_Exception_current = that;

#if DEBUG == DEBUG_System_Exception
    System_Exception_print(that);
#endif
}

/** function System_Exception_terminate
    Throws a System_Exception, before terminating the process.
**/
void  System_Exception_terminate(System_Exception that) {
    Console_assert(that);

#if DEBUG
    System_Console_write__string("TERMINIERT: ");
#endif
#if DEBUG && DEBUG != DEBUG_System_Exception
    System_Exception_print(that);
#endif
    System_Memory_cleanup__threadId(System_Thread_TID);
    System_Syscall_terminate(false);
}

/** function System_Exception_catch 
    Catches a System_Exception of type.
    argument System_Exception * that
    argument System_Type type
    Returns true, if there is a System_Exception, false if not.
**/
Bool  System_Exception_catch(System_Exception ref that, System_Type type) {
    return System_Exception_catch__any(that, type, false);
}

/** function System_Exception_catch__any
    Catches any System_Exception.
    argument System_Exception * that
    argument System_Type type
    argument System_Bool any
    Returns true, if there is a System_Exception, false if not.
**/
Bool  System_Exception_catch__any(System_Exception ref that, System_Type type, System_Bool any) {
    Console_assert(that);
    Console_assert(type);
    
    if (!System_Exception_current) return false;

    Type exceptionType = System_Exception_current->base.type;

    if (!any && !System_Type_isAssignableFrom(exceptionType, type)) return false;

    System_Exception exception = *that = System_Exception_current;
    System_Exception_current = null;

#if DEBUG == DEBUG_System_Exception
    if (exception->message && exception->error)
        Console_writeLine("catches {0:string}: error {2:string}({1:uint}): {3:string}", 4, exceptionType->name, exception->error, enum_getName(typeof(System_ErrorCode), exception->error), exception->message);
    else if (exception->message)
        Console_writeLine("catches {0:string}: {1:string}", 2, exceptionType->name, exception->message);
    else if (exception->error)
        Console_writeLine("catches {0:string}: error {2:string}({1:uint})", 3, exceptionType->name, exception->error, enum_getName(typeof(System_ErrorCode), exception->error));
    else
        Console_writeLine("catches {0:string}", 1, exceptionType->name);
#endif
    return true;    
}

/** function new_System_Exception
    Creates a new System_Exception with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_Exception(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_Exception));
    base_System_Exception_init(that, message);
    return that;
}

/** function base_System_Exception_init
    Initializes new System_Exception with a message.
    argument System_Exception that
    argument System_String8 message
**/
void  base_System_Exception_init(System_Exception that, System_String8 message) {
    that->message = message;
}

/** function base_System_Exception_free
    Free the message.
    argument System_Exception that
**/
void  base_System_Exception_free(System_Exception that) {
    System_Memory_free(that->message);
}

struct System_Type_FunctionInfo  System_ExceptionTypeFunctions[] = {
    { .function = base_System_Exception_init, .value = base_System_Exception_init },
    { .function = base_System_Object_free, .value = base_System_Exception_free },
};

struct System_Type System_ExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "Exception",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Object),
    .functions = { .length = sizeof_array(System_ExceptionTypeFunctions), .value = &System_ExceptionTypeFunctions },
};

struct System_Type System_IOExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "IOException",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Exception),
};

/** function new_System_IOException
    Creates a new System_IOException with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_IOException(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_IOException));
    base_System_Exception_init(that, message);
    return that;
}

/** function new_System_IOException__error
    Creates a new System_IOException with the ErrorCode and a message.
    argument System_ErrorCode error
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_IOException__error(System_ErrorCode error, System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_IOException));
    base_System_Exception_init(that, message);
    that->error = error;
    return that;
}

struct System_Type System_NotSupportedExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "NotSupportedException",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Exception),
};

/** function new_System_NotSupportedException
    Creates a new System_NotSupportedException with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_NotSupportedException(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_NotSupportedException));
    base_System_Exception_init(that, message);
    return that;
}

struct System_Type System_NotImplementedExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "NotImplementedException",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Exception),
};

/** function new_System_NotImplementedException
    Creates a new System_NotImplementedException with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_NotImplementedException(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_NotImplementedException));
    base_System_Exception_init(that, message);
    return that;
}

struct System_Type System_ArgumentExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "ArgumentException",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Exception),
};

/** function new_System_ArgumentException
    Creates a new System_ArgumentException with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_ArgumentException(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_ArgumentException));
    base_System_Exception_init(that, message);
    return that;
}

struct System_Type System_InvalidExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "InvalidException",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Exception),
};

/** function new_System_InvalidException
    Creates a new System_InvalidException with a message.
    argument System_String8 message
    Returns the System_Exception.
**/
System_Exception  new_System_InvalidException(System_String8 message) {
    System_Exception that = (System_Exception)System_Memory_allocClass(typeof(System_InvalidException));
    base_System_Exception_init(that, message);
    return that;
}

#endif
