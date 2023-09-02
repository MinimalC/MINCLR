/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif

System_String8Dictionary System_Environment_Arguments = null;

System_Size  System_Environment_AuxValues[System_Environment_AuxValues_Length] = { };

struct System_Type_FieldInfo  System_Environment_AuxTypeTypeFields[] = {
    { .name = "NULL", .value = System_Environment_AuxType_NULL },
    { .name = "IGNORE", .value = System_Environment_AuxType_IGNORE },
    { .name = "EXECFD", .value = System_Environment_AuxType_EXECFD },
    { .name = "PHDR", .value = System_Environment_AuxType_PHDR },
    { .name = "PHENT", .value = System_Environment_AuxType_PHENT },
    { .name = "PHNUM", .value = System_Environment_AuxType_PHNUM },
    { .name = "PAGESZ", .value = System_Environment_AuxType_PAGESZ },
    { .name = "BASE", .value = System_Environment_AuxType_BASE },
    { .name = "FLAGS", .value = System_Environment_AuxType_FLAGS },
    { .name = "ENTRY", .value = System_Environment_AuxType_ENTRY },
    { .name = "NOTELF", .value = System_Environment_AuxType_NOTELF },
    { .name = "UID", .value = System_Environment_AuxType_UID },
    { .name = "EUID", .value = System_Environment_AuxType_EUID },
    { .name = "GID", .value = System_Environment_AuxType_GID },
    { .name = "EGID", .value = System_Environment_AuxType_EGID },
    { .name = "CLKTCK", .value = System_Environment_AuxType_CLKTCK },
    { .name = "PLATFORM", .value = System_Environment_AuxType_PLATFORM },
    { .name = "HWCAP", .value = System_Environment_AuxType_HWCAP },
    { .name = "FPUCW", .value = System_Environment_AuxType_FPUCW },
    { .name = "DCACHEBSIZE", .value = System_Environment_AuxType_DCACHEBSIZE },
    { .name = "ICACHEBSIZE", .value = System_Environment_AuxType_ICACHEBSIZE },
    { .name = "UCACHEBSIZE", .value = System_Environment_AuxType_UCACHEBSIZE },
    { .name = "IGNOREPPC", .value = System_Environment_AuxType_IGNOREPPC },
    { .name = "SECURE", .value = System_Environment_AuxType_SECURE },
    { .name = "BASE_PLATFORM", .value = System_Environment_AuxType_BASE_PLATFORM },
    { .name = "RANDOM", .value = System_Environment_AuxType_RANDOM },
    { .name = "HWCAP2", .value = System_Environment_AuxType_HWCAP2 },
    { .name = "INTERP", .value = System_Environment_AuxType_INTERP },
    { .name = "EXECFN", .value = System_Environment_AuxType_EXECFN },
    { .name = "SYSINFO", .value = System_Environment_AuxType_SYSINFO },
    { .name = "SYSINFO_EHDR", .value = System_Environment_AuxType_SYSINFO_EHDR },
    { .name = "L1I_CACHESHAPE", .value = System_Environment_AuxType_L1I_CACHESHAPE },
    { .name = "L1D_CACHESHAPE", .value = System_Environment_AuxType_L1D_CACHESHAPE },
    { .name = "L2_CACHESHAPE", .value = System_Environment_AuxType_L2_CACHESHAPE },
    { .name = "L3_CACHESHAPE", .value = System_Environment_AuxType_L3_CACHESHAPE },
    { .name = "L1I_CACHESIZE", .value = System_Environment_AuxType_L1I_CACHESIZE },
    { .name = "L1I_CACHEGEOMETRY", .value = System_Environment_AuxType_L1I_CACHEGEOMETRY },
    { .name = "L1D_CACHESIZE", .value = System_Environment_AuxType_L1D_CACHESIZE },
    { .name = "L1D_CACHEGEOMETRY", .value = System_Environment_AuxType_L1D_CACHEGEOMETRY },
    { .name = "L2_CACHESIZE", .value = System_Environment_AuxType_L2_CACHESIZE },
    { .name = "L2_CACHEGEOMETRY", .value = System_Environment_AuxType_L2_CACHEGEOMETRY },
    { .name = "L3_CACHESIZE", .value = System_Environment_AuxType_L3_CACHESIZE },
    { .name = "L3_CACHEGEOMETRY", .value = System_Environment_AuxType_L3_CACHEGEOMETRY },
    { .name = "MINSIGSTKSZ", .value = System_Environment_AuxType_MINSIGSTKSZ },
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
	.fields = { 
        .value = &System_Environment_AuxTypeTypeFields, .length = sizeof_array(System_Environment_AuxTypeTypeFields),
    },
};