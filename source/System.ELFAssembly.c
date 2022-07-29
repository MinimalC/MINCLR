/* Gemeinfrei. Public Domain. */
#if !defined(internal_System)
#include "internal.System.h"
#endif
#if !defined(have_System_ELFAssembly)
#include <min/System.ELFAssembly.h>
#endif
#if !defined(code_System_ELF32Assembly)
#define code_System_ELF32Assembly

struct System_Type  System_ELF32AssemblyType = { .base = { .type = typeof(System_Type), }, .name = "System.ELF32Assembly", };

#endif
#if !defined(code_System_ELF64Assembly)
#define code_System_ELF64Assembly

struct System_Type  System_ELF64AssemblyType = { .base = { .type = typeof(System_Type), }, .name = "System.ELF64Assembly", };

#endif