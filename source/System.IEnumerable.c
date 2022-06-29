/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_IEnumerable)
#include <min/System.IEnumerable.h>
#endif
#if !defined(code_System_IEnumerable)
#define code_System_IEnumerable


/*# System_IEnumerator #*/

struct_System_String  STRING_System_IEnumerator = const_System_String("System.IEnumerator");

struct_System_Type  System_IEnumeratorType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_IEnumerator,
};

/* TODO: throw NotImplementedException, this is interface */

System_var  base_System_IEnumerator_get_current(System_IEnumerator that) { return null; }
System_boolean  base_System_IEnumerator_moveNext(System_IEnumerator that) { return false; }


/*# System_IEnumerable #*/

struct_System_String  STRING_System_IEnumerable = const_System_String("System.IEnumerable");

struct_System_Type  System_IEnumerableType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_IEnumerable,
};

/* TODO: throw NotImplementedException, this is interface */

System_IEnumerator  base_System_IEnumerable_getEnumerator(System_IEnumerable that) { return null; }

#endif
