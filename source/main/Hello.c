#define using_System
#include <min/System.h>

Size Hello(Size argc, String8 argv[]) {

    if (argc > 1) {
        Console_writeLine("Hello {0:string}!", 1, argv[1]);
        return true;
    }

    Console_writeLine__string("Hello World!");
    return false;
}