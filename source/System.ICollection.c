/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_ICollection)
#include <min/System.ICollection.h>
#endif
#if !defined(code_System_ICollection)
#define code_System_ICollection

/*# System_ICollection #*/

struct System_Type System_ICollectionType = { .base = stack_System_Object(System_Type),
	.name = "ICollection",
};

System_Var  base_System_ICollection_get_index(System_ICollection that) { return null; }
void  base_System_ICollection_set_index(System_ICollection that, System_Var value) { }
System_Size  base_System_ICollection_get_Length(System_ICollection that) { return 0; }
void  base_System_ICollection_copyTo(System_ICollection that, System_ICollection other, System_Size offset) { }

#endif
