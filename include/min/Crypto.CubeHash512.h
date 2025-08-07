/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Crypto_CubeHash512)
#define have_Crypto_CubeHash512

typedef System_fixed struct Crypto_CubeHash512 {

    System_UInt32  x[32];

    System_Size  position;

    System_Size  hashsize;

} * Crypto_CubeHash512;

export struct System_Type  Crypto_CubeHash512Type;

export Crypto_CubeHash512  new_Crypto_CubeHash512();
export void  Crypto_CubeHash512_init(Crypto_CubeHash512 that);
export void  Crypto_CubeHash512_init__size(Crypto_CubeHash512 that, System_Size hashsize);
export void  Crypto_CubeHash512_updateBits(Crypto_CubeHash512 that, System_String8 input, Size length);
export void  Crypto_CubeHash512_update(Crypto_CubeHash512 that, System_String8 input, System_Size length);
export void  Crypto_CubeHash512_final(Crypto_CubeHash512 that);
export System_String8  Crypto_CubeHash512_toString(Crypto_CubeHash512 that);
export System_Size  stack_Crypto_CubeHash512_toString(Crypto_CubeHash512 that, System_String8 string);

#if defined(using_Crypto)
#define CubeHash512  Crypto_CubeHash512
#define CubeHash512Type  Crypto_CubeHash512Type
#define new_CubeHash512  new_Crypto_CubeHash512
#define CubeHash512_init  Crypto_CubeHash512_init
#define CubeHash512_init__size  Crypto_CubeHash512_init__size
#define CubeHash512_updateBits  Crypto_CubeHash512_updateBits
#define CubeHash512_update  Crypto_CubeHash512_update
#define CubeHash512_final  Crypto_CubeHash512_final
#define CubeHash512_toString  Crypto_CubeHash512_toString
#define stack_CubeHash512_toString  Crypto_CubeHash512_toString
#endif
#endif
