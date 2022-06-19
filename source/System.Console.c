#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_Console)
#define code_System_Console

/* OLD: */
void System_assert4(const __string8 assertion, const __string8 fileName, const __uint32 line, const __string8 functionName) {
    __Console_printLine("Assert: File %s:%i  function %s: %s", fileName, line, functionName, assertion);
    System_Console_terminate(0);
}
void System_debug5(const __string8 assertion, const __string8 fileName, const __uint32 line, const __string8 functionName, const __string8 message) {
    __Console_printLine("Debug: File %s:%i  function %s: %s: %s", fileName, line, functionName, assertion, message);
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
            __Console_print("%s", exception->base.Type->name);
        else
            __Console_print("System.Exception");

        if (exception->message)
            __Console_print(": %s", exception->message);

        __Console_printLineEmpty();

        inline_Object_freeClass(&exception);
    }

    System_Syscall_terminate(code);
}

void  System_Console_write0(__string8 string) {
    base_System_File_write(&System_Console_StdOut, __string8_get_Length(string), string);
}

void  System_Console_write(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_string8_formatSuffixTo__arguments(format, 0, (System_IStream)&System_Console_StdOut, args);
    __arguments_end(args);
}

void  System_Console_writeLine(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_string8_formatSuffixTo__arguments(format, '\n', (System_IStream)&System_Console_StdOut, args);
    __arguments_end(args);
}


void System_Console_print(__string8 format, ...) {
    __assert(format)

    __arguments args;
    __arguments_start(args, (void *)format);
    ISO_vfprintf(ISO_stdout, format, args);
    __arguments_end(args);
}

void System_Console_printByte(__uint8 byte) {
    __assert(byte)

    ISO_putc(byte, ISO_stdout);
}

void System_Console_printString(__String format, ...) {
    if (!format || !format->value) return;

    __arguments args;
    __arguments_start(args, (void *)format);
    ISO_vfprintf(ISO_stdout, format->value, args);
    __arguments_end(args);
}

#define __hexdump_Columns  32

void System_Console_printHex(const __uint32 length, const void  * value) {
    if (length == 0 || !value) return;

    __uint8  * memory = (__uint8  *)value;
    __uint32 i, j;

    for (i = 0; i < length + ((length % __hexdump_Columns) ? (__hexdump_Columns - length % __hexdump_Columns) : 0); i++)
    {
        /* print offset */
        if(i % __hexdump_Columns == 0)
        {
            __Console_print("0x%08x: ", i);
        }

        /* print hex data */
        if(i < length)
        {
            __Console_print("%02x ", 0xFF & (memory[i]));
        }
        else /* end of block, just aligning for ASCII dump */
        {
            __Console_print("   ");
        }

        /* print ASCII dump */
        if(i % __hexdump_Columns == (__hexdump_Columns - 1))
        {
            for(j = i - (__hexdump_Columns - 1); j <= i; j++)
            {
                if(j >= length) /* end of block, not really printing */
                {
                    __Console_printByte(' ');
                }
                else if(System_uint8_isPrintable(memory[j])) /* printable char */
                {
                    __Console_printByte(0xFF & (memory[j]));
                }
                else /* other char */
                {
                    __Console_printByte('.');
                }
            }
            __Console_printByte('\n');
        }
    }
}

void System_Console_printHexString(__String hexString) {
    if (!hexString || !hexString->length || !hexString->value) return;

    System_Console_printHex(hexString->length, hexString->value);
}

void System_Console_printLineEmpty() {
    ISO_fprintf(ISO_stdout, "\n");
}

void System_Console_printLine(__string8 format, ...) {
    __assert(format)

    __arguments args;
    __arguments_start(args, (void *)format);
    ISO_vfprintf(ISO_stdout, format, args);
    __arguments_end(args);

    System_Console_printLineEmpty();
}

void System_Console_printStringLine(__String format, ...) {
    __arguments args;

    __arguments_start(args, (void *)format);
    System_Console_printString(format, args);
    __arguments_end(args);

    System_Console_printLineEmpty();
}

#endif
