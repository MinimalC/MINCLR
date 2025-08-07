/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_System_String8Dictionary)
#include "System.String8Dictionary.h"
#endif
#if !defined(have_System_Environment)
#define have_System_Environment

export struct System_Type  System_EnvironmentType;

export System_Size System_Environment_Arguments_Count;
export System_String8 * System_Environment_Arguments;

typedef unsigned System_Environment_AuxType;
enum {
    System_Environment_AuxType_NULL = 0,
    System_Environment_AuxType_IGNORE = 1,
    System_Environment_AuxType_EXECFD = 2,
    System_Environment_AuxType_PHDR = 3,
    System_Environment_AuxType_PHENT = 4,
    System_Environment_AuxType_PHNUM = 5,
    System_Environment_AuxType_PAGESZ = 6,
    System_Environment_AuxType_BASE = 7,
    System_Environment_AuxType_FLAGS = 8,
    System_Environment_AuxType_ENTRY = 9,
    System_Environment_AuxType_NOTELF = 10,
    System_Environment_AuxType_UID = 11,
    System_Environment_AuxType_EUID = 12,
    System_Environment_AuxType_GID = 13,
    System_Environment_AuxType_EGID = 14,
    System_Environment_AuxType_CLKTCK = 17,
    System_Environment_AuxType_PLATFORM = 15,
    System_Environment_AuxType_HWCAP = 16,
    System_Environment_AuxType_FPUCW = 18,
    System_Environment_AuxType_DCACHEBSIZE = 19,
    System_Environment_AuxType_ICACHEBSIZE = 20,
    System_Environment_AuxType_UCACHEBSIZE = 21,
    System_Environment_AuxType_IGNOREPPC = 22,
    System_Environment_AuxType_SECURE = 23,
    System_Environment_AuxType_BASE_PLATFORM = 24,
    System_Environment_AuxType_RANDOM = 25,
    System_Environment_AuxType_HWCAP2 = 26,
    System_Environment_AuxType_INTERP = 27, // new
    System_Environment_AuxType_EXECFN = 31,
    System_Environment_AuxType_SYSINFO = 32,
    System_Environment_AuxType_SYSINFO_EHDR = 33,

    System_Environment_AuxType_L1I_CACHESHAPE = 34,
    System_Environment_AuxType_L1D_CACHESHAPE = 35,
    System_Environment_AuxType_L2_CACHESHAPE = 36,
    System_Environment_AuxType_L3_CACHESHAPE = 37,
    System_Environment_AuxType_L1I_CACHESIZE = 40,
    System_Environment_AuxType_L1I_CACHEGEOMETRY = 41,
    System_Environment_AuxType_L1D_CACHESIZE = 42,
    System_Environment_AuxType_L1D_CACHEGEOMETRY = 43,
    System_Environment_AuxType_L2_CACHESIZE = 44,
    System_Environment_AuxType_L2_CACHEGEOMETRY = 45,
    System_Environment_AuxType_L3_CACHESIZE = 46,
    System_Environment_AuxType_L3_CACHEGEOMETRY = 47,

    System_Environment_AuxType_MINSIGSTKSZ = 51,
};

export System_String8 System_Environment_AuxType_toString(System_Environment_AuxType value);

export struct System_Type  System_Environment_AuxTypeType;

typedef struct System_Environment32_AuxValue {
    System_UInt32 type;
    System_UInt32 value;
} * System_Environment32_AuxValue;

export struct System_Type  System_Environment32_AuxValueType;

typedef struct System_Environment64_AuxValue {
    System_UInt64 type;
    System_UInt64 value;
} * System_Environment64_AuxValue;

export struct System_Type  System_Environment64_AuxValueType;

#if System_Size_Bits == 32
#define System_Environment_AuxValue  System_Environment32_AuxValue

#else /* if System_Size_Bits == 64 */
#define System_Environment_AuxValue  System_Environment64_AuxValue
#endif

export System_Environment_AuxValue System_Environment_AuxValues;
export System_Size System_Environment_AuxValues_Count;

#endif
