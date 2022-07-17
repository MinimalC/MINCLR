/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_enum)
#define code_System_enum

/*# System_enum #*/

string8 System_enum_getName(Type type, intptr value) {
    assert(type)

    for (size i = 0; i < type->fields.length; ++i) {

        struct_System_Type_FieldInfo info = array(type->fields.value)[i];

        if (info.value == value) {
            return info.name;
        }
    }

    return string8_Empty;
}

#endif
#if !defined(code_System_Type)
#define code_System_Type

/*# System_Type #*/

struct_System_Type  System_TypeType = { .base = { .type = typeof(System_Type) },
    .name = "System.Type",
	.size = sizeof(struct_System_Type),
	.baseType = &System_ObjectType
};

/* Literal Types */

/* sizeof(void) is 1 */
/* sizeof(void *) is sizeof(size), sizeof(intptr) */

struct_System_Type  System_voidType     = { .base = stack_System_Object(System_Type), .name = "System.void",    .size = sizeof(void) };
struct_System_Type  System_varType      = { .base = stack_System_Object(System_Type), .name = "System.var",     .size = sizeof(void *) };
struct_System_Type  System_sizeType     = { .base = stack_System_Object(System_Type), .name = "System.size",    .size = sizeof(System_size) };
struct_System_Type  System_ssizeType    = { .base = stack_System_Object(System_Type), .name = "System.ssize",   .size = sizeof(System_ssize) };
struct_System_Type  System_intptrType   = { .base = stack_System_Object(System_Type), .name = "System.intptr",  .size = sizeof(System_intptr) };
struct_System_Type  System_sintptrType  = { .base = stack_System_Object(System_Type), .name = "System.sintptr", .size = sizeof(System_sintptr) };
struct_System_Type  System_booleanType  = { .base = stack_System_Object(System_Type), .name = "System.boolean", .size = sizeof(System_boolean) };

struct_System_Type  System_Type_FunctionInfoType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.FunctionInfo",
	.size = sizeof(struct_System_Type_FunctionInfo),
	.baseType = &System_ObjectType
};

struct_System_Type  System_Type_FunctionInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.FunctionInfoArray",
	.size = sizeof(struct_System_Type_FunctionInfoArray),
	.baseType = &System_ObjectType
};

struct_System_Type  System_Type_InterfaceInfoType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.InterfaceInfo",
	.size = sizeof(struct_System_Type_InterfaceInfo),
	.baseType = &System_ObjectType
};

struct_System_Type  System_Type_InterfaceInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.InterfaceInfoArray",
	.size = sizeof(struct_System_Type_InterfaceInfoArray),
	.baseType = &System_ObjectType
};

struct_System_Type  System_Type_FieldInfoType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.FieldInfo",
	.size = sizeof(struct_System_Type_FieldInfo),
	.baseType = &System_ObjectType
};

struct_System_Type  System_Type_FieldInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = "System.Type.FieldInfoArray",
	.size = sizeof(struct_System_Type_FieldInfoArray),
	.baseType = &System_ObjectType
};

System_var System_Type_getMethod(System_Type  that, System_var fun) {
    System_var reture = System_Type_trygetMethod(that, fun);
    if (!reture) throw_terminate(new_System_Exception("NotImplementedException_new: Method not found"));
    return reture;
}

System_var System_Type_trygetMethod(System_Type  that, System_var fun) {
    System_assert(that)
    System_assert(fun)

    System_Type_FunctionInfo info;
    for (System_size f = 0; f < that->functions.length; ++f) {
        info = &array(that->functions.value)[f];
        if (fun == info->function) return info->value;
    }

    if (that->baseType) return System_Type_trygetMethod(that->baseType, fun);

    return null;
}

System_boolean  System_Type_isAssignableFrom(System_Type  that, System_Type  other) {
    assert(that)
    assert(other)

    System_Type they = that;
    System_Type_InterfaceInfo info;
    while (they) {
        if (other == they) return true;
        for (System_size f = 0; f < they->interfaces.length; ++f) {
            info = &array(they->interfaces.value)[f];
            if (other == info->interfaceType) return true;
        }
        they = they->baseType;
    }
    return false;
}

#endif
