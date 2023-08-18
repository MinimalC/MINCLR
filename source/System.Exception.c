/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
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

/*typedef struct System_ReservedException {
    struct System_Exception base;

    System_Size __reserved[8];
} * System_ReservedException;

thread struct System_ReservedException System_ReservedException_current;*/

thread System_Exception System_Exception_current = null;

//thread System_Char8 System_Exception_message[4096] = "";

Bool  System_Exception_try() {
    return (System_Exception_current && System_Exception_current->base.type) ? true : false;
}

Bool  System_Exception_tryNot() {
    return (!System_Exception_current || !System_Exception_current->base.type) ? true : false;
}

void  System_Exception_throw(System_Exception that) {
    Debug_assert(that);

    System_Exception_current = that;

#if DEBUG
    Type type = that->base.type;
    if (!type) type = typeof(System_Exception);

    if (that->message && that->error)
        Console_writeLine("throws {0:string}: error {1:uint} ({2:string}): {3:string}", 4, type->name, that->error, enum_getName(typeof(System_ErrorCode), that->error), that->message);
    else if (that->message)
        Console_writeLine("throws {0:string}: {1:string}", 2, type->name, that->message);
    else if (that->error)
        Console_writeLine("throws {0:string}: error {1:uint} ({2:string})", 3, type->name, that->error, enum_getName(typeof(System_ErrorCode), that->error));
    else
        Console_writeLine("throws {0:string}", 1, type->name);
#endif
}

void  System_Exception_terminate(System_Exception that) {
    Debug_assert(that);
#if DEBUG
    System_Console_write__string("TERMINIERT: ");
#endif
    System_Exception_throw(that);

    System_Syscall_terminate(false);
}

Bool  stack_System_Exception_catch(System_Exception * that, System_Type type) {
    Debug_assert(that);
    Debug_assert(type);
    
    if (!System_Exception_current) return false;

    if (!System_Type_isAssignableFrom(System_Exception_current->base.type, type)) return false;
        
    *that = System_Exception_current;
    System_Exception_current = null;
    return true;    
}

System_Exception  base_System_Exception_init(System_Exception that, System_String8 message) {
    base_System_Object_init((System_Object)that);

    that->message = message;
    return that;
}

/* void  base_System_Exception_free(System_Exception that) {

    base_System_Object_free((System_Object)that);
} */

struct System_Type_FunctionInfo  System_ExceptionTypeFunctions[] = {
    [0] = { .function = base_System_Exception_init, .value = base_System_Exception_init },
/*    [1] = { .function = base_System_Object_free, .value = base_System_Exception_free }, */
};

struct System_Type System_ExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "Exception",
    .size = sizeof(struct System_Exception),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_ExceptionTypeFunctions), .value = &System_ExceptionTypeFunctions
    },
};

#endif
