/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif

/*# System_Atomic #*/

struct System_Type System_AtomicType = { .base = { .type = typeof(System_Type) }, .name = "Atomic" };

void System_Atomic_fence() {
    __asm__("mfence");
}

System_Bool System_Atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock cmpxchgq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Size System_Atomic_exchange(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock xchgq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Atomic_add(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock addq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Atomic_subtract(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock subq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Atomic_increment(atomic System_Size * that) {
    __asm__ ("lock incq %q0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Size System_Atomic_decrement(atomic System_Size * that) {
    __asm__ ("lock decq %q0" : "=m" (*that) : "m" (*that));
    return *that;
}

void System_Atomic_delay() {
    __asm__ __volatile__ ("nop\n""nop\n""nop\n""nop\n""nop\n""nop\n""nop\n""nop\n" "nop\n""nop\n""nop\n""nop\n""nop\n""nop\n""nop\n""nop\n");
}