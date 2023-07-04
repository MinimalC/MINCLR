/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_Crypto_SipHash48)
#include <min/Crypto.SipHash48.h>
#endif
#if !defined(code_Crypto_SipHash48)
#define code_Crypto_SipHash48

/*# Crypto_SipHash48 #*/

Crypto_SipHash48  base_Crypto_SipHash48_init(Crypto_SipHash48 that) {

    that->v0 = 0x736f6d6570736575ULL;
    that->v1 = 0x646f72616e646f6dULL;
    that->v2 = 0x6c7967656e657261ULL;
    that->v3 = 0x7465646279746573ULL;
}

Crypto_SipHash48  base_Crypto_SipHash48_init__key(Crypto_SipHash48 that, System_String8 key) {

	UInt64 k0 = *((UInt64 *)(key + 0));
	UInt64 k1 = *((UInt64 *)(key + 8));

    that->v0 = k0 ^ 0x736f6d6570736575ULL;
    that->v1 = k1 ^ 0x646f72616e646f6dULL;
    that->v2 = k0 ^ 0x6c7967656e657261ULL;
    that->v3 = k1 ^ 0x7465646279746573ULL;

    return that;
}

#define SIPHASH_ROUNDS  4
#define SIPHASH_FINALROUNDS  8

#define rotl64(x, c)  ( ((x) << (c)) ^ ((x) >> (64-(c))) )

#define HALF_ROUND(a,b,c,d,s,t) \
	do { \
		a += b;  c += d; \
		b = rotl64(b, s); d = rotl64(d, t); \
		b ^= a;  d ^= c; \
	} while(0)

#define COMPRESS(v0,v1,v2,v3) \
	do { \
		HALF_ROUND(v0,v1,v2,v3,13,16); \
		v0 = rotl64(v0,32); \
		HALF_ROUND(v2,v1,v0,v3,17,21); \
		v2 = rotl64(v2, 32); \
	} while(0)

void  Crypto_SipHash48_update(Crypto_SipHash48 that, System_Var input, System_Size length) {

    UInt64 v0 = that->v0, v1 = that->v1;
    UInt64 v2 = that->v2, v3 = that->v3;

    Size i, k, len;
    UInt64 mi, mask;
	for (i = 0; i * 8 < length - (length % 8); ++i)
	{
		mi = *((UInt64*)(input + i));
		v3 ^= mi;
		for (k = 0; k < SIPHASH_ROUNDS; ++k) COMPRESS(v0,v1,v2,v3);
		v0 ^= mi;
	}

	mi = *((UInt64 *)(input + i));
	len = (length & 0xff) << 56;
	mask = length % 8 == 0 ? 0 : 0xffffffffffffffffULL >> (8 * (8 - (length % 8)));
	mi = (mi & mask) ^ len;

	v3 ^= mi;
	for (k = 0; k < SIPHASH_ROUNDS; ++k) COMPRESS(v0,v1,v2,v3);
	v0 ^= mi;

    that->v0 = v0; that->v1 = v1;
    that->v2 = v2; that->v3 = v3;
}

System_UInt64  Crypto_SipHash48_final(Crypto_SipHash48 that) {

    UInt64 v0 = that->v0, v1 = that->v1;
    UInt64 v2 = that->v2, v3 = that->v3;

	v2 ^= 0xff;
	for(Size k = 0; k < SIPHASH_FINALROUNDS; ++k) COMPRESS(v0,v1,v2,v3);

	return (v0 ^ v1) ^ (v2 ^ v3);
}

#undef COMPRESS
#undef HALF_ROUND
#undef rotl64

void  base_Crypto_SipHash48_free(Crypto_SipHash48 that) {
    unused(that)
}

struct System_Type_FunctionInfo  Crypto_SipHash48TypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_Crypto_SipHash48_init },
};

struct System_Type Crypto_SipHash48Type = {
	.base = { .type = typeof(System_Type) },
	.name = "Crypto.SipHash48",
	.size = sizeof(struct Crypto_SipHash48),
	.baseType = &System_ObjectType,
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(Crypto_SipHash48TypeFunctions), .value = &Crypto_SipHash48TypeFunctions
    },
};

#endif
