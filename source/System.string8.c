#if !defined(have_System)
#include "System.internal.h"
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

struct_System_Type  System_string8Type = { .base = stack_System_Object(System_Type),
    .name = "System.string8"
};

struct_System_string8  System_string8_Empty = "";

__size  System_string8_indexOf(__string8 that, __uint8 character){
    __size i = 0, len = __string8_get_Length(that);
    if (len == 0) return 0;
    do {
        if (that[i] == character) return i + 1;
    } while ( ++i < len );
    return 0;
}

__size  System_string8_lastIndexOf(__string8 that, __uint8 character) {
    __size i = __string8_get_Length(that);
    if (i == 0) return 0;
    do {
        if (that[--i] == character) return i + 1;
    } while ( i );
    return 0;
}

__size  System_string8_get_Length(__string8 that) {
    __size i = 0;
    while (that[i]) ++i;
    return i;
}

/* __size  System_string8_get_Length__max(__string8 that, __size count) {
    __size i = 0;
    while (count && that[i]) { ++i; --count; }
    return i;
} */


void  System_string8_copyTo(__string8 src, __string8 dest) {
    __size count = __string8_get_Length(src);
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copyToAt(__string8 src, __string8 dest, __size at) {
    __size count = __string8_get_Length(src);
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copySubstringTo(__string8 src, __size count, __string8 dest) {
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_string8_copySubstringToAt(__string8 src, __size count, __string8 dest, __size at) {
    if (at) dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

__string8  System_string8_clone(__string8 that) {
    __size count = __string8_get_Length(that);
    if (!count) return __null;
    __string8 dest = __Memory_alloc(count);
    __string8_copyTo(that, dest);
    return dest;
}

__size  System_string8_compare(__string8 that, __string8 other) {
    __size count = 0;
    while ( ( *that ) && ( *that == *other ) ) {
        ++that; ++other; ++count;
    }
    return count;
}

__bool  System_string8_equals(__string8 that, __string8 other) {
    __size length = __string8_get_Length(other);
    return length == __string8_compare(that, other);
}

__size  System_string8_compareSubstring(__string8 that, __string8 other, __size length) {
    __size count = 0;
    while ( *that && length && ( *that == *other ) ) {
        ++that; ++other; --length; ++count;
    }
    return count;
}

__bool  System_string8_equalsSubstring(__string8 that, __string8 other, __size length) {
    return length == __string8_compareSubstring(that, other, length);
}

__bool  System_string8_isNullOrEmpty(__string8 that) {
    return !that || that[0] == '\0';
}


struct_string8 WARNING = "WARNING! ";

void  System_string8_formatSuffixTo__arguments(__string8 format, __char8 suffix, __IStream stream, __arguments args) {
    __size argc = __argument(args, __size); /* this is expecting a size as first argument or null */
    if (argc > 16) { argc = 0;
        WARNING[8] = '0';
        System_IStream_write(stream, sizeof(WARNING) - 1, WARNING);
    }
    __var argv[16] = { 0 };
    __size i;
    for (i = 0; i < argc; ++i) {
        argv[i] = __argument(args, __var);
    }

    __char8  message[519] = { 0 };
    __char8  scratch[100] = { 0 };
    for (i = 0; i < sizeof(message); ++i) message[i] = 0;
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;

    // just don't write everything else

    __size format_length = __string8_get_Length(format);
    if (format_length > 512) { format_length = 512;
        WARNING[8] = '1';
        System_IStream_write(stream, sizeof(WARNING) - 1, WARNING);
    }

    __string8 f = format;
    __string8 m = message;
    __size message_length = 0, argi, argsize, target, numbers;
    while (1) {
        if (format_length == 0) break;

        __string8_copySubstringToAt(format, format_length, message, message_length);
        if (format_length <= 4) {
            message_length += format_length;
            break;
        }

        /* Read { to } */
        __string8 begin0 = 0, end0 = 0;
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
            WARNING[8] = '2';
            System_IStream_write(stream, sizeof(WARNING) - 1, WARNING);
        }
        message_length += (begin0 - format);

        argi = System_string8_touint16base10(begin0 + 1);

        /* DEBUG
        System_uint16_tostring8base10__stack(argi, scratch);
        __string8_copyToAt(scratch, message, message_length);
        message_length += System_uint16_string8base10Length_DEFAULT; */

        if (argi >= argc) {
            WARNING[8] = '3';
            System_IStream_write(stream, sizeof(WARNING) - 1, WARNING);
        }
        else {

            /* Read :obj :str :bool :char :int :uint :decimal :float :double */
            /* Also read 8, 16, 24, 32, 48, 64 */
            __string8 begin1 = 0, begin2 = 0, end1 = 0, end2 = 0; argsize = 0;
            for (f = begin0 + 2; f < (format + format_length); ++f) {
                if (*f != ':') continue;
                for (begin1 = ++f; f < (format + format_length); ++f) {
                    if (!__char8_isAlpha(*f)) break;
                    end1 = f;
                }
                if (!end1) { begin1 = 0; break; }
                for (begin2 = f; f < (format + format_length); ++f) {
                    if (!__char8_isNumber(*f)) break;
                    end2 = f;
                }
                if (!end2) begin2 = 0;
                break;
            }
            /* Read :bin :oct :dec :hex */
            __string8 begin3 = 0, end3 = 0; target = 10;
            if (!end2 && end1) end2 = end1;
            if (end2) {
                for (f = end2 + 1; f < (format + format_length); ++f) {
                    if (*f != ':') continue;
                    for (begin3 = ++f; f < (format + format_length); ++f) {
                        if (!__char8_isAlpha(*f)) break;
                        end3 = f;
                    }
                    if (!end3) begin3 = 0;
                    break;
                }
                if (begin3) {
                    if (__string8_compareSubstring(begin3, "binary", sizeof("binary") - 1) >= 3) {
                        target = 2;
                        /* DEBUG
                        __string8_copyToAt(":binary", message, message_length);
                        message_length += sizeof(":binary") - 1; */
                    }
                    else if (__string8_compareSubstring(begin3, "octal", sizeof("octal") - 1) >= 3) {
                        target = 8;
                        /* DEBUG
                        __string8_copyToAt(":octal", message, message_length);
                        message_length += sizeof(":octal") - 1; */
                    }
                    else if (__string8_compareSubstring(begin3, "decimal", sizeof("decimal") - 1) >= 3) {
                        target = 10;
                        /* DEBUG
                        __string8_copyToAt(":decimal", message, message_length);
                        message_length += sizeof(":decimal") - 1; */
                    }
                    else if (__string8_compareSubstring(begin3, "hexadecimal", sizeof("hexadecimal") - 1) >= 3) {
                        target = 16;
                        /* DEBUG
                        __string8_copyToAt(":hexadecimal", message, message_length);
                        message_length += sizeof(":hexadecimal") - 1; */
                    }
                }
            }
            if (!begin1) {
                WARNING[8] = '4';
                System_IStream_write(stream, sizeof(WARNING) - 1, WARNING); /* TODO: Console_warning */
            }
            else {
                if (begin2) {
                    argsize = System_string8_touint16base10(begin2);

                    /* DEBUG: Write argsize
                    System_uint16_tostring8base10__stack(argsize, scratch);
                    __string8_copyToAt(scratch, message, message_length);
                    message_length += System_uint16_string8base10Length_DEFAULT; */
                }

                if (__string8_compareSubstring(begin1, "object", sizeof("object") - 1) >= 3) {
                    /* DEBUG */
                    __string8_copyToAt("object", message, message_length);
                    message_length += sizeof("object") - 1;
                }
                else if (__string8_compareSubstring(begin1, "character", sizeof("character") - 1) >= 4) {
                    /* DEBUG */
                    __string8_copyToAt("character", message, message_length);
                    message_length += sizeof("character") - 1;
                }
                else if (__string8_compareSubstring(begin1, "string", sizeof("string") - 1) >= 3) {

                    __string8_copyToAt((__string8)argv[argi], message, message_length);
                    message_length += __string8_get_Length(argv[argi]);
                }
                else if (__string8_compareSubstring(begin1, "decimal", sizeof("decimal") - 1) >= 3) {
                    /* DEBUG */
                    __string8_copyToAt("decimal", message, message_length);
                    message_length += sizeof("decimal") - 1;
                }
                else if (__string8_compareSubstring(begin1, "boolean", sizeof("boolean") - 1) >= 4) {

                    if (argv[argi]) {
                        __string8_copyToAt("true", message, message_length);
                        message_length += sizeof("true") - 1;
                    }
                    else {
                        __string8_copyToAt("false", message, message_length);
                        message_length += sizeof("false") - 1;
                    }
                }
                else if (__string8_compareSubstring(begin1, "integer", sizeof("integer") - 1) >= 3) {

                    if (!argsize) argsize = 64; /* TODO: System_wordSize */
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
                        WARNING[8] = '5';
                        System_IStream_write(stream, sizeof(WARNING) - 1, WARNING); /* TODO: Console_warning */
                        argsize = 64;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_int64_tostring8base16__stack((__int64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int64_tostring8base10__stack((__int64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int64_tostring8base8__stack((__int64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int64_tostring8base2__stack((__int64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_int32_tostring8base16__stack((__int32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int32_tostring8base10__stack((__int32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int32_tostring8base8__stack((__int32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int32_tostring8base2__stack((__int32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_int16_tostring8base16__stack((__int16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int16_tostring8base10__stack((__int16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int16_tostring8base8__stack((__int16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int16_tostring8base2__stack((__int16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_int8_tostring8base16__stack((__int8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_int8_tostring8base10__stack((__int8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_int8_tostring8base8__stack((__int8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_int8_tostring8base2__stack((__int8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else if (__string8_compareSubstring(begin1, "uinteger", sizeof("uinteger") - 1) >= 4
                      || __string8_equalsSubstring(begin1, "unsigned", sizeof("unsigned") - 1))
                {
                    if (!argsize) argsize = 64; /* TODO: System_wordSize */
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
                        WARNING[8] = '6';
                        System_IStream_write(stream, sizeof(WARNING) - 1, WARNING); /* TODO: Console_warning */
                        argsize = 64;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = System_uint64_tostring8base16__stack((__uint64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint64_tostring8base10__stack((__uint64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint64_tostring8base8__stack((__uint64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint64_tostring8base2__stack((__uint64)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = System_uint32_tostring8base16__stack((__uint32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint32_tostring8base10__stack((__uint32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint32_tostring8base8__stack((__uint32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint32_tostring8base2__stack((__uint32)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = System_uint16_tostring8base16__stack((__uint16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint16_tostring8base10__stack((__uint16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint16_tostring8base8__stack((__uint16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint16_tostring8base2__stack((__uint16)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = System_uint8_tostring8base16__stack((__uint8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = System_uint8_tostring8base10__stack((__uint8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = System_uint8_tostring8base8__stack((__uint8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = System_uint8_tostring8base2__stack((__uint8)(__size)argv[argi], scratch);
                            __string8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else {
                    WARNING[8] = '7';
                    System_IStream_write(stream, sizeof(WARNING) - 1, WARNING); /* TODO: Console_warning */
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

    /* DEBUG: Write argc
    System_uint64_tostring8base10__stack(argc, scratch);
    __string8_copyToAt(scratch, message, message_length);
    message_length += System_uint64_string8base10Length_DEFAULT; */

    if (suffix) message[message_length++] = (suffix == 0x01 ? 0x00 : suffix);

    System_IStream_write(stream, message_length, message);
}


__uint16  System_string8_touint16base10(__string8 that) {

    __uint16 reture = 0;
    if (!__char8_isNumber(that[0])) return reture;

    __size count = 1, n = 0;
    while (count < 5 && __char8_isNumber(that[count])) ++count;
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
