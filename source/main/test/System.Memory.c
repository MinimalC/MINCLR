#define using_System
#include <min/System.h>

__private __size  Test00_size = 8;
__private __uint8  Test00_Check[] = "\x01\x01\x03\x01\x01\x01\x01\x01";

__main(test00_System_Memory, args) {
    // __uint8 *arg1; __size arg1size;
    /* if (argc == 1) is unnecessary: arg[0] is always the Application_Path, for example /home/user007/bin/MetaFrame */
    // if (argc > 2) { arg1 = argv[1]; arg1size = sizeof(argv[1]); }


    /* Test: Memory_alloc */
    __uint8 *bytes = __Memory_alloc(Test00_size);
    if (!bytes)
        __Console_printLine("Test01: ERROR: System_Memory_alloc");
    else
        __Console_printLine("Test01: SUCCESS: System_Memory_alloc");


    /* Test: Memory_set */
    __Memory_set(bytes, 0x01, Test00_size);
    // *(bytes + 2) = 0x03;
    bytes[2] = 0x03;


    /* Test: Memory_compare and Memory_equals  */
    if (0 != __Memory_compare(bytes, Test00_Check, Test00_size))
        __Console_printLine("Test02: ERROR: System_Memory_compare");
    else
        __Console_printLine("Test02: SUCCESS: System_Memory_compare");

    if (!__Memory_equals(bytes, Test00_Check, Test00_size))
        __Console_printLine("Test03: ERROR: System_Memory_equals");
    else
        __Console_printLine("Test03: SUCCESS: System_Memory_equals");


    /* Test: Memory_indexOf */
    __size indexOf2 = __Memory_indexOf(bytes, 0x03, Test00_size);
    if (indexOf2 != 3)
        __Console_printLine("Test04: ERROR: System_Memory_indexOf");
    else
        __Console_printLine("Test04: SUCCESS: System_Memory_indexOf");


    /* Test: Memory_free */
    __Memory_free((void **)&bytes);
    if (bytes)
        __Console_printLine("Test05: ERROR: System_Memory_free");
    else
        __Console_printLine("Test05: SUCCESS: System_Memory_free");


    return __true;
}
