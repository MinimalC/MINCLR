#define using_System
#include <min/System.h>


String8  root[] = { 
    "/home/user/../user1", 
    "../../user1",
    "/home/user1/",
};
String8  path[] = { 
    "/",
    "index.html",
    "/index.html",
    "../index.html",
    "/../index.html",
    "/./Documents/whaat/../../Downloads/.System.File.test.txt",
    "./Documents/whaat/Downloads/../../../../../.System.File.test.txt",
};
String8  success[] = { 
    // root "/home/user/../user1", 
    "/home/user1/", 
    "/home/user1/index.html",
    "/home/user1/index.html", 
    "/home/index.html",
    "/home/index.html", 
    "/home/user1/Downloads/.System.File.test.txt",
    "/.System.File.test.txt",

    // root "../../user1"
    "../../user1/",
    "../../user1/index.html",
    "../../user1/index.html",
    "../../index.html",
    "../../index.html",
    "../../user1/Downloads/.System.File.test.txt",
    "../../../.System.File.test.txt",

    // root "/home/user1/",
    "/home/user1/",
    "/home/user1/index.html",
    "/home/user1/index.html",
    "/home/index.html",
    "/home/index.html",
    "/home/user1/Downloads/.System.File.test.txt",
    "/.System.File.test.txt",
};

int System_Runtime_main(int argc, char * argv[]) {

    System_Size test = 0;

    for (Size r = 0, s = 0; r < sizeof_array(root); ++r) {
        for (Size p = 0; p < sizeof_array(path); ++p, ++s, ++test) {
            String8 combination = System_Path_combine(root[r], path[p]);
            Bool equals = String8_equals(combination, success[s]);
            Console_writeLine("Test{0:uint}: \"{1:string}\" & \"{2:string}\" => \"{3:string}\": {4:string}", 5, test, root[r], path[p],
                combination, equals ? "SUCCESS" : "ERROR");

            /*String8  directory = System_Path_getDirectoryName(combination);
            Console_writeLine("Test{0:uint}: Path_getDirectoryName: {1:string}", 2, test, directory);
            Memory_free(directory);

            String8  filename = System_Path_getFileName(combination);
            Console_writeLine("Test{0:uint}: Path_getFileName: {1:string}", 2, test, filename);
            Memory_free(filename);*/

            Memory_free(combination);
        }
    }

    

	return true;	/* OK (1 == true) */
}
