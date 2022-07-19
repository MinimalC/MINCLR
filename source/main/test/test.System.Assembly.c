#define using_System
#include <min/System.h>

#if defined(have_AMD64)
STRING8  sharedObjectName = "/lib/x86_64-linux-gnu/libc.so.6";
#elif defined(have_ARM)
STRING8  sharedObjectName = "/lib/arm-linux-gnueabihf/libc.so.6";
#endif

STRING8  symbolName = "malloc";

//main(test47_System_Assembly, args) {
int main(int argc, char * argv[]) {

	/* Test00: open an Assembly */
    Assembly assembly = Assembly_open(sharedObjectName, AssemblyBinding_Now);

    if (!assembly) {
        Console_writeLine("Assembly NOT opened: {0:string}", 1, sharedObjectName);
        return false;
    }
    Console_writeLine("Assembly opened: {0:string}", 1, assembly->fileName);


	/* Test01: find a Symbol */
    void * symbolPtr = Assembly_find(assembly, symbolName);
    if (!symbolPtr) {
        Console_writeLine("Symbol NOT found: {0:string}", 1, symbolName);
        return false;
    }
    Console_writeLine("Symbol found: {0:string} at Address {1:uint}", 2, symbolName, symbolPtr);


	/* Test02: close the Assembly */
    Memory_free(assembly);

	return true;
}
