#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_string8)
#include <min/System.string8.h>
#endif
#if !defined(have_ISO)
#include <min/ISO.h>
#endif
#if !defined(code_System_Console)
#define code_System_Console

/* OLD: */
void System_assert4(const __string8 assertion, const __string8 fileName, const __uint32 line, const __string8 functionName) {
    __Console_writeLine("Assert: File {0:string}:{1:int}  function {2:string}: {3:string}", 4, fileName, line, functionName, assertion);
    System_Console_terminate(0);
}
void System_debug5(const __string8 assertion, const __string8 fileName, const __uint32 line, const __string8 functionName, const __string8 message) {
    __Console_writeLine("Debug: File {0:string}:{1:int}  function {2:string}: {3:string}: {4:string}", 5, fileName, line, functionName, assertion, message);
}
/* NEW: */

struct_System_Type  System_ConsoleType = { .base = stack_System_Object(System_Type),
	.name = "System.Console",
};

struct_System_File  System_Console_StdIn = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_var)System_File_special_STDIN,
};
struct_System_File  System_Console_StdOut = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_var)System_File_special_STDOUT,
};
struct_System_File  System_Console_StdErr = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_var)System_File_special_STDERR,
};

void  System_Console_sync() {
    /* ISO_fflush(ISO_stdout); */
    System_Syscall_fsync((System_var)System_File_special_STDOUT);
}

/* __attribute__((constructor)) void System_init */

void System_Console_exit(const __size code)  {
    System_Syscall_terminate(code);
}

void System_Console_terminate(const __size code)  {
    /* fclose(randomDevice); */

    System_Exception exception = System_Exception_get_current();
    if (exception) {
        System_Object_addReference((System_Object)exception);
        System_Exception_set_current(__null);

        if (inline_System_Object_get_Type(exception))
            __Console_write("{0:string}", 1, exception->base.Type->name);
        else
            __Console_write__string8("System.Exception");

        if (exception->message)
            __Console_write(": {0:string}", 1, exception->message);

        __Console_writeLineEmpty();

        inline_Object_freeClass(&exception);
    }

    System_Syscall_terminate(code);
}

void  System_Console_write__string8(__string8 string) {
    System_File_write(&System_Console_StdOut, __string8_get_Length(string), string);
}

void  System_Console_write(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_string8_formatSuffixTo__arguments(format, __null, (System_IStream)&System_Console_StdOut, args);
    __arguments_end(args);
}

void  System_Console_writeLineEmpty() {
    System_string8_formatSuffixTo__arguments(__string8_Empty, '\n', (System_IStream)&System_Console_StdOut, __null);
}

void  System_Console_writeLine__string8(__string8 string) {
    System_string8_formatSuffixTo__arguments(string, '\n', (System_IStream)&System_Console_StdOut, __null);
}

void  System_Console_writeLine(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_string8_formatSuffixTo__arguments(format, '\n', (System_IStream)&System_Console_StdOut, args);
    __arguments_end(args);
}

void  System_Console_write__char8(__char8 character) {
    System_string8_formatSuffixTo__arguments("", character, (System_IStream)&System_Console_StdOut, __null);
}


#define __hexdump_Columns  32

void System_Console_writeHex(__size length, void  * value) {
    if (length == 0 || !value) return;

    __uint8  * memory = (__uint8  *)value;
    __size i, j;

    for (i = 0; i < length + ((length % __hexdump_Columns) ? (__hexdump_Columns - length % __hexdump_Columns) : 0); i++)
    {
        /* print offset */
        if(i % __hexdump_Columns == 0)
        {
            __Console_write("0x{0:uint64:hex}: ", 1, i); // TODO: precision 8 on amd64, 4 on arm
        }

        /* print hex data */
        if(i < length)
        {
            __Console_write("{0:uint8:hex} ", 1, 0xFF & (memory[i])); // TODO: precision 2
        }
        else /* end of block, just aligning for ASCII dump */
        {
            __Console_write__string8("   ");
        }

        /* print ASCII dump */
        if(i % __hexdump_Columns == (__hexdump_Columns - 1))
        {
            for(j = i - (__hexdump_Columns - 1); j <= i; j++)
            {
                if(j >= length) /* end of block, not really printing */
                {
                    __Console_write__char8(' ');
                }
                else if(System_char8_isPrintable(memory[j])) /* printable char */
                {
                    __Console_write__char8(0xFF & (memory[j]));
                }
                else /* other char */
                {
                    __Console_write__char8('.');
                }
            }
            __Console_write__char8('\n');
        }
    }
}

#endif
