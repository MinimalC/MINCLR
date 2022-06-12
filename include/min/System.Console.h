#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_System_Console)
#define have_System_Console

__export struct_System_Type  System_ConsoleType;

__export System_void  System_Console_sync();
__export System_void  System_Console_exit(const System_size code) __noreturn;
__export System_void  System_Console_terminate(const System_size code) __noreturn;

__export System_void  System_Console_write(System_string8 format, System_arguments args);
__export System_void  System_Console_write__arguments(System_string8 format, ...);
__export System_void  System_Console_writeLine(System_string8 format, System_arguments args);
__export System_void  System_Console_writeLine__arguments(System_string8 format, ...);

__export System_void  System_Console_print(System_string8 format, ...);
__export System_void  System_Console_printByte(System_uint8 byte);
__export System_void  System_Console_printHex(const System_uint32 length, const void  * hex);
__export System_void  System_Console_printLine(System_string8 format, ...);
__export System_void  System_Console_printLineEmpty();
__export System_void  System_Console_printString(System_String format, ...);
__export System_void  System_Console_printHexString(System_String hexString);
__export System_void  System_Console_printStringLine(System_String format, ...);

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
#define __Console_printString  System_Console_printString
#define __Console_printHexString  System_Console_printHexString
#define __Console_printStringLine  System_Console_printStringLine
#endif

#endif
