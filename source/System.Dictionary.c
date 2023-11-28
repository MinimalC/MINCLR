/* Gemeinfrei. Public Domain. */

#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Dictionary)
#include <min/System.Dictionary.h>
#endif
#if !defined(code_auto_System_Dictionary)
#define code_auto_System_Dictionary

/*# System_Dictionary #*/

System_Dictionary  new_System_Dictionary() {
    System_Dictionary that = (System_Dictionary)System_Memory_allocClass(typeof(System_Dictionary));
    base_System_Dictionary_init(that);
    return that;
}

void  base_System_Dictionary_init(System_Dictionary that) {

}
void  base_System_Dictionary_free(System_Dictionary that) {

}
struct System_Type_FunctionInfo  System_DictionaryTypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = base_System_Dictionary_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Dictionary_free },
};
struct System_Type System_DictionaryType = { .base = { .type = typeof(System_Type) },
    .name = "Dictionary",
    .size = sizeof(struct System_Dictionary),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_DictionaryTypeFunctions), .value = &System_DictionaryTypeFunctions
    },
};
#endif
