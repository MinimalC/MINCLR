/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include <min/System.Type.h>
#endif
#if !defined(have_System_ELF32Assembly)
#define have_System_ELF32Assembly

export struct System_Type  System_ELF32AssemblyType;

typedef struct System_ELF32Assembly_Header {
    struct {
        System_Char8  magic[4];
        System_Char8  class;
        System_Char8  endianess;
        System_Char8  elfVersion;
        System_Char8  osABI;
        System_Char8  abiVersion;
        System_Char8  __reserved[7];
    };
    System_UInt16    type;               /* Object file type */
    System_UInt16    machine;            /* Architecture */
    System_UInt32    assemblyVersion;            /* Object file version */
    System_UInt32    entryPoint;              /* Entry point virtual address */
    System_UInt32    programHeaderOffset;              /* Program header table file offset */
    System_UInt32    sectionHeaderOffset;              /* Section header table file offset */
    System_UInt32    processorFlags;              /* Processor-specific flags */
    System_UInt16    headerSize;             /* ELF header size in bytes */
    System_UInt16    programHeaderTableEntrySize;          /* Program header table entry size */
    System_UInt16    programHeaderTableEntryCount;              /* Program header table entry count */
    System_UInt16    sectionHeaderTableEntrySize;          /* Section header table entry size */
    System_UInt16    sectionHeaderTableEntryCount;              /* Section header table entry count */
    System_UInt16    sectionHeaderStringTableIndex;           /* Section header string table index */
} * System_ELF32Assembly_Header;

export struct System_Type  System_ELF32Assembly_HeaderType;

#endif
#if !defined(have_System_ELF64Assembly)
#define have_System_ELF64Assembly

export struct System_Type  System_ELF64AssemblyType;

typedef struct System_ELF64Assembly_Header {
    struct {
        System_Char8  magic[4];
        System_Char8  class;
        System_Char8  endianess;
        System_Char8  elfVersion;
        System_Char8  osABI;
        System_Char8  osABIVersion;
        System_Char8  __reserved[7];
    };
    System_UInt16    type;               /* Object file type */
    System_UInt16    machine;            /* Architecture */
    System_UInt32    assemblyVersion;            /* Object file version */
    System_UInt64    entryPoint;              /* Entry point virtual address */
    System_UInt64    programHeaderOffset;              /* Program header table file offset */
    System_UInt64    sectionHeaderOffset;              /* Section header table file offset */
    System_UInt32    processorFlags;              /* Processor-specific flags */
    System_UInt16    size;             /* ELF header size in bytes */
    System_UInt16    programHeaderTableEntrySize;          /* Program header table entry size */
    System_UInt16    programHeaderTableEntryCount;              /* Program header table entry count */
    System_UInt16    sectionHeaderTableEntrySize;          /* Section header table entry size */
    System_UInt16    sectionHeaderTableEntryCount;              /* Section header table entry count */
    System_UInt16    sectionHeaderStringTableIndex;           /* Section header string table index */
} * System_ELF64Assembly_Header;

export struct System_Type  System_ELF64Assembly_HeaderType;

#endif
#if !defined(have_System_ELFAssembly)
#define have_System_ELFAssembly

export const System_String8 System_ELFAssembly_Magic;
#define System_ELFAssembly_Magic_VALUE  "\177ELF"

#define System_ELFAssembly_Header_MaxSize  65536

#if System_Size_Width == 64
#define System_ELFAssembly  System_ELF64Assembly
#define System_ELFAssemblyType  System_ELF64AssemblyType
#define System_ELFAssembly_Header  System_ELF64Assembly_Header

#else /* if System_Size_Width == 32 */
#define System_ELFAssembly  System_ELF32Assembly
#define System_ELFAssemblyType  System_ELF32AssemblyType
#define System_ELFAssembly_Header  System_ELF32Assembly_Header
#endif

#if defined(using_System)
#define ELFAssembly  System_ELFAssembly
#define ELFAssemblyType  System_ELFAssemblyType
#define ELFAssembly_Header  System_ELFAssembly_Header
#define ELFAssembly_HeaderType  System_ELFAssembly_HeaderType
#endif
#endif