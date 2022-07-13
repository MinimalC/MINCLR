/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(code_System_Exception)
#define code_System_Exception

struct_System_Type_FunctionInfo  System_ExceptionTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Exception_init, .value = base_System_Exception_init },
/*    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Exception_free }, */
};

struct_System_Type  System_ExceptionType = {
    .base = { .type = typeof(System_Type) },
    .name = "System.Exception",
    .size = sizeof(struct_System_Exception),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ExceptionTypeFunctions), .value = &System_ExceptionTypeFunctions
    },
};

/* thread */ System_Exception System_Exception_current = null;

System_Exception  System_Exception_get_current() {
    return System_Exception_current;
}

void  System_Exception_set_current(System_Exception that) {

    if (System_Exception_current) inline_System_Object_freeClass(&System_Exception_current);

    System_Exception_current = (that == null ? null : (System_Exception)System_Object_addReference((System_Object)that));
}

void  System_Exception_throw(System_Exception that) {
    assert(that)

    // TODO: Memory_copyTo(that, sizeof(struct_System_Exception), &System_Exception_current)
    System_Exception_set_current(that);
}

void  System_Exception_terminate(System_Exception that) {
    assert(that)

    System_Exception_throw(that);
    System_Console_terminate(0);
}

System_Exception  System_Exception_new(System_string8 message) {
    return inline_System_Exception_new(message);
}

System_Exception  base_System_Exception_init(System_Exception that, System_string8 message) {
    base_System_Object_init((System_Object)that);

    that->message = message;
    return that;
}

/* void  base_System_Exception_free(System_Exception that) {

    base_System_Object_free((System_Object)that);
} */

#endif
