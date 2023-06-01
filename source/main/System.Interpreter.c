/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "../System.internal.h"
#endif
#include <min/System.h>

int System_Runtime_main(int argc, char  * argv[]) {

    if (System_String8_endsWith(argv[0], "System.Interpreter")) {
        if (argc == 1) {
            System_Console_writeLine__string("Usage: System.Interpreter filename");
            return false; 
        }

        System_Console_writeLine__string("This is System.Interpreter as command");
        return true;
    }

    System_Console_writeLine__string("This is System.Interpreter as INTERP");
    return true;
}