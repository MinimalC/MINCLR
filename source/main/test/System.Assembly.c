#define using_System
#include <min/System.h>

#if defined(have_AMD64)
struct_string8  sharedObjectName = "/lib/x86_64-linux-gnu/libc.so.6";
#elif defined(have_ARM)
struct_string8  sharedObjectName = "/lib/arm-linux-gnueabihf/libc.so.6";
#endif

struct_string8  symbolName = "malloc";

__main(test47_System_Assembly, args) {

	/* Test00: open an Assembly */
    __Assembly assembly = __Assembly_open(sharedObjectName, __AssemblyBinding_Now);

    if (!assembly) {
        __Console_printLine("Assembly NOT opened: %s", sharedObjectName);
        return __false;
    }
    __Console_printLine("Assembly opened: %s", assembly->fileName);


	/* Test01: find a Symbol */
    void * symbolPtr = __Assembly_find(assembly, symbolName);
    if (!symbolPtr) {
        __Console_printLine("Symbol NOT found: %s", symbolName);
        return __false;
    }
    __Console_printLine("Symbol found: %s at Address %u", symbolName, symbolPtr);


	/* Test02: close the Assembly */
    __Object_freeClass(&assembly);

	return __true;
}
