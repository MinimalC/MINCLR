/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Atomic)
#define have_System_Atomic

typedef System_fixed struct System_Atomic {

    atomic System_Int32 readers;

    atomic System_Int32 writers;

}  * System_Atomic;

export struct System_Type  System_AtomicType;

export void System_Atomic_fence();
export void System_Atomic_pause();

export System_Bool System_Size_atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value);
export System_Size System_Size_atomic_exchange(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_exchange_add(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_add(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_subtract(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_increment(atomic System_Size * that);
export System_Size System_Size_atomic_decrement(atomic System_Size * that);
export System_Size System_Size_atomic_negation(atomic System_Size * that);
export System_Size System_Size_atomic_and(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_or(atomic System_Size * that, System_Size value);
export System_Size System_Size_atomic_xor(atomic System_Size * that, System_Size value);
export System_Bool System_Size_atomic_bit_test_complement(atomic System_Size * that, System_Size value);
export System_Bool System_Size_atomic_bit_test_unset(atomic System_Size * that, System_Size value);
export System_Bool System_Size_atomic_bit_test_set(atomic System_Size * that, System_Size value);

export System_Bool System_Int32_atomic_expect(atomic System_Int32 * that, System_Int32 comparison, System_Int32 value);
export System_Int32 System_Int32_atomic_exchange(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_exchange_add(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_add(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_subtract(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_increment(atomic System_Int32 * that);
export System_Int32 System_Int32_atomic_decrement(atomic System_Int32 * that);
export System_Int32 System_Int32_atomic_negation(atomic System_Int32 * that);
export System_Int32 System_Int32_atomic_and(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_or(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Int32_atomic_xor(atomic System_Int32 * that, System_Int32 value);
export System_Bool System_Int32_atomic_bit_test_complement(atomic System_Int32 * that, System_Int32 value);
export System_Bool System_Int32_atomic_bit_test_unset(atomic System_Int32 * that, System_Int32 value);
export System_Bool System_Int32_atomic_bit_test_set(atomic System_Int32 * that, System_Int32 value);

export System_Bool System_Atomic_readLock(System_Atomic that);
export System_Bool System_Atomic_readLock__dontwait(System_Atomic that, System_Bool dontwait);
export void System_Atomic_readUnlock(System_Atomic that);
export System_Bool System_Atomic_writeLock(System_Atomic that);
export System_Bool System_Atomic_writeLock__dontwait(System_Atomic that, System_Bool dontwait);
export void System_Atomic_writeUnlock(System_Atomic that);

#if defined(using_System)
#define Atomic  System_Atomic
#define AtomicType  System_AtomicType
#endif
#endif
