/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif

/*# System_Atomic #*/

struct System_Type System_AtomicType = { .base = { .type = typeof(System_Type) }, .name = "Atomic" };

void System_Atomic_fence() {
    __asm__("mfence");
}

void System_Atomic_delay() {
    __asm__ __volatile__ (
        "nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;  nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;"
        "nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;  nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;"
        "nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;  nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;"
        "nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;  nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;"
    );
}

System_Bool System_Atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock cmpxchgq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Bool System_Atomic_expectDefault(atomic System_Size * that) {
    return System_Atomic_expect(that, 0, 0);
}

System_Size System_Atomic_exchange(atomic System_Size * that, System_Size value) {
    System_Size reture = 0;
    __asm__ ("lock xchgq %q2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Size System_Atomic_exchangeDefault(atomic System_Size * that) {
    return System_Atomic_exchange(that, 0);
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


System_Bool System_Atomic_expect__int32(atomic System_Int32 * that, System_Int32 comparison, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock cmpxchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Bool System_Atomic_expectDefault__int32(atomic System_Int32 * that) {
    return System_Atomic_expect__int32(that, 0, 0);
}

System_Int32 System_Atomic_exchange__int32(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock xchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Atomic_exchangeDefault__int32(atomic System_Int32 * that) {
    return System_Atomic_exchange__int32(that, 0);
}

System_Int32 System_Atomic_add__int32(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock addl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Atomic_subtract__int32(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock subl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
}

System_Int32 System_Atomic_increment__int32(atomic System_Int32 * that) {
    __asm__ ("lock incl %0" : "=m" (*that) : "m" (*that));
    return *that;
}

System_Int32 System_Atomic_decrement__int32(atomic System_Int32 * that) {
    __asm__ ("lock decl %0" : "=m" (*that) : "m" (*that));
    return *that;
}
