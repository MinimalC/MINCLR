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

export System_Var System_Console_Arguments;
export System_Size System_Console_Arguments_Count;

export void  System_Console_exit(const System_Size code) noreturn;
export void  System_Console_sync(void);

export System_Size  System_Console_execute(System_String8 fileName, ...);
export System_Size  System_Console_execute__arguments(System_String8 fileName, System_Size argc, System_String8 argv[]);

export void  System_Console_write__char(System_Char8 character);
export void  System_Console_write__string_size(System_String8 string, System_Size size);
export void  System_Console_write__string(System_String8 string);
export void  System_Console_write(System_String8 format, ...);
export void  System_Console_writeLineEmpty(void);
/*export void  System_Console_writeLine__string_size(System_String8 string, System_Size size);*/
export void  System_Console_writeLine__string(System_String8 string);
export void  System_Console_writeLine(System_String8 format, ...);
export void  System_Console_assert__string8(const System_Bool expression, const System_String8 text, const System_String8 functionName, const System_String8 fileName, const System_Size line);
export void  System_Console_debug(const System_String8 format, ...);
export void  System_Console_debug__string(System_String8 format);
export void  System_Console_debug__string_size(System_String8 format, System_Size size);
export void  System_Console_debugLine(const System_String8 format, ...);
export void  System_Console_debugLine__string(const System_String8 string);
export void  System_Console_debugLineEmpty(void);
export void  System_Console_error(const System_String8 format, ...);
export void  System_Console_errorLine(const System_String8 format, ...);
export void  System_Console_errorLineEmpty(void);
export void  System_Console_writeHex(System_Size length, System_Var value);

#if !DEBUG
#define System_Console_assert(expression) (void)(expression)
#else
#define System_Console_assert(expression)  (void)System_Console_assert__string8((expression), (System_String8)#expression, (System_String8)__func__, (System_String8)__FILE__, (System_Size)__LINE__)
#endif

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
#define Console_assert  System_Console_assert
#define Console_assert__string8  System_Console_assert__string8
#define Console_debug  System_Console_debug
#define Console_debugLine  System_Console_debugLine
#define Console_debugLineEmpty  System_Console_debugLineEmpty
#define Console_error  System_Console_error
#define Console_errorLine  System_Console_errorLine
#define Console_errorLineEmpty  System_Console_errorLineEmpty
#define Console_writeHex  System_Console_writeHex
#endif
#endif
