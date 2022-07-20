/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_string8)
#include <min/System.string8.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_int64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_char8)
#define code_System_char8
/*# System_char8 #*/
System_boolean  System_char8_isNumber(System_char8 that) {
    return (that >= 0x30 && that <= 0x39);
}
System_boolean  System_char8_isUpper(System_char8 that) {
    return (that >= 0x41 && that <= 0x5A);
}
System_boolean  System_char8_isLower(System_char8 that) {
    return (that >= 0x61 && that <= 0x7A);
}
System_boolean  System_char8_isAlpha(System_char8 that) {
    return System_char8_isUpper(that) || System_char8_isLower(that);
}
System_boolean  System_char8_isAlphaNumeric(System_char8 that) {
    return System_char8_isAlpha(that) || System_char8_isNumber(that);
}
System_boolean  System_char8_isHexNumber(System_char8 that) {
    return (that >= 0x30 && that <= 0x39) || (that >= 0x41 && that <= 0x46) || (that >= 0x61 && that <= 0x66);
}
System_boolean  System_char8_isWhiteSpace(System_char8 that) {
    return that == 0x20 || that == 0x0c || that == 0x0a || that == 0x0d || that == 0x09 || that == 0x0b;
}
System_boolean  System_char8_isControl(System_char8 that) {
    return (that >= 0x00 && that <= 0x1F) || that == 0x7F;
}
System_boolean  System_char8_isPunctuation(System_char8 that) {
    return (that >= 0x21 && that <= 0x2F) || (that >= 0x3A && that <= 0x40) || (that >= 0x5B && that <= 0x60) || (that >= 0x7B && that <= 0x7E);
}
System_boolean  System_char8_isPrintable(System_char8 that) {
    return System_char8_isAlphaNumeric(that) || System_char8_isPunctuation(that);
}
#endif
#if !defined(code_System_string8)
#define code_System_string8

/*# System_string8 #*/

/* static class System.string8 */

struct System_Type  System_string8Type = { .base = stack_System_Object(System_Type),
    .name = "System.string8"
};

System_STRING8  System_string8_Empty = "";

size  System_string8_indexOf(string8 that, uint8 character){
    size i = 0, len = string8_get_Length(that);
    if (len == 0) return 0;
    do {
        if (that[i] == character) return i + 1;
    } while ( ++i < len );
    return 0;
}

size  System_string8_lastIndexOf(string8 that, uint8 character) {
    size i = string8_get_Length(that);
    if (i == 0) return 0;
    do {
        if (that[--i] == character) return i + 1;
    } while ( i );
    return 0;
}

size  System_string8_get_Length(string8 that) {
    size i = 0;
    while (that[i]) ++i;
    return i;
}

/* size  System_string8_get_Length__max(string8 that, size count) {
    size i = 0;
    while (count && that[i]) { ++i; --count; }
    return i;
} */


