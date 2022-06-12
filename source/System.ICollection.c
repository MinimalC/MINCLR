#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_ICollection)
#define code_System_ICollection

/*# System_ICollection #*/

struct_System_String  STRING_System_ICollection = const_System_String("System.ICollection");

struct_System_Type  System_ICollectionType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_ICollection,
};

/* TODO: throw NotImplementedException, this is interface */

System_var  base_System_ICollection_get_index(System_ICollection that) { return __null; }
System_void  base_System_ICollection_set_index(System_ICollection that, System_var value) { }
System_size  base_System_ICollection_get_Length(System_ICollection that) { return 0; }
System_void  base_System_ICollection_copyTo(System_ICollection that, System_ICollection other, System_size offset) { }

#endif
