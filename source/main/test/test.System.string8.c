#define using_System
#include <min/System.h>

struct_string8  prefix  = "main_";
struct_string8  command  = "./home/test01_System_string8";
struct_string8  final_name  = "main_test01_System_string8";
struct_string8  empty  = "";

//main(test01_System_string8, args){
int main(int argc, char * argv[]) {

    if (!string8_isNullOrEmpty(null) || !string8_isNullOrEmpty(empty) || string8_isNullOrEmpty(prefix))
        Console_writeLine__string8("Test00: ERROR: string8_isNullOrEmpty");
    else
        Console_writeLine__string8("Test00: SUCCESS: string8_isNullOrEmpty");


    size command_length = string8_get_Length(command);
    if (command_length != 28)
        Console_writeLine__string8("Test01: ERROR: string8_get_Length");
    else
        Console_writeLine__string8("Test01: SUCCESS: string8_get_Length");

    size  command_i0 = string8_indexOf(command, '/');
    if (command_i0 != 2)
        Console_writeLine("Test02: ERROR: string8_indexOf: {0:uint}", 1, command_i0);
    else
        Console_writeLine__string8("Test02: SUCCESS: string8_indexOf");

    size  command_i1 = string8_lastIndexOf(command, '/');
    if (command_i1 != 7)
        Console_writeLine__string8("Test03: ERROR: string8_lastIndexOf");
    else
        Console_writeLine__string8("Test03: SUCCESS: string8_lastIndexOf");

    size prefix_length = string8_get_Length(prefix);
    string8  name  = Memory_alloc(prefix_length + command_length + 1);
    string8_copySubstringTo(prefix, prefix_length, name);
    string8_copySubstringTo(command + command_i1, command_length, name + prefix_length);

    if (!string8_equals(name, final_name))
        Console_writeLine__string8("Test04: ERROR: string8_copySubstringTo");
    else
        Console_writeLine__string8("Test04: SUCCESS: string8_copySubstringTo");

    Memory_free((void**)&name);

    return true;
}
