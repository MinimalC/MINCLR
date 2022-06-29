#define using_System
#include <min/System.h>

struct_string8  HALLOtxt = "./.FileNotFound";
/* struct_string8  HALLOtxt = "./.test.txt"; */

//main(test41_System_Exception, args) {
int main(int argc, char * argv[]) {

	/* Test00: Open .FileNotFound */
    File file = File_open(HALLOtxt, System_File_mode_readOnly);
    try

    Console_write__string8("ERROR: System_Exception_get_current() is null");

    catch
    catch_class(System_SystemException,exception, {
        Console_write__string8("SUCCESS: System_Exception_get_current():");
        Console_write(" {0:string}", 1, Object_get_Type(exception)->name->value);
        Console_write(", error: {0:string} ({1:uint64})", 2, enum_getName(System_error, exception->error), exception->error);

        /* rethrow */
        System_Exception_throw((System_Exception)exception);
    })
    finally
    Console_writeLineEmpty();

    finally_return(true)

    /* Test02: Close the File */
    if (file) Object_freeClass(&file);

    return false;
}
