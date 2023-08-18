#define using_System
#include <min/System.h>

Size  Test00_size = 8;
UInt8  Test00_Check[] = "\x01\x01\x03\x01\x01\x01\x01\x01";

int System_Runtime_main(int argc, char * argv[]) {

    /* Test: Memory_allocClass */
    UInt8 *bytes = Memory_allocArray(typeof(UInt8), Test00_size);
    if (!bytes)
        Console_writeLine__string("Test01: ERROR: System_Memory_allocClass");
    else
        Console_writeLine__string("Test01: SUCCESS: System_Memory_allocClass");

    if (!System_Memory_isAllocated((Var)bytes))
        Console_writeLine__string("Test01: ERROR: System_Memory_isAllocated");
    else
        Console_writeLine__string("Test01: SUCCESS: System_Memory_isAllocated");

    /* Test: Memory_set */
    Memory_set(bytes, 0x01, Test00_size);
    // *(bytes + 2) = 0x03;
    bytes[2] = 0x03;

    /* Test: Memory_compare and Memory_equals  */
    if (Test00_size != Memory_compare(bytes, Test00_Check, Test00_size))
        Console_writeLine__string("Test02: ERROR: System_Memory_compare");
    else
        Console_writeLine__string("Test02: SUCCESS: System_Memory_compare");

    if (!Memory_equals(bytes, Test00_Check, Test00_size))
        Console_writeLine__string("Test03: ERROR: System_Memory_equals");
    else
        Console_writeLine__string("Test03: SUCCESS: System_Memory_equals");


    /* Test: Memory_indexOf */
    Size indexOf2 = Memory_indexOf(bytes, 0x03, Test00_size);
    if (indexOf2 != 3)
        Console_writeLine__string("Test04: ERROR: System_Memory_indexOf");
    else
        Console_writeLine__string("Test04: SUCCESS: System_Memory_indexOf");


    /* Test: Memory_free */
    Memory_free(bytes);
    if (bytes)
        Console_writeLine__string("Test05: ERROR: System_Memory_free");
    else
        Console_writeLine__string("Test05: SUCCESS: System_Memory_free");


    return true;
}
