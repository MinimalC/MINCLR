/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif

System_String8  System_Environment_Arguments[System_Environment_Arguments_Length] = { };

struct System_Environment_AuxValue  System_Environment_AuxValues[System_Environment_AuxValues_Length] = { };

struct System_Type_FieldInfo  System_Environment_AuxTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NULL", .value = System_Environment_AuxType_NULL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IGNORE", .value = System_Environment_AuxType_IGNORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXECFD", .value = System_Environment_AuxType_EXECFD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHDR", .value = System_Environment_AuxType_PHDR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHENT", .value = System_Environment_AuxType_PHENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHNUM", .value = System_Environment_AuxType_PHNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PAGESZ", .value = System_Environment_AuxType_PAGESZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BASE", .value = System_Environment_AuxType_BASE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FLAGS", .value = System_Environment_AuxType_FLAGS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ENTRY", .value = System_Environment_AuxType_ENTRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NOTELF", .value = System_Environment_AuxType_NOTELF },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "UID", .value = System_Environment_AuxType_UID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EUID", .value = System_Environment_AuxType_EUID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GID", .value = System_Environment_AuxType_GID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EGID", .value = System_Environment_AuxType_EGID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CLKTCK", .value = System_Environment_AuxType_CLKTCK },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLATFORM", .value = System_Environment_AuxType_PLATFORM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HWCAP", .value = System_Environment_AuxType_HWCAP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FPUCW", .value = System_Environment_AuxType_FPUCW },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DCACHEBSIZE", .value = System_Environment_AuxType_DCACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ICACHEBSIZE", .value = System_Environment_AuxType_ICACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "UCACHEBSIZE", .value = System_Environment_AuxType_UCACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IGNOREPPC", .value = System_Environment_AuxType_IGNOREPPC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SECURE", .value = System_Environment_AuxType_SECURE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BASE_PLATFORM", .value = System_Environment_AuxType_BASE_PLATFORM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RANDOM", .value = System_Environment_AuxType_RANDOM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HWCAP2", .value = System_Environment_AuxType_HWCAP2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXECFN", .value = System_Environment_AuxType_EXECFN },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYSINFO", .value = System_Environment_AuxType_SYSINFO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYSINFO_EHDR", .value = System_Environment_AuxType_SYSINFO_EHDR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHESHAPE", .value = System_Environment_AuxType_L1I_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHESHAPE", .value = System_Environment_AuxType_L1D_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHESHAPE", .value = System_Environment_AuxType_L2_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHESHAPE", .value = System_Environment_AuxType_L3_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHESIZE", .value = System_Environment_AuxType_L1I_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHEGEOMETRY", .value = System_Environment_AuxType_L1I_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHESIZE", .value = System_Environment_AuxType_L1D_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHEGEOMETRY", .value = System_Environment_AuxType_L1D_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHESIZE", .value = System_Environment_AuxType_L2_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHEGEOMETRY", .value = System_Environment_AuxType_L2_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHESIZE", .value = System_Environment_AuxType_L3_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHEGEOMETRY", .value = System_Environment_AuxType_L3_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MINSIGSTKSZ", .value = System_Environment_AuxType_MINSIGSTKSZ },
};

struct System_Type System_Environment_AuxTypeType = { .base = { .type = typeof(System_Type) },
    .name = "AuxType",
    .size = sizeof(System_Environment_AuxType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Environment_AuxTypeTypeFields, .length = sizeof_array(System_Environment_AuxTypeTypeFields),
    },
};