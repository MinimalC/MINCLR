/* Gemeinfrei. Public Domain. */
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

enum { System_Console_Arguments_Length = 256 };
export System_String8 System_Console_Arguments[System_Console_Arguments_Length];

export void  System_Console_exit(const System_Size code) noreturn;

export void  System_Console_sync(void);
export void  System_Console_write__string_size(System_String8 string, System_Size size);
export void  System_Console_write__string(System_String8 string);
export void  System_Console_write(System_String8 format, ...);
export void  System_Console_writeLineEmpty(void);
/*export void  System_Console_writeLine__string_size(System_String8 string, System_Size size);*/
export void  System_Console_writeLine__string(System_String8 string);
export void  System_Console_writeLine(System_String8 format, ...);
export void  System_Console_write__char(System_Char8 character);
export void  System_Debug_writeHex(System_Size length, System_Var value);

#if defined(using_System)
#define ConsoleType  System_ConsoleType
#define Console_exit  System_Console_exit
#define Console_sync  System_Console_sync
#define Console_write__string  System_Console_write__string
#define Console_write  System_Console_write
#define Console_writeLineEmpty  System_Console_writeLineEmpty
#define Console_writeLine__string  System_Console_writeLine__string
#define Console_writeLine  System_Console_writeLine
#define Console_write__char  System_Console_write__char
#define Debug_writeHex  System_Debug_writeHex
#endif
#endif
