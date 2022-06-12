#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_Assembly)
#define code_System_Assembly

/*# System_Assembly #*/

System_Assembly  System_Assembly_new() {
    return inline_System_Assembly_new();
}

__Assembly  System_Assembly_open(const __string8  fileName, enum_System_AssemblyBinding  flags)
{
    ISO_Library assemblyPtr = ISO_dlopen(fileName, (__int32)flags);
    if (!assemblyPtr) return __null; /* TODO: throw FileNotFound */

    __Assembly that = inline_Object_allocClass(__Assembly);
    base_System_Assembly_init(that);

    that->fileName = fileName;
    that->assemblyPtr = assemblyPtr;

    return that;
}

void * System_Assembly_findGlobal(const System_string8 name) {
    return ISO_dlsym(__null, name);
}

void  * System_Assembly_find(__Assembly that, const System_string8  name)
{
    return ISO_dlsym((ISO_Library)that->assemblyPtr, name);
}


__Assembly  base_System_Assembly_init(__Assembly that) {
    if (!that) that = inline_Object_allocClass(__Assembly);
	base_System_Object_init((__Object)that);

    return that;
}
void  base_System_Assembly_free(__Assembly that) {

    if (that->assemblyPtr) {
        ISO_dlclose((ISO_Library)that->assemblyPtr);
        that->assemblyPtr = __null;
    }

	base_System_Object_free((__Object)that);
}

struct_System_String  STRING_System_Assembly = const_System_String("System.Assembly");

struct_System_Type_FunctionInfo  System_AssemblyTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Assembly_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Assembly_free },
};

struct_System_Type  System_AssemblyType = {
	.base = { .Type = __typeof(System_Type) },
	.name = &STRING_System_Assembly,
	.size = sizeof(struct_System_Assembly),
	.baseType = &System_ObjectType,
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_AssemblyTypeFunctions), .value = &System_AssemblyTypeFunctions
    },
};

#endif
