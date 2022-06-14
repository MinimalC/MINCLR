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

struct_System_string8 STRING8_System_Type = "System.Type";

struct_System_String STRING_System_Type = const_System_String(STRING8_System_Type);

struct_System_Type  System_TypeType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_Type,
	.size = sizeof(struct_System_Type),
	.baseType = &System_ObjectType
};

/* Literal Types */

/* sizeof(void) is 1 */
/* sizeof(void *) is sizeof(__size), sizeof(__intptr) */

struct_System_String  STRING_System_void    = const_System_String("System.void");
struct_System_String  STRING_System_var     = const_System_String("System.var");
struct_System_String  STRING_System_size    = const_System_String("System.size");
struct_System_String  STRING_System_ssize   = const_System_String("System.ssize");
struct_System_String  STRING_System_intptr  = const_System_String("System.intptr");
struct_System_String  STRING_System_sintptr = const_System_String("System.sintptr");
struct_System_String  STRING_System_boolean = const_System_String("System.boolean");

struct_System_Type  System_voidType     = { .base = stack_System_Object(System_Type), .name = &STRING_System_void,    .size = sizeof(void) };
struct_System_Type  System_varType      = { .base = stack_System_Object(System_Type), .name = &STRING_System_var,     .size = sizeof(void *) };
struct_System_Type  System_sizeType     = { .base = stack_System_Object(System_Type), .name = &STRING_System_size,    .size = sizeof(System_size) };
struct_System_Type  System_ssizeType    = { .base = stack_System_Object(System_Type), .name = &STRING_System_ssize,   .size = sizeof(System_ssize) };
struct_System_Type  System_intptrType   = { .base = stack_System_Object(System_Type), .name = &STRING_System_intptr,  .size = sizeof(System_intptr) };
struct_System_Type  System_sintptrType  = { .base = stack_System_Object(System_Type), .name = &STRING_System_sintptr, .size = sizeof(System_sintptr) };

struct_System_Type  System_booleanType  = { .base = stack_System_Object(System_Type), .name = &STRING_System_boolean, .size = sizeof(System_boolean) };

#include "System.values.auto.c"

#include "System.decimal.c"

struct_System_String  STRING_System_Type_FunctionInfo = const_System_String("System.Type.FunctionInfo");

struct_System_Type  System_Type_FunctionInfoType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_FunctionInfo,
	.size = sizeof(struct_System_Type_FunctionInfo),
	.baseType = &System_ObjectType
};

struct_System_String  STRING_System_Type_FunctionInfoArray = const_System_String("System.Type.FunctionInfoArray");

struct_System_Type  System_Type_FunctionInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_FunctionInfoArray,
	.size = sizeof(struct_System_Type_FunctionInfoArray),
	.baseType = &System_ObjectType
};

struct_System_String  STRING_System_Type_InterfaceInfo = const_System_String("System.Type.InterfaceInfo");

struct_System_Type  System_Type_InterfaceInfoType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_InterfaceInfo,
	.size = sizeof(struct_System_Type_InterfaceInfo),
	.baseType = &System_ObjectType
};

struct_System_String  STRING_System_Type_InterfaceInfoArray = const_System_String("System.Type.InterfaceInfoArray");

struct_System_Type  System_Type_InterfaceInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_InterfaceInfoArray,
	.size = sizeof(struct_System_Type_InterfaceInfoArray),
	.baseType = &System_ObjectType
};

struct_System_String  STRING_System_Type_FieldInfo = const_System_String("System.Type.FieldInfo");

struct_System_Type  System_Type_FieldInfoType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_FieldInfo,
	.size = sizeof(struct_System_Type_FieldInfo),
	.baseType = &System_ObjectType
};

struct_System_String  STRING_System_Type_FieldInfoArray = const_System_String("System.Type.FieldInfoArray");

struct_System_Type  System_Type_FieldInfoArrayType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_Type_FieldInfoArray,
	.size = sizeof(struct_System_Type_FieldInfoArray),
	.baseType = &System_ObjectType
};

void  System_function_void(void) { }

void  System_function_that(System_Object that) { __unused(that) }

System_var System_function_that_return(System_Object that) { __unused(that) return __null; }

System_var System_Type_getMethod(System_Type  that, System_var function) {
    System_assert(that)

    for (System_size i = 0; i < that->functions.length; ++i) {

        struct_System_Type_FunctionInfo info =  __array(that->functions.value)[i];

        if (info.function == function) {
            return info.value;
        }
    }

    if (that->baseType) return System_Type_getMethod(that->baseType, function);

    __throw_terminate(inline_System_Exception_new("NotImplementedException_new: Method not found"));
}

System_boolean  System_Type_isAssignableFrom(System_Type  that, System_Type  other) {
    __assert(other)

    System_Type other_type = other;
    while (other_type) {
        if (that == other_type) return __true;
        other_type = other->baseType;
    }
    return __false;
}

#endif
