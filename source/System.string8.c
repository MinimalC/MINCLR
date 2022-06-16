#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_string8)
#define code_System_string8

/*# System_string8 #*/

/* static class System.string8 */

struct_System_String  STRING_System_string8 = const_System_String("System.string8");

struct_System_Type  System_string8Type = { .base = stack_System_Object(System_Type),
    .name = &STRING_System_string8
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

__size  System_string8_compare(__string8 that, __string8 other){
    while ( ( *that ) && ( *that == *other ) ) {
        ++that; ++other;
    }
    return ( *that - *other );
}

__bool  System_string8_equals(__string8 that, __string8 other) {
    return 0 == __string8_compare(that, other);
}

__size  System_string8_compareSubstring(__string8 that, __string8 other, __size count) {
    while ( *that && count && ( *that == *other ) ) {
        ++that; ++other; --count;
    }
    if ( 0 == count ) return 0;
    return ( *that - *other );
}

__bool  System_string8_equalsSubstring(__string8 that, __string8 other, __size count) {
    return 0 == __string8_compareSubstring(that, other, count);
}

__bool  System_string8_isNullOrEmpty(__string8 that) {
    return !that || that[0] == '\0';
}

#endif
