#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_File)
#include "System.File.h"
#endif
#if !defined(have_System_Console)
#define have_System_Console

export struct System_Type  System_ConsoleType;

export struct System_File  System_Console_StdIn;
export struct System_File  System_Console_StdOut;
export struct System_File  System_Console_StdErr;

export void  System_Console_exit(const System_size code) noreturn;
export void  System_Console_terminate(const System_size code) noreturn;

export void  System_Console_sync();
export void  System_Console_write__string8(System_string8 string);
export void  System_Console_write(System_string8 format, ...);
export void  System_Console_writeLineEmpty();
export void  System_Console_writeLine__string8(System_string8 string);
export void  System_Console_writeLine(System_string8 format, ...);
export void  System_Console_write__char8(System_char8 character);
export void  System_Console_writeSuffix__arguments(System_string8 format, System_char8 suffix, System_arguments args);
export void  System_Console_writeHex(System_size length, System_var value);

#if defined(using_System)
#define ConsoleType  System_ConsoleType
#define Console_exit  System_Console_exit
#define Console_terminate  System_Console_terminate
#define Console_sync  System_Console_sync
#define Console_write__string8  System_Console_write__string8
#define Console_write  System_Console_write
#define Console_writeLineEmpty  System_Console_writeLineEmpty
#define Console_writeLine__string8  System_Console_writeLine__string8
#define Console_writeLine  System_Console_writeLine
#define Console_write__char8  System_Console_write__char8
#define Console_writeSuffix__arguments  System_Console_writeSuffix__arguments
#define Console_writeHex  System_Console_writeHex
#endif
#endif
