#define using_System
#include <min/System.h>

struct_string8  HALLO = "HaLLo";
struct_string8  HALLOtxt = "./.test.txt";

//__main(test42_System_File, args) {
int main(int argc, char * argv[]) {

	/* Test00: Open a File */
    __File file = __File_open(HALLOtxt, System_File_mode_readWrite | System_File_mode_create | System_File_mode_truncate);


	/* Test01: Write to the File and flush */
    __File_write(file, sizeof(HALLO) - 1, HALLO);

    __File_sync(file);

	/* Test02: get Position */
    __size position = __File_get_Position(file);

    if (position == 5)
        __Console_writeLine("Position {0:uint} is correct", 1, position);
    else
        __Console_writeLine("Position {0:uint} is NOT correct", 1, position);


	/* Test03: set Position */
    __File_set_Position(file, 0);

	/* Test04: Read from the File */
    __char8 text[6];
    for (__size i = 0; i < 6; ++i) text[i] = 0x00;

    __size count =  __File_read(file, 5, text);

    if (count == 5 && __string8_equals(HALLO, text))
        __Console_writeLine("{0:string} is correct, {1:uint} bytes read", 2, text, count);
    else
        __Console_writeLine("{0:string} is NOT correct, {1:uint} bytes read", 2, text, count);


	/* Test02: Close the File */
    __Object_freeClass(&file);

	return __true;	/* OK (1 == true) */
}
