/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Int64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_Char8)
#define code_System_Char8
/*# System_Char8 #*/
System_Bool  System_Char8_isNumber(System_Char8 that) {
    return (that >= 0x30 && that <= 0x39);
}
System_Bool  System_Char8_isUpper(System_Char8 that) {
    return (that >= 0x41 && that <= 0x5A);
}
System_Bool  System_Char8_isLower(System_Char8 that) {
    return (that >= 0x61 && that <= 0x7A);
}
System_Bool  System_Char8_isAlpha(System_Char8 that) {
    return System_Char8_isUpper(that) || System_Char8_isLower(that);
}
System_Bool  System_Char8_isAlphaNumeric(System_Char8 that) {
    return System_Char8_isAlpha(that) || System_Char8_isNumber(that);
}
System_Bool  System_Char8_isHexNumber(System_Char8 that) {
    return (that >= 0x30 && that <= 0x39) || (that >= 0x41 && that <= 0x46) || (that >= 0x61 && that <= 0x66);
}
System_Bool  System_Char8_isWhiteSpace(System_Char8 that) {
    return that == 0x20 || that == 0x0c || that == 0x0a || that == 0x0d || that == 0x09 || that == 0x0b;
}
System_Bool  System_Char8_isControl(System_Char8 that) {
    return (that >= 0x00 && that <= 0x1F) || that == 0x7F;
}
System_Bool  System_Char8_isPunctuation(System_Char8 that) {
    return (that >= 0x21 && that <= 0x2F) || (that >= 0x3A && that <= 0x40) || (that >= 0x5B && that <= 0x60) || (that >= 0x7B && that <= 0x7E);
}
System_Bool  System_Char8_isPrintable(System_Char8 that) {
    return System_Char8_isAlphaNumeric(that) || System_Char8_isPunctuation(that);
}
#endif
#if !defined(code_System_String8)
#define code_System_String8

/*# System_String8 #*/

/* static class System.String8 */

struct System_Type  System_String8Type = { .base = stack_System_Object(System_Type),
    .name = "String8"
};

System_STRING8  System_String8_Empty = "";

Size  System_String8_indexOf(String8 that, UInt8 character){
    Size i = 0, len = String8_get_Length(that);
    if (len == 0) return 0;
    do {
        if (that[i] == character) return i + 1;
    } while ( ++i < len );
    return 0;
}

Size  System_String8_lastIndexOf(String8 that, UInt8 character) {
    Size i = String8_get_Length(that);
    if (i == 0) return 0;
    do {
        if (that[--i] == character) return i + 1;
    } while ( i );
    return 0;
}

Size  System_String8_get_Length(String8 that) {
    return System_String8_get_Length__max(that, System_String8_MaxLength_VALUE);
}

System_Size  System_String8_get_Length__max(System_String8 that, System_Size limit) {
    Debug_assert(that);
    Size i = 0;
    while (limit && that[i]) { --limit; ++i; }
    return i;
}

