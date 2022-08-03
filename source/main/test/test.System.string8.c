#define using_System
#include <min/System.h>

STRING8  prefix  = "main_";
STRING8  command  = "./home/test01_System_String8";
STRING8  final_name  = "main_test01_System_String8";
STRING8  empty  = "";

#define main  System_Runtime_main

//main(test01_System_String8, args){
int main(int argc, char * argv[]) {

    if (!String8_isNullOrEmpty(null) || !String8_isNullOrEmpty(empty) || String8_isNullOrEmpty(prefix))
        Console_writeLine__string("Test00: ERROR: String8_isNullOrEmpty");
    else
        Console_writeLine__string("Test00: SUCCESS: String8_isNullOrEmpty");


    Size command_length = String8_get_Length(command);
    if (command_length != 28)
        Console_writeLine__string("Test01: ERROR: String8_get_Length");
    else
        Console_writeLine__string("Test01: SUCCESS: String8_get_Length");

    Size  command_i0 = String8_indexOf(command, '/');
    if (command_i0 != 2)
        Console_writeLine("Test02: ERROR: String8_indexOf: {0:uint}", 1, command_i0);
    else
        Console_writeLine__string("Test02: SUCCESS: String8_indexOf");

    Size  command_i1 = String8_lastIndexOf(command, '/');
    if (command_i1 != 7)
        Console_writeLine__string("Test03: ERROR: String8_lastIndexOf");
    else
        Console_writeLine__string("Test03: SUCCESS: String8_lastIndexOf");

    Size prefix_length = String8_get_Length(prefix);
    String8  name  = Memory_allocArray(typeof(System_Char8), prefix_length + command_length + 1);
    String8_copySubstringTo(prefix, prefix_length, name);
    String8_copySubstringTo(command + command_i1, command_length, name + prefix_length);

    if (!String8_equals(name, final_name))
        Console_writeLine__string("Test04: ERROR: String8_copySubstringTo");
    else
        Console_writeLine__string("Test04: SUCCESS: String8_copySubstringTo");

    Memory_free(name);

    return true;
}
