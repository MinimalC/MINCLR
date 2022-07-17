/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Crypto_SipHash48)
#define have_Crypto_SipHash48

/* static class Crypto.SipHash48 */

#define struct_Crypto_SipHash48  struct Crypto_SipHash48
typedef final fixed struct_Crypto_SipHash48 {
    struct_System_Object  base;

    System_uint64  v0;
    System_uint64  v1;
    System_uint64  v2;
    System_uint64  v3;

}  * Crypto_SipHash48;

#define stack_Crypto_SipHash48()  (struct_Crypto_SipHash48){ .base = stack_System_Object(Crypto_SipHash48),\
    .v0 = 0x736f6d6570736575ULL ,\
    .v1 = 0x646f72616e646f6dULL ,\
    .v2 = 0x6c7967656e657261ULL ,\
    .v3 = 0x7465646279746573ULL ,}

export struct_System_Type  Crypto_SipHash48Type;

export void  Crypto_SipHash48_update(Crypto_SipHash48 that, System_var input, System_size length);
export System_uint64  Crypto_SipHash48_final(Crypto_SipHash48 that);

/* final class Crypto.SipHash48 */

typedef Crypto_SipHash48 delegate(Crypto_SipHash48_init)(Crypto_SipHash48 that);
typedef void delegate(Crypto_SipHash48_free)(Crypto_SipHash48 that);

export Crypto_SipHash48  base_Crypto_SipHash48_init(Crypto_SipHash48 that);
export void  base_Crypto_SipHash48_free(Crypto_SipHash48 that);

#define Crypto_SipHash48_init  base_Crypto_SipHash48_init
#define Crypto_SipHash48_free  base_Crypto_SipHash48_free

#define new_Crypto_SipHash48()  (base_Crypto_SipHash48_init((Crypto_SipHash48)System_Memory_allocClass(typeof(Crypto_SipHash48))))

#if defined(using_Crypto)
#define struct_SipHash48  struct_Crypto_SipHash48
#define stack_SipHash48  stack_Crypto_SipHash48
#define SipHash48  Crypto_SipHash48
#define SipHash48Type  Crypto_SipHash48Type
#define function_SipHash48_init  function_Crypto_SipHash48_init
#define function_SipHash48_free  function_Crypto_SipHash48_free
#define base_SipHash48_init  base_Crypto_SipHash48_init
#define base_SipHash48_free  base_Crypto_SipHash48_free
#define SipHash48_update  Crypto_SipHash48_update
#define SipHash48_final  Crypto_SipHash48_final
#define SipHash48_new  Crypto_SipHash48_new
#define SipHash48_init  Crypto_SipHash48_init
#define SipHash48_free  Crypto_SipHash48_free
#endif

#endif
