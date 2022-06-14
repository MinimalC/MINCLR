#define using_System
#include <min/System.h>

struct_string8  HALLOtxt = "./.FileNotFound";
/* struct_string8  HALLOtxt = "./.test.txt"; */

__main(test41_System_Exception, args) {

	/* Test00: Open .FileNotFound */
    __File file = __File_open(HALLOtxt, System_File_mode_readOnly);
    __try

    __Console_print("ERROR: System_Exception_get_current() is __null");

    __catch
    __catch_class(System_SystemException,exception, {
        __Console_print("SUCCESS: System_Exception_get_current():");
        __Console_print(" %s", __Object_get_Type(exception)->name->value);
        __Console_print(", error: %s (%llu)", __enum_getName(System_error, exception->error), exception->error);

        /* rethrow */
        System_Exception_throw((System_Exception)exception);
    })
    __finally
    __Console_printLineEmpty();

    __finally_return(__true)

    /* Test02: Close the File */
    if (file) __Object_freeClass(&file);

    return __false;
}
