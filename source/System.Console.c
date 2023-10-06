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
#if !defined(code_System_Console)
#define code_System_Console

struct System_Type System_ConsoleType = { .base = { .type = typeof(System_Type) },
	.name = "Console",
};

struct System_File  System_Console_StdIn = {
    .base = { .type = typeof(System_File) },
    .filePtr = (System_Var)System_Syscall_StandardFile_STDIN,
};
struct System_File  System_Console_StdOut = {
    .base = { .type = typeof(System_File) },
    .filePtr = (System_Var)System_Syscall_StandardFile_STDOUT,
};
struct System_File  System_Console_StdErr = {
    .base = { .type = typeof(System_File) },
    .filePtr = (System_Var)System_Syscall_StandardFile_STDERR,
};

void  System_Console_sync() {
    System_Syscall_fsync((System_Var)System_Syscall_StandardFile_STDOUT);
}

/* __attribute__((constructor)) void System_init */

void System_Console_exit(const Size code)  {
#if DEBUG == DEBUG_System_Syscall_mmap
    System_Syscall_mmap__debug();
#endif
#if DEBUG
    System_Memory_debug();
#endif
    if (System_Exception_current) System_Exception_terminate(System_Exception_current);
    System_Syscall_terminate(code);
}

void  System_Console_write__string_size(String8 string, Size size) {
    Debug_assert(string);
    base_System_File_write__string_size(&System_Console_StdOut, string, size);
}

void  System_Console_write__string(String8 string) {
    System_Console_write__string_size(string, String8_get_Length(string));
}

void  System_Console_write__char(Char8 character) {
    System_Console_write__string_size(&character, 1);
}

void  System_Console_write(String8 format, ...) {
    Debug_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_File_writeEnd__arguments(&System_Console_StdOut, format, 0, argc, argv);
}

void  System_Console_writeLineEmpty(void) {
    base_System_File_write__string_size(&System_Console_StdOut, "\n", 1);
}

void  System_Console_writeLine__string(String8 string) {
    System_Console_writeLine(string, 0);
}

void  System_Console_writeLine(String8 format, ...) {
    Debug_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_File_writeEnd__arguments(&System_Console_StdOut, format, '\n', argc, argv);
}


#define hexdump_Columns  32
#define hexdump_Space_VALUE  142 /* = 12 + (hexdump_Columns * 3) + hexdump_Columns + 2 */

void System_Debug_writeHex(Size length, void  * value) {
    if (length == 0 || !value) return;

    UInt8  * memory = (UInt8  *)value;
    Size i, j, l, pos, length_div_columns_rem = length % hexdump_Columns, i_div_columns_rem;


    Char8 scratch[System_UInt64_String8base16Length_DEFAULT + 1]; System_Stack_zero(scratch);

    Char8 buffer[hexdump_Space_VALUE]; System_Stack_zero(buffer);
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

void System_Debug_assert__String8(const System_String8 expression, const System_String8 functionName, const System_String8 fileName, const System_Size line) {
    Var argv[4];
    argv[0] = (Var)expression;
    argv[1] = (Var)functionName;
    argv[2] = (Var)fileName;
    argv[3] = (Var)line;
    base_System_File_writeEnd__arguments(&System_Console_StdErr, "ASSERT: {0:string} in function {1:string} in {2:string}:{3:int}", '\n', 4, argv);
}

void System_Debug_writeLine__message(const System_String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_File_writeEnd__arguments(&System_Console_StdErr, format, '\n', argc, argv);
}

System_String8 System_Console_Arguments[System_Console_Arguments_Length] = { };

#endif