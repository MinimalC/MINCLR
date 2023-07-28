/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif

System_String8  System_Environment_Arguments[System_Environment_Arguments_Length] = { };

System_Size  System_Environment_AuxValues[System_Environment_AuxValues_Length] = { };

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
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "INTERP", .value = System_Environment_AuxType_INTERP },
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

System_String8 System_Environment_AuxType_toString(System_Environment_AuxType value) {
    switch (value) {
    case System_Environment_AuxType_NULL: return "NULL";
    case System_Environment_AuxType_IGNORE: return "IGNORE";
    case System_Environment_AuxType_EXECFD: return "EXECFD";
    case System_Environment_AuxType_PHDR: return "PHDR";
    case System_Environment_AuxType_PHENT: return "PHENT";
    case System_Environment_AuxType_PHNUM: return "PHNUM";
    case System_Environment_AuxType_PAGESZ: return "PAGESZ";
    case System_Environment_AuxType_BASE: return "BASE";
    case System_Environment_AuxType_FLAGS: return "FLAGS";
    case System_Environment_AuxType_ENTRY: return "ENTRY";
    case System_Environment_AuxType_NOTELF: return "NOTELF";
    case System_Environment_AuxType_UID: return "UID";
    case System_Environment_AuxType_EUID: return "EUID";
    case System_Environment_AuxType_GID: return "GID";
    case System_Environment_AuxType_EGID: return "EGID";
    case System_Environment_AuxType_CLKTCK: return "CLKTCK";
    case System_Environment_AuxType_PLATFORM: return "PLATFORM";
    case System_Environment_AuxType_HWCAP: return "HWCAP";
    case System_Environment_AuxType_FPUCW: return "FPUCW";
    case System_Environment_AuxType_DCACHEBSIZE: return "DCACHEBSIZE";
    case System_Environment_AuxType_ICACHEBSIZE: return "ICACHEBSIZE";
    case System_Environment_AuxType_UCACHEBSIZE: return "UCACHEBSIZE";
    case System_Environment_AuxType_IGNOREPPC: return "IGNOREPPC";
    case System_Environment_AuxType_SECURE: return "SECURE";
    case System_Environment_AuxType_BASE_PLATFORM: return "BASE_PLATFORM";
    case System_Environment_AuxType_RANDOM: return "RANDOM";
    case System_Environment_AuxType_HWCAP2: return "HWCAP2";
    case System_Environment_AuxType_INTERP: return "INTERP";
    case System_Environment_AuxType_EXECFN: return "EXECFN";
    case System_Environment_AuxType_SYSINFO: return "SYSINFO";
    case System_Environment_AuxType_SYSINFO_EHDR: return "SYSINFO_EHDR";
    case System_Environment_AuxType_L1I_CACHESHAPE: return "L1I_CACHESHAPE";
    case System_Environment_AuxType_L1D_CACHESHAPE: return "L1D_CACHESHAPE";
    case System_Environment_AuxType_L2_CACHESHAPE: return "L2_CACHESHAPE";
    case System_Environment_AuxType_L3_CACHESHAPE: return "L3_CACHESHAPE";
    case System_Environment_AuxType_L1I_CACHESIZE: return "L1I_CACHESIZE";
    case System_Environment_AuxType_L1I_CACHEGEOMETRY: return "L1I_CACHEGEOMETRY";
    case System_Environment_AuxType_L1D_CACHESIZE: return "L1D_CACHESIZE";
    case System_Environment_AuxType_L1D_CACHEGEOMETRY: return "L1D_CACHEGEOMETRY";
    case System_Environment_AuxType_L2_CACHESIZE: return "L2_CACHESIZE";
    case System_Environment_AuxType_L2_CACHEGEOMETRY: return "L2_CACHEGEOMETRY";
    case System_Environment_AuxType_L3_CACHESIZE: return "L3_CACHESIZE";
    case System_Environment_AuxType_L3_CACHEGEOMETRY: return "L3_CACHEGEOMETRY";
    case System_Environment_AuxType_MINSIGSTKSZ: return "MINSIGSTKSZ";
    default: return "UNKNOWN";
    }
}

struct System_Type System_Environment_AuxTypeType = { .base = { .type = typeof(System_Type) },
    .name = "AuxType",
    .size = sizeof(System_Environment_AuxType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Environment_AuxTypeTypeFields, .length = sizeof_array(System_Environment_AuxTypeTypeFields),
    },
};