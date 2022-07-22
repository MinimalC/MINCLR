#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
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
#if !defined(have_ISO)
#include <min/ISO.h>
#endif
#if !defined(code_System_Console)
#define code_System_Console

struct System_Type  System_ConsoleType = { .base = stack_System_Object(System_Type),
	.name = "System.Console",
};

struct System_File  System_Console_StdIn = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_File_special_STDIN,
};
struct System_File  System_Console_StdOut = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_File_special_STDOUT,
};
struct System_File  System_Console_StdErr = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_Var)System_File_special_STDERR,
};

void  System_Console_sync() {
    /* ISO_fflush(ISO_stdout); */
    System_Syscall_fsync((System_Var)System_File_special_STDOUT);
}

/* __attribute__((constructor)) void System_init */

void System_Console_exit(const Size code)  {
    System_Syscall_terminate(code);
}

void System_Console_terminate(const Size code)  {
    /* fclose(randomDevice); */

    System_Exception exception = System_Exception_get_current();
    if (exception) {
        System_Memory_addReference((System_Object)exception);
        System_Exception_set_current(null);

        if (exception->base.type)
            Console_write("{0:string}", 1, exception->base.type->name);
        else
            Console_write__String8_size("System.Exception");

        if (exception->message)
            Console_write(": {0:string}", 1, exception->message);

        Console_writeLineEmpty();

        System_Memory_free(exception);
    }

    System_Syscall_terminate(code);
}

void  System_Console_write__String8(String8 string) {
    System_File_write__String8_size(&System_Console_StdOut, string, String8_get_Length(string));
}

void  System_Console_write__char8(Char8 character) {
    System_File_write__String8_size(&System_Console_StdOut, &character, 1);
}

void  System_Console_writeLineEmpty() {
    System_File_write__String8_size(&System_Console_StdOut, "\n", 1);
}

void  System_Console_write(String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE] = { 0 };
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments((System_IStream)&System_Console_StdOut, format, 0, argc, argv);
}

void  System_Console_writeLine__String8(String8 string) {
    System_IStream_writeLine((System_IStream)&System_Console_StdOut, string);
}

void  System_Console_writeLine(String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE] = { 0 };
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments((System_IStream)&System_Console_StdOut, format, '\n', argc, argv);
}


#define hexdump_Columns  32

void System_Console_writeHex(Size length, void  * value) {
    if (length == 0 || !value) return;

    UInt8  * memory = (UInt8  *)value;
    Size i, j;

    for (i = 0; i < length + ((length % hexdump_Columns) ? (hexdump_Columns - length % hexdump_Columns) : 0); i++)
    {
        /* print offset */
        if(i % hexdump_Columns == 0)
        {
            Console_write("0x{0:uint64:hex}: ", 1, i); // TODO: precision 8 on amd64, 4 on arm
        }

        /* print hex data */
        if(i < length)
        {
            Console_write("{0:uint8:hex} ", 1, 0xFF & (memory[i])); // TODO: precision 2
        }
        else /* end of block, just aligning for ASCII dump */
        {
            Console_write__String8_size("   ");
        }

        /* print ASCII dump */
        if(i % hexdump_Columns == (hexdump_Columns - 1))
        {
            for(j = i - (hexdump_Columns - 1); j <= i; j++)
            {
                if(j >= length) /* end of block, not really printing */
                {
                    Console_write__char8(' ');
                }
                else if(System_Char8_isPrintable(memory[j])) /* printable char */
                {
                    Console_write__char8(0xFF & (memory[j]));
                }
                else /* other char */
                {
                    Console_write__char8('.');
                }
            }
            Console_write__char8('\n');
        }
    }
}

#undef hexdump_Columns

void System_Console_assert__String8(const System_String8 expression, const System_String8 functionName, const System_String8 fileName, const System_UInt32 line) {
    System_IStream_writeLine((System_IStream)&System_Console_StdErr, "ASSERT: {0:string} in function {1:string} in {2:string}:{3:int}", 4, expression, functionName, fileName, line);
}

#undef System_Console_debug
void System_Console_debug(const System_String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE] = { 0 };
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeLine__arguments((System_IStream)&System_Console_StdErr, format, argc, argv);
}

#endif