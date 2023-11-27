/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Atomic)
#define have_System_Atomic

export struct System_Type  System_AtomicType;

export void System_Atomic_fence();
export void System_Atomic_delay();

export System_Bool System_Atomic_expect(atomic System_Size * that, System_Size comparison, System_Size value);
export System_Bool System_Atomic_expectDefault(atomic System_Size * that);
export System_Size System_Atomic_exchange(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_exchangeDefault(atomic System_Size * that);
export System_Size System_Atomic_add(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_subtract(atomic System_Size * that, System_Size value);
export System_Size System_Atomic_increment(atomic System_Size * that);
export System_Size System_Atomic_decrement(atomic System_Size * that);

export System_Bool System_Atomic_expect__int32(atomic System_Int32 * that, System_Int32 comparison, System_Int32 value);
export System_Bool System_Atomic_expectDefault__int32(atomic System_Int32 * that);
export System_Int32 System_Atomic_exchange__int32(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Atomic_exchangeDefault__int32(atomic System_Int32 * that);
export System_Int32 System_Atomic_add__int32(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Atomic_subtract__int32(atomic System_Int32 * that, System_Int32 value);
export System_Int32 System_Atomic_increment__int32(atomic System_Int32 * that);
export System_Int32 System_Atomic_decrement__int32(atomic System_Int32 * that);

#if defined(using_System)
#define Atomic  System_Atomic
#define AtomicType  System_AtomicType
#endif
#endif
