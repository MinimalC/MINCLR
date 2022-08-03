#define using_System
#include <min/System.h>

STRING8  HALLO = "HaLLo";
STRING8  HALLOtxt = "./.test.txt";

#define main  System_Runtime_main

//main(test42_System_File, args) {
int main(int argc, char * argv[]) {

	/* Test00: Open a File */
    File file = File_open(HALLOtxt, System_File_Mode_readWrite | System_File_Mode_create | System_File_Mode_truncate);


	/* Test01: Write to the File and flush */
    File_write__string_size(file, HALLO, sizeof(HALLO) - 1);

    File_sync(file);

	/* Test02: get Position */
    Size position = File_get_Position(file);

    if (position == 5)
        Console_writeLine("Position {0:uint} is correct", 1, position);
    else
        Console_writeLine("Position {0:uint} is NOT correct", 1, position);


	/* Test03: set Position */
    File_set_Position(file, 0);

	/* Test04: Read from the File */
    Char8 text[6];
    for (Size i = 0; i < 6; ++i) text[i] = 0x00;

    Size count =  File_read(file, text, 5);

    if (count == 5 && String8_equals(HALLO, text))
        Console_writeLine("{0:string} is correct, {1:uint} bytes read", 2, text, count);
    else
        Console_writeLine("{0:string} is NOT correct, {1:uint} bytes read", 2, text, count);


	/* Test02: Close the File */
    Memory_free(file);

	return true;	/* OK (1 == true) */
}