void  System_string8_copyTo(string8 src, string8 dest) {
    size count = string8_get_Length(src);
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copyToAt(string8 src, string8 dest, size at) {
    size count = string8_get_Length(src);
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copySubstringTo(string8 src, size count, string8 dest) {
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copySubstringToAt(string8 src, size count, string8 dest, size at) {
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

string8  System_string8_clone(string8 that) {
    size count = string8_get_Length(that);
    if (!count) return null;
    string8 dest = (string8)System_Memory_allocArray(typeof(System_char8), count);
    string8_copyTo(that, dest);
    return dest;
}

size  System_string8_compare(string8 that, string8 other) {
    size count = 0;
    while ( ( *that ) && ( *that == *other ) ) {
        ++that; ++other; ++count;
    }
    return count;
}

bool  System_string8_equals(string8 that, string8 other) {
    size length = string8_get_Length(other);
    return length == string8_compare(that, other);
}

size  System_string8_compareSubstring(string8 that, string8 other, size length) {
    size count = 0;
    while ( *that && length && ( *that == *other ) ) {
        ++that; ++other; --length; ++count;
    }
    return count;
}

bool  System_string8_equalsSubstring(string8 that, string8 other, size length) {
    return length == string8_compareSubstring(that, other, length);
}

bool  System_string8_isNullOrEmpty(string8 that) {
    return !that || that[0] == '\0';
}

#if DEBUG
STRING8 WARNING = "WARNING  \0";
#endif


size  stack_System_string8_format(string8 format, char8 message[System_string8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_string8_formatEnd__arguments(format, 0, message, argc, argv);
}

size  stack_System_string8_formatLine(string8 format, char8 message[System_string8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_string8_formatEnd__arguments(format, '\n', message, argc, argv);
}

size  stack_System_string8_formatEnd(string8 format, char8 suffix, char8 message[System_string8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_string8_formatEnd__arguments(format, suffix, message, argc, argv);
}

size  stack_System_string8_formatEnd__arguments(string8 format, char8 suffix, char8 message[System_string8_formatLimit_VALUE], size argc, var argv[]) {
    return stack_System_string8_formatEnd__limit_arguments(format, suffix, System_string8_formatLimit_VALUE, message, argc, argv);
}

size  stack_System_string8_formatEnd__limit_arguments(string8 format, char8 suffix, size limit, char8 message[], size argc, var argv[]) {
    Console_assert(!argc || argv);

    size i;
    char8  scratch[100] = { 0 };
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;

    // just don't write everything else

    size format_length = string8_get_Length(format);
    if (format_length > (limit - 5)) { format_length = limit - 5;
#if DEBUG
        WARNING[7] = '1';
        System_Console_write__string8(WARNING);
#endif
    }

    string8 f = format;
    string8 m = message;
    size message_length = 0, argi, argsize, target, numbers;
    while (1) {
        if (format_length == 0) break;

        string8_copySubstringToAt(format, format_length, message, message_length);
        if (format_length <= 4) {
            message_length += format_length;
            break;
        }

        /* Read { to } */
        string8 begin0 = 0, end0 = 0;
        for (; f < (format + format_length); ++f) {
            if (*f != '{') continue;
            if (f > format && *(f - 1) == '\\') continue;
            begin0 = f;
            for (; f < (format + format_length); ++f) {
                if (*f != '}') continue;
                end0 = f;
                break;
            }
            break;
        }
        if (!begin0) {
            message_length += format_length;
            break;
        }
        if (!end0) {
#if DEBUG == DEBUG_System_string8_format
            WARNING[7] = '2';
            System_Console_write__string8(WARNING);
#endif
        }
        message_length += (begin0 - format);

        argi = System_uint16_parsebase10(begin0 + 1);

        /* DEBUG
        System_uint16_tostring8base10__stack(argi, scratch);
        string8_copyToAt(scratch, message, message_length);
        message_length += System_uint16_string8base10Length_DEFAULT; */

        if (argi >= argc) {
#if DEBUG == DEBUG_System_string8_format
            WARNING[7] = '3';
            System_Console_write__string8(WARNING);
#endif
        }
        else {
            /* Read :obj :str :bool :char :int :uint :decimal :float :double */
            /* Also read 8, 16, 24, 32, 48, 64 */
            string8 begin1 = 0, begin2 = 0, end1 = 0, end2 = 0; argsize = 0;
            for (f = begin0 + 2; f < (format + format_length); ++f) {
                if (*f != ':') continue;
                for (begin1 = ++f; f < (format + format_length); ++f) {
                    if (!char8_isAlpha(*f)) break;
                    end1 = f;
                }
                if (!end1) { begin1 = 0; break; }
                for (begin2 = f; f < (format + format_length); ++f) {
                    if (!char8_isNumber(*f)) break;
                    end2 = f;
                }
                if (!end2) begin2 = 0;
                break;
            }
            /* Read :bin :oct :dec :hex */
            string8 begin3 = 0, end3 = 0; target = 10;
            if (!end2 && end1) end2 = end1;
            if (end2) {
                for (f = end2 + 1; f < (format + format_length); ++f) {
                    if (*f != ':') continue;
                    for (begin3 = ++f; f < (format + format_length); ++f) {
                        if (!char8_isAlpha(*f)) break;
                        end3 = f;
                    }
                    if (!end3) begin3 = 0;
                    break;
                }
                if (begin3) {
                    if (string8_compareSubstring(begin3, "binary", sizeof("binary") - 1) >= 3) {
                        target = 2;
                        /* DEBUG
                        string8_copyToAt(":binary", message, message_length);
                        message_length += sizeof(":binary") - 1; */
                    }
                    else if (string8_compareSubstring(begin3, "octal", sizeof("octal") - 1) >= 3) {
                        target = 8;
                        /* DEBUG
                        string8_copyToAt(":octal", message, message_length);
                        message_length += sizeof(":octal") - 1; */
                    }
                    else if (string8_compareSubstring(begin3, "decimal", sizeof("decimal") - 1) >= 3) {
                        target = 10;
                        /* DEBUG
                        string8_copyToAt(":decimal", message, message_length);
                        message_length += sizeof(":decimal") - 1; */
                    }
                    else if (string8_compareSubstring(begin3, "hexadecimal", sizeof("hexadecimal") - 1) >= 3) {
                        target = 16;
                        /* DEBUG
                        string8_copyToAt(":hexadecimal", message, message_length);
                        message_length += sizeof(":hexadecimal") - 1; */
                    }
                }
            }
            if (!begin1) {
#if DEBUG == DEBUG_System_string8_format
                WARNING[7] = '4';
                System_Console_write__string8(WARNING);
#endif
            }
            else {
                if (begin2) {
                    argsize = System_uint16_parsebase10(begin2);

                    /* DEBUG: Write argsize
                    System_uint16_tostring8base10__stack(argsize, scratch);
                    string8_copyToAt(scratch, message, message_length);
                    message_length += System_uint16_string8base10Length_DEFAULT; */
                }

                if (string8_compareSubstring(begin1, "object", sizeof("object") - 1) >= 3) {
                    /* DEBUG */
                    string8_copyToAt("object", message, message_length);
                    message_length += sizeof("object") - 1;
                }
                else if (string8_compareSubstring(begin1, "character", sizeof("character") - 1) >= 4) {
                    /* DEBUG */
                    string8_copyToAt("character", message, message_length);
                    message_length += sizeof("character") - 1;
                }
                else if (string8_compareSubstring(begin1, "string", sizeof("string") - 1) >= 3) {

                    string8_copyToAt((string8)argv[argi], message, message_length);
                    message_length += string8_get_Length(argv[argi]);
                }
                else if (string8_compareSubstring(begin1, "decimal", sizeof("decimal") - 1) >= 3) {
                    /* DEBUG */
                    string8_copyToAt("decimal", message, message_length);
                    message_length += sizeof("decimal") - 1;
                }
                else if (string8_compareSubstring(begin1, "boolean", sizeof("boolean") - 1) >= 4) {

                    if (argv[argi]) {
                        string8_copyToAt("true", message, message_length);
                        message_length += sizeof("true") - 1;
                    }
                    else {
                        string8_copyToAt("false", message, message_length);
                        message_length += sizeof("false") - 1;
                    }
                }
                else if (string8_compareSubstring(begin1, "integer", sizeof("integer") - 1) >= 3) {

                    if (!argsize) argsize = System_size_Width;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_string8_format
                        WARNING[7] = '5';
                        System_Console_write__string8(WARNING);
#endif
                        argsize = System_size_Width;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_int64_tostring8base16__stack((int64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int64_tostring8base10__stack((int64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int64_tostring8base8__stack((int64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int64_tostring8base2__stack((int64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_int32_tostring8base16__stack((int32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int32_tostring8base10__stack((int32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int32_tostring8base8__stack((int32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int32_tostring8base2__stack((int32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_int16_tostring8base16__stack((int16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int16_tostring8base10__stack((int16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int16_tostring8base8__stack((int16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int16_tostring8base2__stack((int16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_int8_tostring8base16__stack((int8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int8_tostring8base10__stack((int8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int8_tostring8base8__stack((int8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int8_tostring8base2__stack((int8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else if (string8_compareSubstring(begin1, "uinteger", sizeof("uinteger") - 1) >= 4
                      || string8_equalsSubstring(begin1, "unsigned", sizeof("unsigned") - 1))
                {
                    if (!argsize) argsize = System_size_Width;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_string8_format
                        WARNING[7] = '6';
                        System_Console_write__string8(WARNING);
#endif
                        argsize = System_size_Width;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_uint64_tostring8base16__stack((uint64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint64_tostring8base10__stack((uint64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint64_tostring8base8__stack((uint64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint64_tostring8base2__stack((uint64)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_uint32_tostring8base16__stack((uint32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint32_tostring8base10__stack((uint32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint32_tostring8base8__stack((uint32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint32_tostring8base2__stack((uint32)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_uint16_tostring8base16__stack((uint16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint16_tostring8base10__stack((uint16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint16_tostring8base8__stack((uint16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint16_tostring8base2__stack((uint16)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_uint8_tostring8base16__stack((uint8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint8_tostring8base10__stack((uint8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint8_tostring8base8__stack((uint8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint8_tostring8base2__stack((uint8)(size)argv[argi], scratch);
                            string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else {
#if DEBUG == DEBUG_System_string8_format
                    WARNING[7] = '7';
                    System_Console_write__string8(WARNING);
#endif
                }

            }
        }

        if (end0) {
            format_length -= (end0 - format) + 1;
            f = format = end0 + 1;
            continue;
        }

        break;
    }

    if (suffix) message[message_length++] = (suffix == 0x01 ? 0x00 : suffix);

    return message_length;
}

#endif
