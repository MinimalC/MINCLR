#define using_System
#include <min/System.h>

STRING8  prefix  = "main_";
STRING8  name  = "test01_System_String8";
STRING8  final_name  = "main_test01_System_String8";
STRING8  command  = "./home/test01_System_String8";
STRING8  empty  = "";

int System_Runtime_main(int argc, char * argv[]) {

    if (String8_isNullOrEmpty(null) && String8_isNullOrEmpty(empty) && !String8_isNullOrEmpty(prefix))
        Console_writeLine__string("Test00: SUCCESS: String8_isNullOrEmpty");
    else
        Console_writeLine__string("Test00: ERROR: String8_isNullOrEmpty");


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

    String8 prefix_name = System_String8_concat(prefix, name);
    if (!String8_equals(prefix_name, final_name))
        Console_writeLine("Test04: ERROR: String8_concat: {0:string}", 1, prefix_name);
    else
        Console_writeLine__string("Test04: SUCCESS: String8_concat");
    Memory_free(prefix_name);


    String8  command_directory = System_Path_getDirectoryName(command);
    if (!command_directory)
        Console_writeLine__string("Test05: ERROR: Path_getDirectoryName");
    else {
        Console_writeLine("Test05: SUCCESS: Path_getDirectoryName: {0:string}", 1, command_directory);
        Memory_free(command_directory);
    }

    String8  command_filename = System_Path_getFileName(command);
    if (!command_filename)
        Console_writeLine__string("Test06: ERROR: Path_getDirectoryName");
    else {
        Console_writeLine("Test06: SUCCESS: Path_getFileName: {0:string}", 1, command_filename);
        Memory_free(command_filename);
    }

    return true;
}
