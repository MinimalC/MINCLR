#if !defined(have_System_internal)
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
#if !defined(have_System_string8)
#include <min/System.string8.h>
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
    .filePtr = (System_var)System_File_special_STDIN,
};
struct System_File  System_Console_StdOut = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_var)System_File_special_STDOUT,
};
struct System_File  System_Console_StdErr = {
    .base = stack_System_Object(System_File),
    .filePtr = (System_var)System_File_special_STDERR,
};

void  System_Console_sync() {
    /* ISO_fflush(ISO_stdout); */
    System_Syscall_fsync((System_var)System_File_special_STDOUT);
}

/* __attribute__((constructor)) void System_init */

void System_Console_exit(const size code)  {
    System_Syscall_terminate(code);
}

void System_Console_terminate(const size code)  {
    /* fclose(randomDevice); */

    System_Exception exception = System_Exception_get_current();
    if (exception) {
        System_Memory_addReference((System_Object)exception);
        System_Exception_set_current(null);

        if (exception->base.type)
            Console_write("{0:string}", 1, exception->base.type->name);
        else
            Console_write__string8("System.Exception");

        if (exception->message)
            Console_write(": {0:string}", 1, exception->message);

        Console_writeLineEmpty();

        System_Memory_free(exception);
    }

    System_Syscall_terminate(code);
}

void  System_Console_write__string8(string8 string) {
    System_File_write(&System_Console_StdOut, string8_get_Length(string), string);
}

void  System_Console_write(string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_formatEnd__arguments((System_IStream)&System_Console_StdOut, format, 0, argc, argv);
}

void  System_Console_writeLineEmpty() {
    System_File_write(&System_Console_StdOut, 1, "\n");
}

void  System_Console_writeLine__string8(string8 string) {
    System_IStream_formatLine((System_IStream)&System_Console_StdOut, string);
}

void  System_Console_writeLine(string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_formatEnd__arguments((System_IStream)&System_Console_StdOut, format, '\n', argc, argv);
}

void  System_Console_write__char8(char8 character) {
    System_File_write(&System_Console_StdOut, 1, &character);
}


void System_Console_assert__string8(const System_string8 expression, const System_string8 functionName, const System_string8 fileName, const System_uint32 line) {
    System_IStream_formatLine((System_IStream)&System_Console_StdErr, "ASSERT: {0:string} in function {1:string} in {2:string}:{3:int}", 4, expression, functionName, fileName, line);
}

void System_Console_debug__format(const System_string8 expression, const System_string8 message, const System_string8 functionName, const System_string8 fileName, const System_uint32 line) {
    /* TODO: Prepend __VA_ARGS__ ARGUMENTS, Append expression, message etc. */
    System_IStream_formatLine((System_IStream)&System_Console_StdErr, "DEBUG: {0:string}: {1:string} in function {2:string} in {3:string}:{4:int}", 5, expression, message, functionName, fileName, line);
}


#define hexdump_Columns  32

void System_Console_writeHex(size length, void  * value) {
    if (length == 0 || !value) return;

    uint8  * memory = (uint8  *)value;
    size i, j;

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
            Console_write__string8("   ");
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
                else if(System_char8_isPrintable(memory[j])) /* printable char */
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

#endif
