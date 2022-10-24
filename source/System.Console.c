#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt8)
#include <min/System.values.auto.h>
#endif
#if !defined(have_ISO)
#include <min/ISO.h>
#endif
#if !defined(code_System_Console)
#define code_System_Console

struct System_Type  System_ConsoleType = { .base = stack_System_Object(System_Type),
	.name = "Console",
};

struct System_File  System_Console_StdIn = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_Syscall_StandardFile_STDIN,
};
struct System_File  System_Console_StdOut = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_Syscall_StandardFile_STDOUT,
};
struct System_File  System_Console_StdErr = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_Syscall_StandardFile_STDERR,
};

void  System_Console_sync() {
    /* ISO_fflush(ISO_stdout); */
    System_Syscall_fsync((System_Var)System_Syscall_StandardFile_STDOUT);
}

/* __attribute__((constructor)) void System_init */

void System_Console_exit(const Size code)  {
#if DEBUG || !DEBUG
    struct System_Exception exception;
    if (stack_System_Exception_catch(&exception, typeof(System_Exception))) {
        if (exception.message && exception.error)
            Console_writeLine("{0:string}: error {1:uint} ({2:string}): {3:string}", 4, exception.base.type->name, exception.error, enum_getName(typeof(System_Error), exception.error), exception.message);
        else if (exception.message)
            Console_writeLine("{0:string}: {1:string}", 2, exception.base.type->name, exception.message);
        else if (exception.error)
            Console_writeLine("{0:string}: error {1:uint} ({2:string})", 3, exception.base.type->name, exception.error, enum_getName(typeof(System_Error), exception.error));
        else
            Console_writeLine("{0:string}", 1, exception.base.type->name);
    }
#endif
    System_Syscall_terminate(code);
}

void  System_Console_write__string(String8 string) {
    Debug_assert(string);
    System_File_write__string_size(&System_Console_StdOut, string, String8_get_Length(string));
}

void  System_Console_write__char(Char8 character) {
    System_File_write__string_size(&System_Console_StdOut, &character, 1);
}

void  System_Console_writeLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdOut, "\n", 1);
}

void  System_Console_write(String8 format, ...) {
    Debug_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments((System_IStream)&System_Console_StdOut, format, 0, argc, argv);
}

void  System_Console_writeLine__string(String8 string) {
    Debug_assert(string);
    System_Console_writeLine(string, 0);
}

void  System_Console_writeLine(String8 format, ...) {
    Debug_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments((System_IStream)&System_Console_StdOut, format, '\n', argc, argv);
}


#define hexdump_Columns  32
#define hexdump_Space_VALUE  142 /* = 12 + (hexdump_Columns * 3) + hexdump_Columns + 2 */

void System_Debug_writeHex(Size length, void  * value) {
    if (length == 0 || !value) return;

    UInt8  * memory = (UInt8  *)value;
    Size i, j, l, pos, length_div_columns_rem = length % hexdump_Columns, i_div_columns_rem;


    Char8 scratch[System_UInt64_String8base16Length_DEFAULT + 1];
    for (i = 0; i < System_UInt64_String8base16Length_DEFAULT; ++i) scratch[i] = 0;

    Char8 buffer[hexdump_Space_VALUE];
    static Size hexdump_Space = hexdump_Space_VALUE;
    for (i = 0; i < hexdump_Space; ++i) buffer[i] = 0;
    buffer[0] = '0';
    buffer[1] = 'x';

    for (i = 0; i < length + ((length_div_columns_rem) ? (hexdump_Columns - length_div_columns_rem) : 0); ++i)
    {
        i_div_columns_rem = i % hexdump_Columns;

        /* print offset */
        if(i_div_columns_rem == 0)
        {
            pos = 2;
            l = stack_System_UInt64_toString8base16(i, scratch);
            Memory_copyTo(scratch, l, buffer + pos);
            pos += l;
            buffer[pos++] = ':';
            buffer[pos++] = ' ';
        }

        /* print hex data */
        if(i < length)
        {
            l = stack_System_UInt8_toString8base16(0xFF & memory[i], scratch);
            Memory_copyTo(scratch, l, buffer + pos);
            pos += l;
            buffer[pos++] = ' ';
        }
        else /* end of block, just aligning for ASCII dump */
        {
            buffer[pos++] = ' ';
            /* buffer[pos++] = ' '; */
            /* buffer[pos++] = ' '; */
        }

        /* print ASCII dump */
        if(i_div_columns_rem == (hexdump_Columns - 1))
        {
            for(j = i - (hexdump_Columns - 1); j <= i; j++)
            {
                if(j >= length) /* end of block, not really printing */
                {
                    buffer[pos++] = ' ';
                }
                else if(System_Char8_isPrintable(memory[j])) /* printable char */
                {
                    buffer[pos++] = 0xFF & memory[j];
                }
                else /* other char */
                {
                    buffer[pos++] = '.';
                }
            }
            buffer[pos++] = '\n';
            buffer[pos++] = '\0';
            Console_write__string(buffer);
        }
    }
}

#undef hexdump_Columns
#undef hexdump_Space_VALUE

void System_Debug_assert__String8(const System_String8 expression, const System_String8 functionName, const System_String8 fileName, const System_UInt32 line) {
    System_IStream_writeLine((System_IStream)&System_Console_StdErr, "ASSERT: {0:string} in function {1:string} in {2:string}:{3:int}", 4, expression, functionName, fileName, line);
}

void System_Debug_writeLine__message(const System_String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeLine__arguments((System_IStream)&System_Console_StdErr, format, argc, argv);
}

System_String8 System_Console_Arguments[System_Console_Arguments_Length] = { };

#endif