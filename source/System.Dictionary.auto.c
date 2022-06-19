/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_Dictionary)
#define code_auto_System_Dictionary
/*# System_Dictionary #*/
System_Dictionary  System_Dictionary_new() {
    return inline_System_Dictionary_new();
}
System_Dictionary  base_System_Dictionary_init(System_Dictionary that) {
    base_System_Object_init((System_Object)that);
    return that;
}
void  base_System_Dictionary_free(System_Dictionary that) {
    base_System_Object_free((System_Object)that);
}
struct_System_Type_FunctionInfo  System_DictionaryTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Dictionary_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Dictionary_free },
};
struct_System_Type  System_DictionaryType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.Dictionary",
    .size = sizeof(struct_System_Dictionary),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_DictionaryTypeFunctions), .value = &System_DictionaryTypeFunctions
    },
};
#endif
