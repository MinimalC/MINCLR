#define using_System
#include <min/System.h>

struct_System_string8  string8_welt = "World";

struct_System_String welt = const_System_String__UTF8(string8_welt);

__main(test06_System_String, args) {

    /* Example 3 */
    __String www = &welt;

    if (args->length >= 2) {
        www = System_String_new( System_string8Array_get_index(args, 1) );
    }

    __Console_print("System_byteOrder_NATIVE: %0x\n", System_byteOrder_NATIVE);

    __Console_print("Hallo ");
    __Console_printString(www);
    __Console_print("! { { .Type = %s }, .CodePage = %llx, .Length = %llu }", 
        __Object_get_Type(www)->name->value, www->codepage, www->length);
    __Console_printLineEmpty();

    __Object_freeClass(&www);
    return __true;
}
