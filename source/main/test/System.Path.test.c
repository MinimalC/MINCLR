#define using_System
#include <min/System.h>

STRING8  root = "/home/user/../user1";
STRING8  path = "/./Documents/whaat/../../Downloads/.System.File.test.txt";

STRING8  root1 = "../../user1";
STRING8  path1 = "./Documents/whaat/Downloads/../../../../../.System.File.test.txt";

int System_Runtime_main(int argc, char * argv[]) {

    Console_writeLine("Using System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root, path);
	String8 combination = System_Path_combine(root, path);
    Console_writeLine("{0:string}", 1, combination);
    Memory_free(combination);

    Console_writeLine("Using System_Path_combine(\"{0:string}\", \"{1:string}\"):", 2, root1, path1);
	String8 combination1 = System_Path_combine(root1, path1);
    Console_writeLine("{0:string}", 1, combination1);
    Memory_free(combination1);

	return true;	/* OK (1 == true) */
}
