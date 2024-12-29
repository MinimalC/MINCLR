#define using_System
#include <min/System.h>

STRING8  root = "/home/user/../user1";
STRING8  path = "/./Documents/whaat/../../Downloads/.System.File.test.txt";

STRING8  root1 = "../../user1";
STRING8  path1 = "./Documents/whaat/Downloads/../../../../../.System.File.test.txt";

STRING8  path2 = "index.html";

STRING8  root2 = "/home/user1/";
STRING8  path3 = "/";

int System_Runtime_main(int argc, char * argv[]) {

    Console_writeLine("Test01: System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root, path);
	String8 combination = System_Path_combine(root, path);
    Bool equals = String8_equals(combination, "/home/user1/Downloads/.System.File.test.txt");
    Console_writeLine("Test01: {0:string} {1:string}", 2, equals ? "SUCCESS" : "ERROR", combination);
    Memory_free(combination);

    Console_writeLine("Test02: System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root1, path1);
	String8 combination1 = System_Path_combine(root1, path1);
    Bool equals1 = String8_equals(combination1, "../../../.System.File.test.txt");
    Console_writeLine("Test02: {0:string} {1:string}", 2, equals1 ? "SUCCESS" : "ERROR", combination1);
    Memory_free(combination1);

    Console_writeLine("Test03: System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root, path2);
	String8 combination2 = System_Path_combine(root, path2);
    Bool equals2 = String8_equals(combination2, "/home/user1/index.html");
    Console_writeLine("Test03: {0:string} {1:string}", 2, equals2 ? "SUCCESS" : "ERROR", combination2);
    Memory_free(combination2);

    Console_writeLine("Test04: System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root2, path3);
	String8 combination3 = System_Path_combine(root2, path3);
    Bool equals3 = String8_equals(combination3, "/home/user1/");
    Console_writeLine("Test04: {0:string} {1:string}", 2, equals3 ? "SUCCESS" : "ERROR", combination3);
    Memory_free(combination3);

    String8  command_directory = System_Path_getDirectoryName(path1);
    if (!command_directory)
        Console_writeLine__string("Test10: ERROR: Path_getDirectoryName");
    else {
        Console_writeLine("Test10: SUCCESS: Path_getDirectoryName: {0:string}", 1, command_directory);
        Memory_free(command_directory);
    }

    String8  command_filename = System_Path_getFileName(path1);
    if (!command_filename)
        Console_writeLine__string("Test11: ERROR: Path_getDirectoryName");
    else {
        Console_writeLine("Test11: SUCCESS: Path_getFileName: {0:string}", 1, command_filename);
        Memory_free(command_filename);
    }
    

	return true;	/* OK (1 == true) */
}
