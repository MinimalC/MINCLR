/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_Crypto_CubeHash512)
#include <min/Crypto.CubeHash512.h>
#endif
#if !defined(code_Crypto_CubeHash512)
#define code_Crypto_CubeHash512

/*# Crypto_CubeHash512 #*/

Crypto_CubeHash512  new_Crypto_CubeHash512() {
    Crypto_CubeHash512 that = (Crypto_CubeHash512)System_Memory_allocClass(typeof(Crypto_CubeHash512));
    Crypto_CubeHash512_init(that);
    return that;
}

#define CUBEHASH_ROUNDS 16
#define CUBEHASH_BLOCKBYTES 32

static void Crypto_CubeHash512_transform(Crypto_CubeHash512 that)
{
  System_Size i;
  System_Size r;
  System_UInt32 y[16]; Stack_clear(y);

#define ROTATE(a,b) (((a) << (b)) | ((a) >> (32 - b)))

  for (r = 0;r < CUBEHASH_ROUNDS;++r) {
    for (i = 0;i < 16;++i) that->x[i + 16] += that->x[i];
    for (i = 0;i < 16;++i) y[i ^ 8] = that->x[i];
    for (i = 0;i < 16;++i) that->x[i] = ROTATE(y[i],7);
    for (i = 0;i < 16;++i) that->x[i] ^= that->x[i + 16];
    for (i = 0;i < 16;++i) y[i ^ 2] = that->x[i + 16];
    for (i = 0;i < 16;++i) that->x[i + 16] = y[i];
    for (i = 0;i < 16;++i) that->x[i + 16] += that->x[i];
    for (i = 0;i < 16;++i) y[i ^ 4] = that->x[i];
    for (i = 0;i < 16;++i) that->x[i] = ROTATE(y[i],11);
    for (i = 0;i < 16;++i) that->x[i] ^= that->x[i + 16];
    for (i = 0;i < 16;++i) y[i ^ 1] = that->x[i + 16];
    for (i = 0;i < 16;++i) that->x[i + 16] = y[i];
  }

#undef ROTATE

}

void  Crypto_CubeHash512_init__size(Crypto_CubeHash512 that, System_Size hashsize) {

  if (hashsize < 8) return; // throw
  if (hashsize > 512) return; // throw
  if (hashsize != 8 * (hashsize / 8)) return; // throw

  that->hashsize = hashsize;
  for (Size i = 0; i < 32; ++i) that->x[i] = 0;
  that->x[0] = hashsize / 8;
  that->x[1] = CUBEHASH_BLOCKBYTES;
  that->x[2] = CUBEHASH_ROUNDS;
  Crypto_CubeHash512_transform(that);
  that->position = 0;
}

void  Crypto_CubeHash512_init(Crypto_CubeHash512 that) {

  Crypto_CubeHash512_init__size(that, 512);
}

void Crypto_CubeHash512_updateBits(Crypto_CubeHash512 that, System_String8 input, Size length) {

  /* caller promises us that previous data had integral number of bytes */
  /* so that->pos is a multiple of 8 */

  while (length >= 8) {
    System_UInt32 u = *input;
    u <<= 8 * ((that->position / 8) % 4);
    that->x[that->position / 32] ^= u;
    input += 1;
    length -= 8;
    that->position += 8;
    if (that->position == 8 * CUBEHASH_BLOCKBYTES) {
      Crypto_CubeHash512_transform(that);
      that->position = 0;
    }
  }
  if (length > 0) {
    System_UInt32 u = *input;
    u <<= 8 * ((that->position / 8) % 4);
    that->x[that->position / 32] ^= u;
    that->position += length;
  }
}

void Crypto_CubeHash512_update(Crypto_CubeHash512 that, System_String8 input, Size length) {

  Crypto_CubeHash512_updateBits(that, input, length * 8);
}

void Crypto_CubeHash512_final(Crypto_CubeHash512 that) {
   
  System_UInt32 u = (128 >> (that->position % 8));
  u <<= 8 * ((that->position / 8) % 4);
  that->x[that->position / 32] ^= u;
  Crypto_CubeHash512_transform(that);
  that->x[31] ^= 1;
  Crypto_CubeHash512_transform(that);
  Crypto_CubeHash512_transform(that);
}

System_String8 Crypto_CubeHash512_toString(Crypto_CubeHash512 that) {
  System_String8 string = System_Memory_allocArray(typeof(System_Char8), 257);
  stack_Crypto_CubeHash512_toString(that, string);
  return string;
}

void stack_Crypto_CubeHash512_toString(Crypto_CubeHash512 that, System_String8 string) {
  for (Size i = 0, position = 0; i == 0 || i < that->hashsize / 16; ++i) 
    position += stack_System_String8_format("{0:uint32:hex}", string + position, 1, that->x[i]);
}

struct System_Type_FunctionInfo  Crypto_CubeHash512TypeFunctions[] = {
    { .function = base_System_Object_init, .value = Crypto_CubeHash512_init },
};

struct System_Type Crypto_CubeHash512Type = {
	.base = { .type = typeof(System_Type) },
	.name = "Crypto.CubeHash512",
	.size = sizeof(struct Crypto_CubeHash512),
	.baseType = &System_ObjectType,
	.functions  = { 
        .length = sizeof_array(Crypto_CubeHash512TypeFunctions), .value = &Crypto_CubeHash512TypeFunctions
    },
};

#endif
