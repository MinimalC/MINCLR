#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_enum)
#define code_System_enum

/*# System_enum #*/

__string8 System_enum_getName(__Type type, __intptr value) {
    __assert(type)

    for (__size i = 0; i < type->fields.length; ++i) {

        struct_System_Type_FieldInfo info = __array(type->fields.value)[i];

        if (info.value == value) {
            return info.name;
        }
    }

    return __string8_Empty;
}

#endif
#if !defined(code_System_Type)
#define code_System_Type

/*# System_Type #*/

struct_System_Type  System_TypeType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.Type",
	.size = sizeof(struct_System_Type),
	.baseType = &System_ObjectType
};

/* Literal Types */

/* sizeof(void) is 1 */
/* sizeof(void *) is sizeof(__size), sizeof(__intptr) */

struct_System_Type  System_voidType     = { .base = stack_System_Object(System_Type), .name = "System.void",    .size = sizeof(void) };
struct_System_Type  System_varType      = { .base = stack_System_Object(System_Type), .name = "System.var",     .size = sizeof(void *) };
struct_System_Type  System_sizeType     = { .base = stack_System_Object(System_Type), .name = "System.size",    .size = sizeof(System_size) };
struct_System_Type  System_ssizeType    = { .base = stack_System_Object(System_Type), .name = "System.ssize",   .size = sizeof(System_ssize) };
struct_System_Type  System_intptrType   = { .base = stack_System_Object(System_Type), .name = "System.intptr",  .size = sizeof(System_intptr) };
struct_System_Type  System_sintptrType  = { .base = stack_System_Object(System_Type), .name = "System.sintptr", .size = sizeof(System_sintptr) };

struct_System_Type  System_booleanType  = { .base = stack_System_Object(System_Type), .name = "System.boolean", .size = sizeof(System_boolean) };

#include "System.values.auto.c"

#include "System.decimal.c"

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
    System_assert(that)
    System_assert(fun)

    System_size f, len;
    System_Type_FunctionInfo info0;
    for (f = 0; f < that->functions.length; ++f) {
        info0 = &__array(that->functions.value)[f];
        if (info0->function == fun) return info0->value;
    }

    if (that->baseType) return System_Type_getMethod(that->baseType, fun);

    __throw_terminate(inline_System_Exception_new("NotImplementedException_new: Method not found"));
}

System_boolean  System_Type_isInstanceOf(System_Type  that, System_Type  other) {
    __assert(other)

    System_Type other_type = other;
    while (other_type) {
        if (that == other_type) return __true;
        other_type = other->baseType;
    }
    return __false;
}

#endif
