/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_Exception)
#define code_System_Exception

/* __thread */ System_Exception System_Exception_current = __null;

System_Exception  System_Exception_get_current() {
    return System_Exception_current;
}

System_void  System_Exception_set_current(System_Exception that) {

    if (System_Exception_current) inline_System_Object_freeClass(&System_Exception_current);

    System_Exception_current = (that == __null ? __null : (System_Exception)System_Object_addReference((System_Object)that));
}

System_void  System_Exception_throw(System_Exception that) {
    __assert(that)

    System_Exception_set_current(that);
}

System_void  System_Exception_terminate(System_Exception that) {
    __assert(that)

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

struct_System_String  STRING_System_Exception = const_System_String("System.Exception");

struct_System_Type_FunctionInfo  System_ExceptionTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Exception_init },
/*    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Exception_free }, */
};

struct_System_Type  System_ExceptionType = {
    .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_Exception,
    .size = sizeof(struct_System_Exception),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_ExceptionTypeFunctions), .value = &System_ExceptionTypeFunctions
    },
};

#endif
