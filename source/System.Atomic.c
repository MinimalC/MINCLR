/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif

/** struct System_Atomic  **/

struct System_Type System_AtomicType = { .base = { .type = typeof(System_Type) }, .name = "Atomic", .size = sizeof(struct System_Atomic) };

System_Bool System_Atomic_readLock(System_Atomic that) {
    return System_Atomic_readLock__dontwait(that, false);
}

System_Bool System_Atomic_readLock__dontwait(System_Atomic that, System_Bool dontwait) {
    System_Atomic_fence();
    if (that->writers != -1)
    while (!System_Int32_atomic_expect(&that->writers, 0, -1)) {
        if (dontwait) return false;
        System_Atomic_pause();
        System_Atomic_fence();
    }
    System_Int32_atomic_increment(&that->readers);
    System_Atomic_fence();
    return true;
}

void System_Atomic_readUnlock(System_Atomic that) {
    System_Atomic_fence();
    System_Int32 reader = System_Int32_atomic_decrement(&that->readers);
    System_Atomic_fence();
    if (!reader)
    while (!System_Int32_atomic_expect(&that->writers, -1, 0)) {
        System_Atomic_pause();
        System_Atomic_fence();
    }
}

System_Bool System_Atomic_writeLock(System_Atomic that) {
    return System_Atomic_writeLock__dontwait(that, false);
}

System_Bool System_Atomic_writeLock__dontwait(System_Atomic that, System_Bool dontwait) {
    System_Atomic_fence();
    while (!System_Int32_atomic_expect(&that->writers, 0, 1)) {
        if (dontwait) return false;
        System_Atomic_pause();
        System_Atomic_fence();
    }
    return true;
}

void System_Atomic_writeUnlock(System_Atomic that) {
    System_Atomic_fence();
    System_Int32_atomic_decrement(&that->writers);
    System_Atomic_fence();
}


#if defined(have_AMD64)

void System_Atomic_fence() {
    __asm__("mfence");
}

void System_Atomic_pause() {
    __asm__("pause");
}

System_Bool System_Size_atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock cmpxchgq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Size System_Size_atomic_exchange(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock xchgq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_exchange_add(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock xaddq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_add(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock addq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_subtract(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock subq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_increment(atomic System_Size * that) {
    __asm__ ("lock incq %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Size System_Size_atomic_decrement(atomic System_Size * that) {
    __asm__ ("lock decq %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Size System_Size_atomic_negation(atomic System_Size * that) {
    __asm__ ("lock negq %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Size System_Size_atomic_and(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock andq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_or(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock orq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Size_atomic_xor(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock xorq %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Bool System_Size_atomic_bit_test_complement(atomic System_Size * that, System_Size value) {
    register System_Bool reture = 0;
    __asm__ ("lock btcq %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}

System_Bool System_Size_atomic_bit_test_unset(atomic System_Size * that, System_Size value) {
    register System_Bool reture = 0;
    __asm__ ("lock btrq %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}

System_Bool System_Size_atomic_bit_test_set(atomic System_Size * that, System_Size value) {
    register System_Bool reture = 0;
    __asm__ ("lock btsq %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}


System_Bool System_Int32_atomic_expect(atomic System_Int32 * that, System_Int32 comparison, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock cmpxchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Int32 System_Int32_atomic_exchange(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock xchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_exchange_add(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock xaddl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_add(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock addl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_subtract(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock subl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_increment(atomic System_Int32 * that) {
    __asm__ ("lock incl %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Int32 System_Int32_atomic_decrement(atomic System_Int32 * that) {
    __asm__ ("lock decl %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Int32 System_Int32_atomic_negation(atomic System_Int32 * that) {
    __asm__ ("lock negl %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Int32 System_Int32_atomic_and(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock andl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_or(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock orl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Int32_atomic_xor(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock xorl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Bool System_Int32_atomic_bit_test_complement(atomic System_Int32 * that, System_Int32 value) {
    register System_Bool reture = 0;
    __asm__ ("lock btcl %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}

System_Bool System_Int32_atomic_bit_test_unset(atomic System_Int32 * that, System_Int32 value) {
    register System_Bool reture = 0;
    __asm__ ("lock btrl %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}

System_Bool System_Int32_atomic_bit_test_set(atomic System_Int32 * that, System_Int32 value) {
    register System_Bool reture = 0;
    __asm__ ("lock btsl %1, %2" : "+m" (*that) : "r" (value));
    __asm__ ("setc %0" : "=r"(reture));
    return reture;
}

#endif