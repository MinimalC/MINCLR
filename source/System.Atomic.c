/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif

/*# System_Atomic #*/

struct System_Type System_AtomicType = { .base = { .type = typeof(System_Type) }, .name = "Atomic", .size = sizeof(struct System_Atomic) };

void System_Atomic_fence() {
    __asm__("mfence");
}

void System_Atomic_delay() {
    __asm__ __volatile__ (
        "nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;" /*"nop;nop;nop;nop;nop;nop;nop;nop; nop;nop;nop;nop;nop;nop;nop;nop;"*/
    );
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


System_Bool System_Atomic_expect__int32(atomic System_Int32 * that, System_Int32 comparison, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock cmpxchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that), "0" (comparison));
    return reture == comparison;
}

System_Int32 System_Atomic_exchange__int32(atomic System_Int32 * that, System_Int32 value) {
    System_Int32 reture = 0;
    __asm__ ("lock xchgl %2, %1" : "=a" (reture), "=m" (*that) : "r" (value), "m" (*that));
    return reture;
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


System_Bool System_Atomic_readLock(System_Atomic that) {
    return System_Atomic_readLock__dontwait(that, false);
}

System_Bool System_Atomic_readLock__dontwait(System_Atomic that, System_Bool dontwait) {

    while (!System_Atomic_expect(&that->writers, 0, 0)) {
        if (dontwait) return false;
        System_Atomic_delay();
        System_Atomic_fence();
    }
    System_Atomic_increment(&that->readers);
    System_Atomic_fence();
    return true;
}

void System_Atomic_readUnlock(System_Atomic that) {
    System_Atomic_decrement(&that->readers);
    System_Atomic_fence();
}

System_Bool System_Atomic_writeLock(System_Atomic that) {
    return System_Atomic_writeLock__dontwait(that, false);
}

System_Bool System_Atomic_writeLock__dontwait(System_Atomic that, System_Bool dontwait) {
    System_Size writer;
    if (!dontwait) writer = System_Atomic_increment(&that->writers);
    System_Atomic_fence();
    while (!System_Atomic_expect(&that->readers, 0, 0)) {
        if (dontwait) return false;
        System_Atomic_delay();
        System_Atomic_fence();
    }
    if (dontwait) writer = System_Atomic_increment(&that->writers);
    System_Atomic_fence();
    while (!System_Atomic_expect(&that->writers, writer, writer)) {
        System_Atomic_delay();
        System_Atomic_fence();
    }
    return true;    
}

void System_Atomic_writeUnlock(System_Atomic that) {
    System_Atomic_decrement(&that->writers);
    System_Atomic_fence();
}