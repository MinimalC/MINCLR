/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Atomic)
#define have_System_Atomic

export struct System_Type  System_AtomicType;

export void System_Atomic_fence();
export System_Bool System_Atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value);
export System_Size System_Atomic_exchange(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_add(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_subtract(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_increment(atomic System_Size * that);
export System_Size System_Atomic_decrement(atomic System_Size * that);
export void System_Atomic_delay();

#if defined(using_System)
#define Atomic  System_Atomic
#define AtomicType  System_AtomicType
#endif
#endif
