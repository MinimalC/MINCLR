/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_HashTable)
#include <min/System.HashTable.h>
#endif
#if !defined(code_System_enum)
#define code_System_enum

/** struct System_enum  **/

String8 System_enum_getName(Type type, IntPtr value) {
    Console_assert(type);

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

/** struct System_Type  **/

struct System_Type_FunctionInfo  System_TypeTypeFunctions[] = {
    { .function = base_System_Object_getSipHash, .value = System_Type_getSipHash },
};

struct System_Type System_TypeType = { 
    .base = { .type = typeof_System_Type },
    .name = "System.Type",
	.size = sizeof(struct System_Type),
	.baseType = typeof_System_Object,
	.functions  = { .length = sizeof_array(System_TypeTypeFunctions), .value = &System_TypeTypeFunctions, },
};

struct System_Type System_BoolType     = { .base = { .type = typeof_System_Type }, .name = "System.Bool",    .size = sizeof(System_Bool) };
struct System_Type System_VoidType     = { .base = { .type = typeof_System_Type }, .name = "System.Void",    .size = sizeof(void) };
struct System_Type System_VarType      = { .base = { .type = typeof_System_Type }, .name = "System.Var",     .size = sizeof(void *) };
struct System_Type System_SizeType     = { .base = { .type = typeof_System_Type }, .name = "System.Size",    .size = sizeof(System_Size) };
struct System_Type System_SSizeType    = { .base = { .type = typeof_System_Type }, .name = "System.SSize",   .size = sizeof(System_SSize) };
struct System_Type System_IntPtrType   = { .base = { .type = typeof_System_Type }, .name = "System.IntPtr",  .size = sizeof(System_IntPtr) };
struct System_Type System_SIntPtrType  = { .base = { .type = typeof_System_Type }, .name = "System.SIntPtr", .size = sizeof(System_SIntPtr) };

System_UInt64 System_Type_getSipHash(System_Type that) {
    return System_String8_getSipHash(that->name);
}

System_Type System_Type_getBySipHash__name(System_UInt64 hash, System_String8 name) {
    if (!hash) return null;

    switch (hash) { 
        case typeof_System_Type: return &System_TypeType;
        case typeof_System_Object: return &System_ObjectType;
        case typeof_System_Bool: return &System_BoolType;
        case typeof_System_Void: return &System_VoidType;
        case typeof_System_Var: return &System_VarType;
        case typeof_System_Size: return &System_SizeType;
        case typeof_System_SSize: return &System_SSizeType;
        case typeof_System_IntPtr: return &System_IntPtrType;
        case typeof_System_SIntPtr: return &System_SIntPtrType;
        case typeof_System_UInt8: return &System_UInt8Type;
        case typeof_System_UInt16: return &System_UInt16Type;
        case typeof_System_UInt32: return &System_UInt32Type;
        case typeof_System_UInt64: return &System_UInt64Type;
        case typeof_System_Int8: return &System_Int8Type;
        case typeof_System_Int16: return &System_Int16Type;
        case typeof_System_Int32: return &System_Int32Type;
        case typeof_System_Int64: return &System_Int64Type;
        case typeof_System_Char8: return &System_Char8Type;
        case typeof_System_String8: return &System_String8Type;
        case typeof_System_ErrorCode: return &System_ErrorCodeType;
        case typeof_System_Exception: return &System_ExceptionType;
        case typeof_System_IOException: return &System_IOExceptionType;
        case typeof_System_NotSupportedException: return &System_NotSupportedExceptionType;
        case typeof_System_NotImplementedException: return &System_NotImplementedExceptionType;
        case typeof_System_ArgumentException: return &System_ArgumentExceptionType;
        case typeof_System_InvalidException: return &System_InvalidExceptionType;
        case typeof_System_ELF64Assembly: return &System_ELF64AssemblyType;
        case typeof_System_ELFAssembly_SectionType: return &System_ELFAssembly_SectionTypeType;
    }

    // Enumerate ELFAssembly Symbols

    System_ELF64Assembly assembly = null;
    System_ELF64Assembly_Symbol symbol = null;
    System_HashTable hashtable = null;
    System_Size next = 0;
    do {
        symbol = System_ELF64Assembly_getGlobalSymbol__next("System_TypeTable", &assembly, next++);
        if (symbol && symbol->value) {
            hashtable = (System_HashTable)(assembly->link + symbol->value);
// Console_debugLine("Found GLOBAL System_TypeTable, length {0:uint}", 1, hashtable->length);
            for (Size i = 0; i < hashtable->length; ++i)
                if (hash == array_item(hashtable->items, i).hash)
                    return (System_Type)array_item(hashtable->items, i).value;
        }
    } while (symbol);
    next = 0;
    do {
        symbol = System_ELF64Assembly_getGlobalDynamicSymbol__next("System_TypeTable", &assembly, next++);
        if (symbol && symbol->value) {
            hashtable = (System_HashTable)(assembly->link + symbol->value);
// Console_debugLine("Found DYNAMIC System_TypeTable, length {0:uint}", 1, hashtable->length);
            for (Size i = 0; i < hashtable->length; ++i)
                if (hash == array_item(hashtable->items, i).hash)
                    return (System_Type)array_item(hashtable->items, i).value;
        }
    } while (symbol);

Console_debugLine("System_Type_getBySipHash({0:uint:hex}, \"{1:string}\"): returns void.", 2, hash, !System_String8_isNullOrEmpty(name) ? name : "<Unknown>");
    return &System_VoidType;
}

System_Type System_Type_getBySipHash(System_UInt64 hash) {
    return System_Type_getBySipHash__name(hash, null);
}

System_Var System_Type_getMethod(System_Type  that, System_Var fun) {
    System_Var reture = System_Type_tryMethod(that, fun);
    if (!reture) System_Exception_terminate(new_System_Exception("NotImplementedException: Method not found"));
    return reture;
}

System_Var System_Type_tryMethod(System_Type  that, System_Var fun) {
    Console_assert(that);
    Console_assert(fun);

    System_Type they = that;
    System_Type_FunctionInfo info;
    while (they) {
        for (System_Size f = 0; f < they->functions.length; ++f) {
            info = !they->functions.value ? null : array(they->functions.value) + f;
            if (info && fun == info->function) return info->value;
        }
        if (!they->baseType && System_Type_getSipHash(they) != typeof_System_Object) {
            they = typeof(System_Object);
            continue;
        }
        they = System_Type_getBySipHash(they->baseType);
    }
    return null;
}

System_Bool  System_Type_isAssignableFrom(System_Type  that, System_Type  other) {
    Console_assert(that);
    Console_assert(other);

    System_Type they = that;
    System_Type_InterfaceInfo info;
    while (they) {
        if (System_Type_getSipHash(other) == System_Type_getSipHash(they)) {
            #if DEBUG == DEBUG_System_Type
            System_Console_writeLine("System_Type_isAssignableFrom({0:string}, {1:string})", 2, that->name, other->name);
            #endif
            return true;
        }
        for (System_Size f = 0; f < they->interfaces.length; ++f) {
            info = !they->interfaces.value ? null : array(they->interfaces.value) + f;
            if (info && System_Type_getSipHash(other) == System_Type_getSipHash(info->interfaceType)) {
                #if DEBUG == DEBUG_System_Type
                System_Console_writeLine("System_Type_isAssignableFrom({0:string}, {1:string})", 2, that->name, other->name);
                #endif
                return true;
            }
        }
        they = System_Type_getBySipHash(they->baseType);
    }
    #if DEBUG == DEBUG_System_Type
    System_Console_writeLine("System_Type_isAssignableFrom({0:string}, {1:string}) not", 2, that->name, other->name);
    #endif
    return false;
}

#endif
