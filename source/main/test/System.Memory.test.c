#define using_System
#include <min/System.h>

Size  Test00_size = 8;
UInt8  Test00_Check[] = "\x01\x01\x02\x01\x01\x05\x01\x01";

Char8 MoveTo[]   = "HalloWelt ";
Char8 MoveFrom[] = "HelloWorld";

STRING8 runtime_memory0 = "FFFFEEEEDDDDCCCCBBBBAAAA9999888877776666555544443333222211110000";

STRING8 runtime_memory1 = "0000111122223333444455556666777788889999AAAABBBBCCCCDDDDEEEEFFFF";

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
    Memory_set(bytes, Test00_size, 0x01);
    bytes[2] = 0x02;
    bytes[5] = 0x05;

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
    SSize indexOf2 = Memory_indexOf(bytes, Test00_size, 0x02);
    if (indexOf2 != 2)
        Console_writeLine__string("Test04: ERROR: System_Memory_indexOf");
    else
        Console_writeLine__string("Test04: SUCCESS: System_Memory_indexOf");

    /* Test: Memory_indexOf */
    SSize indexOf5 = Memory_indexOf__other(bytes, Test00_size, "\x05\x01", 2);
    if (indexOf5 != 5)
        Console_writeLine__string("Test04: ERROR: System_Memory_indexOf__other");
    else
        Console_writeLine__string("Test04: SUCCESS: System_Memory_indexOf__other");


    /* Test: Memory_free */
    Memory_free(bytes);
    if (bytes)
        Console_writeLine__string("Test05: ERROR: System_Memory_free");
    else
        Console_writeLine__string("Test05: SUCCESS: System_Memory_free");


    /* Test: Memory_moveTo */
    Memory_moveTo(MoveFrom, sizeof(MoveFrom), MoveTo);
    if (!String8_equals("HalloWelt ", MoveFrom) && !String8_equals("HelloWorld", MoveTo))
        Console_writeLine__string("Test06: ERROR: System_Memory_moveTo");
    else
        Console_writeLine__string("Test06: SUCCESS: System_Memory_moveTo");

    /* Test: Memory_moveTo */
    Memory_moveTo(MoveTo, sizeof(MoveTo), MoveFrom);
    if (!String8_equals("HalloWelt ", MoveTo) && !String8_equals("HelloWorld", MoveFrom))
        Console_writeLine__string("Test07: ERROR: System_Memory_moveTo");
    else
        Console_writeLine__string("Test07: SUCCESS: System_Memory_moveTo");


    System_Memory_sort(runtime_memory0, 16, 4, &System_Memory_alphacompare);
    if (!String8_equals("0000111122223333444455556666777788889999AAAABBBBCCCCDDDDEEEEFFFF", runtime_memory0))
        Console_writeLine("Test08: ERROR: System_Memory_sort ascending {0:string}", 1, runtime_memory0);
    else
        Console_writeLine("Test08: SUCCESS: System_Memory_sort ascending {0:string}", 1, runtime_memory0);

    System_Memory_sort(runtime_memory1, 16, 4, &System_Memory_alphacomparedescending);
    if (!String8_equals("FFFFEEEEDDDDCCCCBBBBAAAA9999888877776666555544443333222211110000", runtime_memory1))
        Console_writeLine("Test09: ERROR: System_Memory_sort descending {0:string}", 1, runtime_memory1);
    else
        Console_writeLine("Test09: SUCCESS: System_Memory_sort descending {0:string}", 1, runtime_memory1);

    String8 realloc_memory = Memory_allocArray(typeof(Char8), 17);
    for (Size c = 0; c < 16; ++c) realloc_memory[c] = 'A';
    Memory_reallocArray((System_Var ref)&realloc_memory, 33);
    for (Size c = 16; c < 32; ++c) realloc_memory[c] = 'B';
    Memory_reallocArray((System_Var ref)&realloc_memory, 49);
    for (Size c = 32; c < 48; ++c) realloc_memory[c] = 'C';
    Memory_reallocArray((System_Var ref)&realloc_memory, 65);
    for (Size c = 48; c < 64; ++c) realloc_memory[c] = 'D';
    Memory_reallocArray((System_Var ref)&realloc_memory, 81);
    for (Size c = 64; c < 80; ++c) realloc_memory[c] = 'E';
    Memory_reallocArray((System_Var ref)&realloc_memory, 97);
    for (Size c = 80; c < 96; ++c) realloc_memory[c] = 'F';
    if (!System_String8_equals("AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEEEEEEEEFFFFFFFFFFFFFFFF", realloc_memory))
        Console_writeLine("Test10: ERROR: System_Memory_reallocArray {0:string}", 1, realloc_memory);
    else
        Console_writeLine("Test10: SUCCESS: System_Memory_reallocArray {0:string}", 1, realloc_memory);
    Memory_free(realloc_memory);

    return true;
}
