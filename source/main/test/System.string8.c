#define using_System
#include <min/System.h>

struct_string8  prefix  = "main_";
struct_string8  command  = "./home/test01_System_string8";
struct_string8  final_name  = "main_test01_System_string8";
struct_string8  empty  = "";

__main(test01_System_string8, args){

    if (!__string8_isNullOrEmpty(__null) || !__string8_isNullOrEmpty(empty) || __string8_isNullOrEmpty(prefix))
        __Console_printLine("Test00: ERROR: __string8_isNullOrEmpty");
    else
        __Console_printLine("Test00: SUCCESS: __string8_isNullOrEmpty");


    __size command_length = __string8_get_Length(command);
    if (command_length != 28)
        __Console_printLine("Test01: ERROR: __string8_get_Length");
    else
        __Console_printLine("Test01: SUCCESS: __string8_get_Length");

    __size  command_i0 = __string8_indexOf(command, '/');
    if (command_i0 != 2)
        __Console_printLine("Test02: ERROR: __string8_indexOf: %llu", command_i0);
    else
        __Console_printLine("Test02: SUCCESS: __string8_indexOf");

    __size  command_i1 = __string8_lastIndexOf(command, '/');
    if (command_i1 != 7)
        __Console_printLine("Test03: ERROR: __string8_lastIndexOf");
    else
        __Console_printLine("Test03: SUCCESS: __string8_lastIndexOf");

    __size prefix_length = __string8_get_Length(prefix);
    __string8  name  = __Memory_alloc(prefix_length + command_length + 1); 
    __string8_copySubstringTo(prefix, prefix_length, name);
    __string8_copySubstringTo(command + command_i1, command_length, name + prefix_length);
 
    if (!__string8_equals(name, final_name))
        __Console_printLine("Test04: ERROR: __string8_copySubstringTo");
    else
        __Console_printLine("Test04: SUCCESS: __string8_copySubstringTo");

    __Memory_free((void**)&name);

    return __true;
}
