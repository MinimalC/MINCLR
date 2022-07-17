#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Assembly)
#define have_System_Assembly


/* old */

#define System_Assembly_next  ((void *) -1l)

/* export void System_Assembly_close(void  * that); */
export System_string8  System_Assembly_error();

#if defined(using_System)
#define Assembly_error  System_Assembly_error
#endif


typedef System_int32  System_AssemblyBinding;
/*#if defined(__x86_64__) */

/* Lazy function call binding. */
#define System_AssemblyBinding_Lazy  0x01

/* Immediate function call binding. */
#define System_AssemblyBinding_Now  0x02

/* Mask of binding time value. */
#define	System_AssemblyBinding_BindingMask  0x03

/* Do not load the object. */
#define System_AssemblyBinding_NoLoad  0x04

/* Use deep binding. */
#define System_AssemblyBinding_DeepBind  0x08

/* The symbols of the loaded object and its dependencies are made
   visible as if the object were linked directly into the program.  */
#define System_AssemblyBinding_Global	0x0100

/* Unix98 demands the following flag which is the inverse to System_AssemblyBinding_Global.
   The implementation does this by default and so we can define the value to zero.  */
#define System_AssemblyBinding_Local	0

/* Do not delete object when closed.  */
#define System_AssemblyBinding_NoFree	0x1000

#if defined(using_System)
#define AssemblyBinding  System_AssemblyBinding
#define AssemblyBinding_Lazy  System_AssemblyBinding_Lazy
#define AssemblyBinding_Now  System_AssemblyBinding_Now
#define AssemblyBinding_BindingMask  System_AssemblyBinding_BindingMask
#define AssemblyBinding_NoLoad  System_AssemblyBinding_NoLoad
#define AssemblyBinding_DeepBind  System_AssemblyBinding_DeepBind
#define AssemblyBinding_Global  System_AssemblyBinding_Global
#define AssemblyBinding_Local  System_AssemblyBinding_Local
#define AssemblyBinding_NoFree  System_AssemblyBinding_NoFree
#endif

/* static class System.Assembly */

#define struct_System_Assembly  struct System_Assembly
typedef fixed struct_System_Assembly {
    struct_System_Object base;

    void  * assemblyPtr;
    System_string8  fileName;

}  * System_Assembly;

export struct_System_Type  System_AssemblyType;

export System_Assembly  System_Assembly_open(const System_string8  fileName, System_AssemblyBinding  flags);
export void  * System_Assembly_find(System_Assembly that, const System_string8 name);
export void  * System_Assembly_findGlobal(const System_string8 name);

#define new_System_Assembly()  (base_System_Assembly_init((System_Assembly)System_Memory_allocClass(typeof(System_Assembly))))

#if defined(using_System)
#define struct_Assembly  struct_System_Assembly
#define Assembly  System_Assembly
#define AssemblyType  System_AssemblyType
#define Assembly_new  System_Assembly_new
#define Assembly_open  System_Assembly_open
#define Assembly_find  System_Assembly_find
#endif

/* class System.Assembly */

export void  base_System_Assembly_free(System_Assembly that);
export System_Assembly  base_System_Assembly_init(System_Assembly that);

#define System_Assembly_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Assembly_init(o)  ((function_System_Object_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)

#if defined(using_System)
#define Assembly_free  System_Assembly_free
#define Assembly_init  System_Assembly_init
#endif

#endif
