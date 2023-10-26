/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
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

String8 System_enum_getName(Type type, IntPtr value) {
    Debug_assert(type);

    System_Type_FieldInfo info;
    for (Size i = 0; i < type->fields.length; ++i) {
        info = &array(type->fields.value)[i];
        if (info && info->value == value && info->name)
            return info->name;
    }
    return String8_Empty;
}

#endif
#if !defined(code_System_Type)
#define code_System_Type

/*# System_Type #*/

struct System_Type System_TypeType = { .base = { .type = typeof(System_Type) },
    .name = "Type",
	.size = sizeof(struct System_Type),
	.baseType = &System_ObjectType
};

/* Literal Types */

/* sizeof(void) is 1 */
/* sizeof(void *) is sizeof(Size), sizeof(IntPtr) */

struct System_Type System_VoidType     = { .base = { .type = typeof(System_Type) }, .name = "Void",    .size = sizeof(void) };
struct System_Type System_VarType      = { .base = { .type = typeof(System_Type) }, .name = "Var",     .size = sizeof(void *) };
struct System_Type System_SizeType     = { .base = { .type = typeof(System_Type) }, .name = "Size",    .size = sizeof(System_Size) };
struct System_Type System_SSizeType    = { .base = { .type = typeof(System_Type) }, .name = "SSize",   .size = sizeof(System_SSize) };
struct System_Type System_IntPtrType   = { .base = { .type = typeof(System_Type) }, .name = "IntPtr",  .size = sizeof(System_IntPtr) };
struct System_Type System_SIntPtrType  = { .base = { .type = typeof(System_Type) }, .name = "SIntptr", .size = sizeof(System_SIntPtr) };
struct System_Type System_BoolType     = { .base = { .type = typeof(System_Type) }, .name = "Bool",    .size = sizeof(System_Bool) };

struct System_Type System_Type_FunctionInfoType = { .base = { .type = typeof(System_Type) },
	.name = "Type.FunctionInfo",
	.size = sizeof(struct System_Type_FunctionInfo),
	.baseType = &System_ObjectType
};

struct System_Type System_Type_FunctionInfoArrayType = { .base = { .type = typeof(System_Type) },
	.name = "Type.FunctionInfoArray",
	.size = sizeof(struct System_Type_FunctionInfoArray),
	.baseType = &System_ObjectType
};

struct System_Type System_Type_InterfaceInfoType = { .base = { .type = typeof(System_Type) },
	.name = "Type.InterfaceInfo",
	.size = sizeof(struct System_Type_InterfaceInfo),
	.baseType = &System_ObjectType
};

struct System_Type System_Type_InterfaceInfoArrayType = { .base = { .type = typeof(System_Type) },
	.name = "Type.InterfaceInfoArray",
	.size = sizeof(struct System_Type_InterfaceInfoArray),
	.baseType = &System_ObjectType
};

struct System_Type System_Type_FieldInfoType = { .base = { .type = typeof(System_Type) },
	.name = "Type.FieldInfo",
	.size = sizeof(struct System_Type_FieldInfo),
	.baseType = &System_ObjectType
};

struct System_Type System_Type_FieldInfoArrayType = { .base = { .type = typeof(System_Type) },
	.name = "Type.FieldInfoArray",
	.size = sizeof(struct System_Type_FieldInfoArray),
	.baseType = &System_ObjectType
};

System_Var System_Type_getMethod(System_Type  that, System_Var fun) {
    System_Var reture = System_Type_tryMethod(that, fun);
    if (!reture) System_Exception_terminate(new_System_Exception("NotImplementedException: Method not found"));
    return reture;
}

System_Var System_Type_tryMethod(System_Type  that, System_Var fun) {
    Debug_assert(that);
    Debug_assert(fun);

    System_Type they = that;
    System_Type_FunctionInfo info;
    while (they) {
        for (System_Size f = 0; f < they->functions.length; ++f) {
            info = !they->functions.value ? null : array(they->functions.value) + f;
            if (info && fun == info->function) return info->value;
        }
        they = they->baseType;
    }
    return null;
}

System_Bool  System_Type_isAssignableFrom(System_Type  that, System_Type  other) {
    Debug_assert(that);
    Debug_assert(other);

    System_Type they = that;
    System_Type_InterfaceInfo info;
    while (they) {
        if (other == they) return true;
        for (System_Size f = 0; f < they->interfaces.length; ++f) {
            if (they->interfaces.value) {
                info = !they->interfaces.value ? null : array(they->interfaces.value) + f;
                if (info && other == info->interfaceType) return true;
            }
        }
        they = they->baseType;
    }
    return false;
}

#endif
