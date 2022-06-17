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

struct_System_String  STRING_System_Console = const_System_String("System.Console");

struct_System_Type  System_ConsoleType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Console,
};

void  System_Console_sync() {
    /* ISO_fflush(ISO_stdout); */
    System_Syscall_fsync(System_File_special_STDOUT);
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
            __Console_print("%s", exception->base.Type->name->value);
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
    __Syscall_write(__File_special_STDOUT, string, __string8_get_Length(string));
}

struct_string8 WARNING = "WARNING! ";

void  System_Console_writeSuffix__arguments(__string8 format, __char8 suffix, __arguments args) {
    __size argc = __argument(args, __size); /* this is expecting a size as first argument or null */
    if (argc > 16) { argc = 0;
        __Syscall_write(__File_special_STDOUT, WARNING, sizeof(WARNING)); /* TODO: Console_warning */
    }

    __size i;
    __char8  message[519] = { }; __string8 m = message;
    __char8  scratch[100] = { };
    for (i = 0; i < sizeof(message); ++i) message[i] = 0;
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;

    // just don't write everything else

    __size format_length = __string8_get_Length(format);
    if (format_length > 512) { format_length = 512;
        __Syscall_write(__File_special_STDOUT, WARNING, sizeof(WARNING)); /* TODO: Console_warning */
    }

    __size message_position = 0, n = 0, begin, end, argi, speci;
    do {
        __string8_copySubstringToAt(format, format_length, message, message_position);

        /* Reading up to the begin'ning { and the end'ing } */
        begin = 0; end = 0; argi = 0;
        for (n = 0; n < format_length; ++n) {
            if (message[n] != '{') continue;
            if (n > 0 && message[n - 1] == '\\') continue;
            begin = n;
            for (++n; n < format_length; ++n) {
                if (message[n] != '}') continue;
                end = n;
                break;
            }
            break;
        }
        if (begin) {
            if (!end) {
                __Syscall_write(__File_special_STDOUT, WARNING, sizeof(WARNING)); /* TODO: Console_warning */
            }

            m = message + begin + 1;
            argi = System_string8_touint16base10(m);

            /* Reading up to the begin'ning : and obj str char int bool bin oct dec hex float double */
            n = begin + 2; begin = 0; end = 0; speci = 0;
            for (; n < format_length; ++n) {
                if (message[n] != ':') continue;
                begin = n;
                for (++n; n < format_length; ++n) {
                    if (__char8_isAlpha(message[n])) continue;
                    end = n;
                    break;
                }
                break;
            }
            if (begin) {
                if (!end) {
                    __Syscall_write(__File_special_STDOUT, WARNING, sizeof(WARNING)); /* TODO: Console_warning */
                }

                m = message + begin + 1;
                if (__string8_compareSubstring(m, "object", sizeof("object")) >= 3) {

                    __string8_copyToAt("object", message, ++format_length);
                    format_length += sizeof("object");
                }
                else if (__string8_compareSubstring(m, "string", sizeof("string")) >= 3) {

                    __string8_copyToAt("string", message, ++format_length);
                    format_length += sizeof("string");
                }
                else if (__string8_compareSubstring(m, "character", sizeof("character")) >= 4) {

                    __string8_copyToAt("character", message, ++format_length);
                    format_length += sizeof("character");
                }
                else if (__string8_compareSubstring(m, "integer", sizeof("integer")) >= 3) {

                    __string8_copyToAt("integer", message, ++format_length);
                    format_length += sizeof("integer");
                }
                else if (__string8_compareSubstring(m, "boolean", sizeof("boolean")) >= 4) {

                    __string8_copyToAt("boolean", message, ++format_length);
                    format_length += sizeof("boolean");
                }
                else if (__string8_compareSubstring(m, "binary", sizeof("binary")) >= 3) {

                    __string8_copyToAt("binary", message, ++format_length);
                    format_length += sizeof("binary");
                }
                else if (__string8_compareSubstring(m, "octal", sizeof("octal")) >= 3) {

                    __string8_copyToAt("octal", message, ++format_length);
                    format_length += sizeof("octal");
                }
                else if (__string8_compareSubstring(m, "decimal", sizeof("decimal")) >= 3) {

                    __string8_copyToAt("decimal", message, ++format_length);
                    format_length += sizeof("decimal");
                }
                else if (__string8_compareSubstring(m, "hexadecimal", sizeof("hexadecimal")) >= 3) {

                    __string8_copyToAt("hexadecimal", message, ++format_length);
                    format_length += sizeof("hexadecimal");
                }
                else {
                    __Syscall_write(__File_special_STDOUT, WARNING, sizeof(WARNING)); /* TODO: Console_warning */
                }
            }
        }


    } while (0);

    /* DEBUG: Write argc */
    System_uint64_tostring8base10__stack(argc, scratch);
    __string8_copyToAt(scratch, message, ++format_length);
    format_length += System_uint64_string8base10Length_DEFAULT;

    if (suffix) message[format_length++] = suffix;

    __Syscall_write(__File_special_STDOUT, message, format_length);
}

void  System_Console_write(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_Console_writeSuffix__arguments(format, 0x00, args);
    __arguments_end(args);
}

void  System_Console_writeLine(__string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_Console_writeSuffix__arguments(format, '\n', args);
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
