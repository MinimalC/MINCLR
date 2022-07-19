#define using_System
#include <min/System.h>

internal size  Test00_size = 8;
internal uint8  Test00_Check[] = "\x01\x01\x03\x01\x01\x01\x01\x01";

//main(test00_System_Memory, args) {
int main(int argc, char * argv[]) {
    // uint8 *arg1; size arg1size;
    /* if (argc == 1) is unnecessary: arg[0] is always the Application_Path, for example /home/user007/bin/MetaFrame */
    // if (argc > 2) { arg1 = argv[1]; arg1size = sizeof(argv[1]); }


    /* Test: Memory_allocClass */
    uint8 *bytes = Memory_allocClass(typeof(uint8), Test00_size);
    if (!bytes)
        Console_writeLine__string8("Test01: ERROR: System_Memory_allocClass");
    else
        Console_writeLine__string8("Test01: SUCCESS: System_Memory_allocClass");


    /* Test: Memory_set */
    Memory_set(bytes, 0x01, Test00_size);
    // *(bytes + 2) = 0x03;
    bytes[2] = 0x03;


    /* Test: Memory_compare and Memory_equals  */
    if (0 != Memory_compare(bytes, Test00_Check, Test00_size))
        Console_writeLine__string8("Test02: ERROR: System_Memory_compare");
    else
        Console_writeLine__string8("Test02: SUCCESS: System_Memory_compare");

    if (!Memory_equals(bytes, Test00_Check, Test00_size))
        Console_writeLine__string8("Test03: ERROR: System_Memory_equals");
    else
        Console_writeLine__string8("Test03: SUCCESS: System_Memory_equals");


    /* Test: Memory_indexOf */
    size indexOf2 = Memory_indexOf(bytes, 0x03, Test00_size);
    if (indexOf2 != 3)
        Console_writeLine__string8("Test04: ERROR: System_Memory_indexOf");
    else
        Console_writeLine__string8("Test04: SUCCESS: System_Memory_indexOf");


    /* Test: Memory_free */
    Memory_free(bytes);
    if (bytes)
        Console_writeLine__string8("Test05: ERROR: System_Memory_free");
    else
        Console_writeLine__string8("Test05: SUCCESS: System_Memory_free");


    return true;
}
