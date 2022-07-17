#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Assembly)
#include <min/System.Assembly.h>
#endif
#if !defined(code_System_Assembly)
#define code_System_Assembly

/*# System_Assembly #*/

Assembly  System_Assembly_open(const string8  fileName, System_AssemblyBinding  flags)
{
    ISO_Library assemblyPtr = ISO_dlopen(fileName, (int32)flags);
    if (!assemblyPtr) return null; /* TODO: throw FileNotFound */

    Assembly that = inline_Object_allocClass(Assembly);
    base_System_Assembly_init(that);

    that->fileName = fileName;
    that->assemblyPtr = assemblyPtr;

    return that;
}

void * System_Assembly_findGlobal(const System_string8 name) {
    return ISO_dlsym(null, name);
}

void  * System_Assembly_find(Assembly that, const System_string8  name)
{
    return ISO_dlsym((ISO_Library)that->assemblyPtr, name);
}


Assembly  base_System_Assembly_init(Assembly that) {
	base_System_Object_init((Object)that);

    return that;
}
void  base_System_Assembly_free(Assembly that) {

    if (that->assemblyPtr) {
        ISO_dlclose((ISO_Library)that->assemblyPtr);
        that->assemblyPtr = null;
    }

	base_System_Object_free((Object)that);
}

struct_System_String  STRING_System_Assembly = const_System_String("System.Assembly");

struct_System_Type_FunctionInfo  System_AssemblyTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Assembly_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Assembly_free },
};

struct_System_Type  System_AssemblyType = {
	.base = { .type = typeof(System_Type) },
	.name = &STRING_System_Assembly,
	.size = sizeof(struct_System_Assembly),
	.baseType = &System_ObjectType,
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_AssemblyTypeFunctions), .value = &System_AssemblyTypeFunctions
    },
};

#endif
