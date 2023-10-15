/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Crypto_SipHash48)
#define have_Crypto_SipHash48

typedef System_fixed struct Crypto_SipHash48 {

    System_UInt64  v0;
    System_UInt64  v1;
    System_UInt64  v2;
    System_UInt64  v3;

} * Crypto_SipHash48;

export struct System_Type  Crypto_SipHash48Type;

export Crypto_SipHash48  new_Crypto_SipHash48();
export void  base_Crypto_SipHash48_init(Crypto_SipHash48 that);
export void  Crypto_SipHash48_update(Crypto_SipHash48 that, System_Var input, System_Size length);
export System_UInt64  Crypto_SipHash48_final(Crypto_SipHash48 that);

#define Crypto_SipHash48_init  base_Crypto_SipHash48_init

#if defined(using_Crypto)
#define SipHash48  Crypto_SipHash48
#define SipHash48Type  Crypto_SipHash48Type

#define new_SipHash48  new_Crypto_SipHash48
#define function_SipHash48_init  function_Crypto_SipHash48_init
#define base_SipHash48_init  base_Crypto_SipHash48_init
#define SipHash48_update  Crypto_SipHash48_update
#define SipHash48_final  Crypto_SipHash48_final
#define SipHash48_init  Crypto_SipHash48_init
#endif

#endif