void  System_String8_copyTo(String8 src, String8 dest) {
    Size count = String8_get_Length(src);
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copyToAt(String8 src, String8 dest, Size at) {
    Size count = String8_get_Length(src);
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copySubstringTo(String8 src, Size count, String8 dest) {
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copySubstringToAt(String8 src, Size count, String8 dest, Size at) {
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

String8  System_String8_clone(String8 that) {
    Size count = String8_get_Length(that);
    if (!count) return null;
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), count);
    String8_copyTo(that, dest);
    return dest;
}

Size  System_String8_compare(String8 that, String8 other) {
    Size count = 0;
    while ( ( *that ) && ( *that == *other ) ) {
        ++that; ++other; ++count;
    }
    return count;
}

Bool  System_String8_equals(String8 that, String8 other) {
    Size length = String8_get_Length(other);
    return length == String8_compare(that, other);
}

Size  System_String8_compareSubstring(String8 that, String8 other, Size length) {
    Size count = 0;
    while ( *that && length && ( *that == *other ) ) {
        ++that; ++other; --length; ++count;
    }
    return count;
}

Bool  System_String8_equalsSubstring(String8 that, String8 other, Size length) {
    return length == String8_compareSubstring(that, other, length);
}

Bool  System_String8_isNullOrEmpty(String8 that) {
    return !that || that[0] == '\0';
}

#if DEBUG
STRING8 WARNING = "WARNING  ";
#endif


Size  stack_System_String8_format(String8 format, Char8 message[System_String8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, 0, message, argc, argv);
}

Size  stack_System_String8_format__arguments(String8 format, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__arguments(format, 0, message, argc, argv);
}

Size  stack_System_String8_formatLine(String8 format, Char8 message[System_String8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, '\n', message, argc, argv);
}

Size  stack_System_String8_formatLine__arguments(String8 format, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__arguments(format, '\n', message, argc, argv);
}

Size  stack_System_String8_formatEnd(String8 format, Char8 suffix, Char8 message[System_String8_formatLimit_VALUE], ...) {
    arguments args;
    arguments_start(args, message);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
}

Size  stack_System_String8_formatEnd__arguments(String8 format, Char8 suffix, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__limit_arguments(format, suffix, System_String8_formatLimit_VALUE, message, argc, argv);
}

Size  stack_System_String8_formatEnd__limit_arguments(String8 format, Char8 suffix, Size limit, Char8 message[], Size argc, Var argv[]) {
    Debug_assert(!argc || argv);

    Size i;
    Char8  scratch[72];
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;

    // just don't write everything else

    Size format_length = String8_get_Length(format);
    if (format_length > (limit - 5)) { format_length = limit - 5;
#if DEBUG
        WARNING[7] = '1';
        System_Console_write__string(WARNING);
#endif
    }

    String8 f = format;
    String8 m = message;
    Size message_length = 0, argi, argsize, target, numbers;
    while (1) {
        if (format_length == 0) break;

        String8_copySubstringToAt(format, format_length, message, message_length);
        if (format_length <= 4) {
            message_length += format_length;
            break;
        }

        /* Read { to } */
        String8 begin0 = 0, end0 = 0;
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
#if DEBUG == DEBUG_System_String8_format
            WARNING[7] = '2';
            System_Console_write__string(WARNING);
#endif
        }
        message_length += (begin0 - format);

        argi = System_UInt16_parsebase10(begin0 + 1);

        /* DEBUG
        System_UInt16_toString8base10__stack(argi, scratch);
        String8_copyToAt(scratch, message, message_length);
        message_length += System_UInt16_String8base10Length_DEFAULT; */

        if (argi >= argc) {
#if DEBUG == DEBUG_System_String8_format
            WARNING[7] = '3';
            System_Console_write__string(WARNING);
#endif
        }
        else {
            /* Read :obj :str :bool :char :int :uint :decimal :float :double */
            /* Also read 8, 16, 24, 32, 48, 64 */
            String8 begin1 = 0, begin2 = 0, end1 = 0, end2 = 0; argsize = 0;
            for (f = begin0 + 2; f < (format + format_length); ++f) {
                if (*f != ':') continue;
                for (begin1 = ++f; f < (format + format_length); ++f) {
                    if (!Char8_isAlpha(*f)) break;
                    end1 = f;
                }
                if (!end1) { begin1 = 0; break; }
                for (begin2 = f; f < (format + format_length); ++f) {
                    if (!Char8_isNumber(*f)) break;
                    end2 = f;
                }
                if (!end2) begin2 = 0;
                break;
            }
            /* Read :bin :oct :dec :hex */
            String8 begin3 = 0, end3 = 0; target = 10;
            if (!end2 && end1) end2 = end1;
            if (end2) {
                for (f = end2 + 1; f < (format + format_length); ++f) {
                    if (*f != ':') continue;
                    for (begin3 = ++f; f < (format + format_length); ++f) {
                        if (!Char8_isAlpha(*f)) break;
                        end3 = f;
                    }
                    if (!end3) begin3 = 0;
                    break;
                }
                if (begin3) {
                    if (String8_compareSubstring(begin3, "binary", sizeof("binary") - 1) >= 3) {
                        target = 2;
                        /* DEBUG
                        String8_copyToAt(":binary", message, message_length);
                        message_length += sizeof(":binary") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "octal", sizeof("octal") - 1) >= 3) {
                        target = 8;
                        /* DEBUG
                        String8_copyToAt(":octal", message, message_length);
                        message_length += sizeof(":octal") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "decimal", sizeof("decimal") - 1) >= 3) {
                        target = 10;
                        /* DEBUG
                        String8_copyToAt(":decimal", message, message_length);
                        message_length += sizeof(":decimal") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "hexadecimal", sizeof("hexadecimal") - 1) >= 3) {
                        target = 16;
                        /* DEBUG
                        String8_copyToAt(":hexadecimal", message, message_length);
                        message_length += sizeof(":hexadecimal") - 1; */
                    }
                }
            }
            if (!begin1) {
#if DEBUG == DEBUG_System_String8_format
                WARNING[7] = '4';
                System_Console_write__string(WARNING);
#endif
            }
            else {
                if (begin2) {
                    argsize = System_UInt16_parsebase10(begin2);

                    /* DEBUG: Write argsize
                    System_UInt16_toString8base10__stack(argsize, scratch);
                    String8_copyToAt(scratch, message, message_length);
                    message_length += System_UInt16_String8base10Length_DEFAULT; */
                }

                if (String8_compareSubstring(begin1, "object", sizeof("object") - 1) >= 3) {
                    /* DEBUG */
                    String8_copyToAt("object", message, message_length);
                    message_length += sizeof("object") - 1;
                }
                else if (String8_compareSubstring(begin1, "character", sizeof("character") - 1) >= 4) {
                    /* DEBUG */
                    String8_copyToAt("character", message, message_length);
                    message_length += sizeof("character") - 1;
                }
                else if (String8_compareSubstring(begin1, "string", sizeof("string") - 1) >= 3) {

                    String8_copyToAt((String8)argv[argi], message, message_length);
                    message_length += String8_get_Length(argv[argi]);
                }
                else if (String8_compareSubstring(begin1, "decimal", sizeof("decimal") - 1) >= 3) {
                    /* DEBUG */
                    String8_copyToAt("decimal", message, message_length);
                    message_length += sizeof("decimal") - 1;
                }
                else if (String8_compareSubstring(begin1, "boolean", sizeof("boolean") - 1) >= 4) {

                    if (argv[argi]) {
                        String8_copyToAt("true", message, message_length);
                        message_length += sizeof("true") - 1;
                    }
                    else {
                        String8_copyToAt("false", message, message_length);
                        message_length += sizeof("false") - 1;
                    }
                }
                else if (String8_compareSubstring(begin1, "integer", sizeof("integer") - 1) >= 3) {

                    if (!argsize) argsize = System_Size_Width;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_String8_format
                        WARNING[7] = '5';
                        System_Console_write__string(WARNING);
#endif
                        argsize = System_Size_Width;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_Int64_toString8base16__stack((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_Int64_toString8base10__stack((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_Int64_toString8base8__stack((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_Int64_toString8base2__stack((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_Int32_toString8base16__stack((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_Int32_toString8base10__stack((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_Int32_toString8base8__stack((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_Int32_toString8base2__stack((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_Int16_toString8base16__stack((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_Int16_toString8base10__stack((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_Int16_toString8base8__stack((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_Int16_toString8base2__stack((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_Int8_toString8base16__stack((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_Int8_toString8base10__stack((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_Int8_toString8base8__stack((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_Int8_toString8base2__stack((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else if (String8_compareSubstring(begin1, "uinteger", sizeof("uinteger") - 1) >= 4
                      || String8_equalsSubstring(begin1, "unsigned", sizeof("unsigned") - 1))
                {
                    if (!argsize) argsize = System_Size_Width;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_String8_format
                        WARNING[7] = '6';
                        System_Console_write__string(WARNING);
#endif
                        argsize = System_Size_Width;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_UInt64_toString8base16__stack((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_UInt64_toString8base10__stack((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_UInt64_toString8base8__stack((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_UInt64_toString8base2__stack((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_UInt32_toString8base16__stack((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_UInt32_toString8base10__stack((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_UInt32_toString8base8__stack((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_UInt32_toString8base2__stack((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_UInt16_toString8base16__stack((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_UInt16_toString8base10__stack((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_UInt16_toString8base8__stack((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_UInt16_toString8base2__stack((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_UInt8_toString8base16__stack((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_UInt8_toString8base10__stack((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_UInt8_toString8base8__stack((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_UInt8_toString8base2__stack((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else {
#if DEBUG == DEBUG_System_String8_format
                    WARNING[7] = '7';
                    System_Console_write__string(WARNING);
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
