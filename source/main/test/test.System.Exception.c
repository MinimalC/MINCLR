#define using_System
#include <min/System.h>

STRING8  HALLOtxt = "./.FileNotFound";
/* STRING8  HALLOtxt = "./.test.txt"; */

//main(test41_System_Exception, args) {
int main(int argc, char * argv[]) {

	/* Test00: Open .FileNotFound */
    File file = File_open(HALLOtxt, System_File_Mode_readOnly);
    try

    Console_write__String8_size("ERROR: System_Exception_get_current() is null");

    catch
    catch_class(System_Exception,exception, {
        Console_write__String8_size("SUCCESS: System_Exception_get_current():");
        Console_write(" {0:string}", 1, Object_get_Type((Object)exception)->name);
        Console_write(", error: {0:string} ({1:uint})", 2, enum_getName(typeof(System_Error), exception->error), exception->error);

        /* rethrow */
        System_Exception_throw(exception);
    })
    finally
    Console_writeLineEmpty();

    finally_return(true)

    /* Test02: Close the File */
    if (file) Memory_free(file);

    return false;
}
