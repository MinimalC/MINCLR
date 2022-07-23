#define using_System
#include <min/System.h>

STRING8  HALLOtxt = "./.FileNotFound";
/* STRING8  HALLOtxt = "./.test.txt"; */

//main(test41_System_Exception, args) {
int main(int argc, char * argv[]) {

	/* Test00: Open .FileNotFound */
    File file = File_open(HALLOtxt, System_File_Mode_readOnly);
    try

    Console_write__string("ERROR: try isn't");

    catch
    catch_class(System_Exception,exception, {

        Console_writeLine("SUCCESS: catch_class {0:string}, error: {1:string} ({2:uint})", 3, exception->base.type->name, enum_getName(typeof(System_Error), exception->error), exception->error);

        /* rethrow(exception); */
    })
    finally
    Console_writeLineEmpty();
    finally_return

    /* Test02: Close the File */
    if (file) Memory_free(file);

    return true;
}
