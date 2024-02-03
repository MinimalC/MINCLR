#define using_System
#include <min/System.h>

STRING8  HALLOtxt = ".FileNotFound";

Bool main_try() {

	/* Test00: Open .FileNotFound */
    File file = File_open(HALLOtxt, System_File_Mode_readOnly);

    System_Exception exception = null;
    if (System_Exception_catch(&exception, typeof(System_IOException))) {
        Console_writeLine("SUCCESS: catch {0:string}", 1, exception->base.type->name);
    }
    Console_writeLine__string("This is finally.");
    /* Test02: Close the File */
    if (file) Memory_free(file);
    if (exception) {
        /* rethrow, just to see TERMINATED */
        System_Exception_throw(exception);
        return false;
    }

    Console_writeLine__string("ERROR: You should NOT see this.");

    return true;
}

int System_Runtime_main(int argc, char * argv[]) {

    Bool reture = main_try();
    Console_writeLine("{0:string}: returning {1:bool}", 2, reture ? "FAIL" : "SUCCESS", reture);
    return reture;
}