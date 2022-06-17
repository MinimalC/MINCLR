#if !defined(have_System_stddef)
#warning "System.stddef.h not included"
#include "System.stddef.h"
#endif
#if !defined(have_System_char8)
#include "System.char8.h"
#endif
#if !defined(have_System_string8)
#define have_System_string8

__export System_size  System_string8_indexOf(System_string8 that, System_uint8 character);
__export System_size  System_string8_lastIndexOf(System_string8 that, System_uint8 character);
__export System_size  System_string8_get_Length(System_string8 that);
__export System_void  System_string8_copyTo(System_string8 src, System_string8 dest);
__export System_void  System_string8_copyToAt(System_string8 src, System_string8 dest, System_size at);
__export System_void  System_string8_copySubstringTo(System_string8 src, System_size count, System_string8 dest);
__export System_void  System_string8_copySubstringToAt(System_string8 src, System_size count, System_string8 dest, System_size at);
__export System_string8  System_string8_clone(System_string8 that);
__export System_size  System_string8_compare(System_string8 that, System_string8 other);
__export System_boolean  System_string8_equals(System_string8 that, System_string8 other);
__export System_size  System_string8_compareSubstring(System_string8 that, System_string8 other, System_size count);
__export System_boolean  System_string8_equalsSubstring(System_string8 that, System_string8 other, System_size count);
__export System_boolean  System_string8_isNullOrEmpty(System_string8 that);
//__export System_boolean  System_string8_startsWith(System_string8 that, String_string8 other);

__export System_uint16  System_string8_touint16base10(System_string8 that);

#define inline_System_string8_equals(chars0, chars1)  (0 == System_string8_compare(chars0, chars1))
#define inline_System_string8_equalsSubstring(chars0, chars1, n)  (0 == System_string8_compareSubstring(chars0, chars1, n))

#if defined(using_System)
#define __string8_lastIndexOf  System_string8_lastIndexOf
#define __string8_indexOf  System_string8_indexOf
#define __string8_get_Length  System_string8_get_Length
#define __string8_copyTo  System_string8_copyTo
#define __string8_copyToAt  System_string8_copyToAt
#define __string8_copySubstringTo  System_string8_copySubstringTo
#define __string8_copySubstringToAt  System_string8_copySubstringToAt
#define __string8_clone  System_string8_clone
#define __string8_compare  System_string8_compare
#define __string8_equals  System_string8_equals
#define __string8_equalsSubstring  System_string8_equalsSubstring
#define __string8_compareIgnoreCase  System_string8_compareIgnoreCase
#define __string8_compareSubstring  System_string8_compareSubstring
#define __string8_isNullOrEmpty  System_string8_isNullOrEmpty
#endif

#endif
