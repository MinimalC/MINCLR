/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_IEnumerable)
#include <min/System.IEnumerable.h>
#endif
#if !defined(code_System_IEnumerable)
#define code_System_IEnumerable

/*# System_IEnumerator #*/

struct System_Type  System_IEnumeratorType = { .base = stack_System_Object(System_Type),
	.name = "IEnumerator",
};

System_Var  base_System_IEnumerator_get_current(System_IEnumerator that) { return null; }
System_Bool  base_System_IEnumerator_moveNext(System_IEnumerator that) { return false; }


/*# System_IEnumerable #*/

struct System_Type  System_IEnumerableType = { .base = stack_System_Object(System_Type),
	.name = "IEnumerable",
};

System_IEnumerator  base_System_IEnumerable_getEnumerator(System_IEnumerable that) { return null; }

#endif
