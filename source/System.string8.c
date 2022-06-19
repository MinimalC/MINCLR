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
        System_IStream_write(stream, sizeof(WARNING), WARNING);
    }

    __size i;
    __char8  message[519] = { }; __string8 m = message;
    __char8  scratch[100] = { };
    for (i = 0; i < sizeof(message); ++i) message[i] = 0;
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;

    // just don't write everything else

    __size format_length = __string8_get_Length(format);
    if (format_length > 512) { format_length = 512;
        System_IStream_write(stream, sizeof(WARNING), WARNING);
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
                System_IStream_write(stream, sizeof(WARNING), WARNING);
            }

            m = message + begin + 1;
            argi = System_string8_touint16base10(m);

            /* DEBUG: Write argi */
            System_uint16_tostring8base10__stack(argi, scratch);
            __string8_copyToAt(scratch, message, ++format_length);
            format_length += System_uint16_string8base10Length_DEFAULT;

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
                    System_IStream_write(stream, sizeof(WARNING), WARNING); /* TODO: Console_warning */
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
                    System_IStream_write(stream, sizeof(WARNING), WARNING); /* TODO: Console_warning */
                }
            }
        }


    } while (0);

    /* DEBUG: Write argc */
    System_uint64_tostring8base10__stack(argc, scratch);
    __string8_copyToAt(scratch, message, ++format_length);
    format_length += System_uint64_string8base10Length_DEFAULT;

    if (suffix) message[format_length++] = suffix;

    System_IStream_write(stream, format_length, message);
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
