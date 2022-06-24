#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_File)
#include "System.File.h"
#endif
#if !defined(have_System_Console)
#define have_System_Console

__export struct_System_Type  System_ConsoleType;

__export struct_System_File  System_Console_StdIn;
__export struct_System_File  System_Console_StdOut;
__export struct_System_File  System_Console_StdErr;

__export System_void  System_Console_sync();
__export System_void  System_Console_exit(const System_size code) __noreturn;
__export System_void  System_Console_terminate(const System_size code) __noreturn;

__export System_void  System_Console_write0(System_string8 string);
__export System_void  System_Console_write(System_string8 format, ...);
__export System_void  System_Console_writeLineEmpty();
__export System_void  System_Console_writeLine0(System_string8 string);
__export System_void  System_Console_writeLine(System_string8 format, ...);
__export System_void  System_Console_writeSuffix__arguments(System_string8 format, System_char8 suffix, System_arguments args);

__export System_void  System_Console_print(System_string8 format, ...);
__export System_void  System_Console_printByte(System_uint8 byte);
__export System_void  System_Console_printHex(const System_uint32 length, const void  * hex);
__export System_void  System_Console_printLine(System_string8 format, ...);
__export System_void  System_Console_printLineEmpty();

#if defined(using_System)
#define __ConsoleType  System_ConsoleType
#define __Console_sync  System_Console_sync
#define __Console_exit  System_Console_exit
#define __Console_terminate  System_Console_terminate
#define __Console_print  System_Console_print
#define __Console_printByte  System_Console_printByte
#define __Console_printHex  System_Console_printHex
#define __Console_printLine  System_Console_printLine
#define __Console_printLineEmpty  System_Console_printLineEmpty
#endif

#endif
