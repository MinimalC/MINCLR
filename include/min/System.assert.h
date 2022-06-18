/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#include "System.stddef.h"
#endif
#if !defined(have_System_assert)
#define have_System_assert

__export void  System_assert4(const System_string8 assertion, const System_string8 file,
    const System_uint32 line, const System_string8 functionName);

__export void  System_debug5(const System_string8 assertion, const System_string8 file,
    const System_uint32 line, const System_string8 functionName, const System_string8 message);

#if !__DEBUG
#define System_assert(expression)  (void)(expression);
#define static_System_assert(expression, diagnostic)
#define System_debug(expression,message)

#else
#define System_assert(expression)  if (!(expression)) { System_assert4((System_string8)(#expression),\
    (System_string8)__FILE__, (System_uint32)__LINE__, (System_string8)__func__); }

#define static_System_assert(expression, diagnostic)  extern int (*__Static_assert_function (void)) \
    [!!sizeof(struct { int __error_if_negative: (expression) ? 2 : -1; })]

#define System_debug(expression,message)  { System_debug5((System_string8)(#expression),\
    (System_string8)__FILE__, (System_uint32)__LINE__, (System_string8)__func__, (System_string8)(message)); }
#endif

#if defined(using_System)
#define __assert  System_assert
#define __debug  System_debug
#endif

#endif
