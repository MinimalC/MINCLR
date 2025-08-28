#define using_System
#include <min/System.h>

STRING8  prefix  = "main_";
STRING8  name  = "test01_System_String8";
STRING8  final_name  = "main_test01_System_String8";
STRING8  command  = "./home/test01_System_String8";
STRING8  empty  = " \t";

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

    SSize  command_i0 = String8_indexOf__char(command, '/');
    if (command_i0 != 1)
        Console_writeLine__string("Test02: ERROR: String8_indexOf__char");
    else
        Console_writeLine__string("Test02: SUCCESS: String8_indexOf__char");

    SSize  command_i1 = String8_indexOf(command, "test01");
    if (command_i1 != 7)
        Console_writeLine__string("Test03: ERROR: String8_indexOf");
    else
        Console_writeLine__string("Test03: SUCCESS: String8_indexOf");

    SSize  command_i2 = String8_lastIndexOf__char(command, '/');
    if (command_i2 != 6)
        Console_writeLine__string("Test04: ERROR: String8_lastIndexOf__char");
    else
        Console_writeLine__string("Test04: SUCCESS: String8_lastIndexOf__char");

    SSize  command_i3 = String8_lastIndexOf(command, "System");
    if (command_i3 != 14)
        Console_writeLine__string("Test05: ERROR: String8_lastIndexOf");
    else
        Console_writeLine__string("Test05: SUCCESS: String8_lastIndexOf");

    String8 prefix_name = System_String8_concat2(prefix, name);
    if (!String8_equals(prefix_name, final_name))
        Console_writeLine("Test06: ERROR: String8_concat2: {0:string}", 1, prefix_name);
    else
        Console_writeLine__string("Test06: SUCCESS: String8_concat2");
    Memory_free(prefix_name);

    String8 concatN = System_String8_concat("main", 6, "_", "test01", "_", "System", "_", "String8");
    if (!String8_equals(concatN, final_name))
        Console_writeLine("Test07: ERROR: String8_concatN: {0:string}", 1, concatN);
    else
        Console_writeLine__string("Test07: SUCCESS: String8_concat__arguments");
    Memory_free(concatN);

    return true;
}
