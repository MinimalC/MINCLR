/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(
".global _start\n"
".hidden _start\n"
".type _start,\u0040function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n"
"    lea _DYNAMIC(%rip),%rsi\n"
//"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n"
".size _start,.-_start\n"
);
#endif
#if !defined(System_internal)
#include "../System.internal.h"
#endif
#if !defined(have_System_Runtime)
#include <min/System.Runtime.h>
#endif
#if !defined(have_System_ELFAssembly)
#include <min/System.ELFAssembly.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif
#if !defined(have_System_Path)
#include <min/System.Path.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

System_Size * System_Runtime_stack = null;

System_Size System_Runtime_pageSize = 0;

void System_Runtime_start(System_Var  * stack) {

    System_Runtime_stack = (System_Size *)stack;
    System_Size argc = (System_Size)*stack;
    System_String8 * argv = (System_String8 *)(++stack);
    System_Size envc = 0;
    System_String8 * envv = (System_String8 *)(stack += argc + 1);
    while (*stack) { ++envc; ++stack; }

    System_String8 name = null;
    System_Var base = null, exec = null;
    System_Size random = 0;
    System_Bool interp = false;
    System_Size auxc = 0;
    System_Environment_AuxValue auxv = (System_Environment_AuxValue)(++stack);
    for (; auxv[auxc].type; ++auxc, stack += 2) {
        System_Environment_AuxValue aux = auxv + auxc;

        if (aux->type == System_Environment_AuxType_PAGESZ)
            System_Runtime_pageSize = aux->value;

        if (aux->type == System_Environment_AuxType_EXECFN)
            name = (System_String8)aux->value;

        if (aux->type == System_Environment_AuxType_BASE)
            base = (System_Var)aux->value;

        if (aux->type == System_Environment_AuxType_PHDR)
            exec = (System_Var)ROUNDDOWN(aux->value, 4096);

        if (aux->type == System_Environment_AuxType_INTERP)
            interp = aux->value;

        if (aux->type == System_Environment_AuxType_RANDOM)
            random = aux->value;
    }

    System_Console_Arguments_Count = argc;
    System_Console_Arguments = argv;
    #if DEBUG == DEBUG_System_Console_Environment_Arguments || DEBUG == DEBUG_System_ELFAssembly
    if (interp)
    for (System_Size i = 0; i < System_Console_Arguments_Count; ++i) {
        System_Console_writeLine("System_Console_Arguments({0:uint}): {1:string}", 2, i, argv[i]);
    }
    #endif

    String8 keys[256]; System_Stack_clear(keys);
    String8 values[256]; System_Stack_clear(values);
    struct System_String8Dictionary dictionary = {
        .base = { .type = typeof(System_String8Dictionary), },
        .key = &keys, .value = &values, .capacity = 256, .length = 0,
    };
    if (interp) {
        System_Environment_Arguments = &dictionary;
        for (System_Size i = 0; i < envc; ++i) {
            String8 key = envv[i];
            SSize sign = System_String8_indexOf(key, '=');
            if (sign > -1) *(key + sign) = '\0';
            String8 value = key + sign + 1;
            base_System_String8Dictionary_add(&dictionary, key, value);
            #if DEBUG == DEBUG_System_Console_Environment_Arguments || DEBUG == DEBUG_System_ELFAssembly
            System_Console_writeLine("System_Environment_Arguments({0:uint}): {1:string}: {2:string}", 3, i, key, value);
            #endif
        }
    }
    
    System_Environment_AuxValues_Count = auxc;
    System_Environment_AuxValues = auxv;
    #if DEBUG == DEBUG_System_Console_Environment_Arguments || DEBUG == DEBUG_System_ELFAssembly
    if (interp)
    for (System_Size i = 0; i < auxc; ++i) {
        switch (auxv[i].type) {
        case System_Environment_AuxType_EXECFN:
        case System_Environment_AuxType_PLATFORM:
            System_Console_writeLine("System_Environment_AuxValue({0:uint}): type ({1:string}), value {2:string}", 3, i, System_Environment_AuxType_toString(auxv[i].type), auxv[i].value);
            break;
        default:
            System_Console_writeLine("System_Environment_AuxValue({0:uint}): type ({1:string}), value 0x{2:uint:hex}", 3, i, System_Environment_AuxType_toString(auxv[i].type), auxv[i].value);
            break;
        }
    }
    #endif

    System_Thread_PID = System_Syscall_getpid();

    function_System_Runtime_main entry = &System_Runtime_main;
    System_String8 entryName = "System_Runtime_main";
    if (interp) {
        System_String8 fileName = System_Path_getFileName(name);
        for (System_String8 n = fileName; *n; ++n) {
            switch (*n) {
            // case TODO
            case '.':
                *n = '_';
                break;
            }
        }
        System_ELF64Assembly assembly1 = null;
        System_ELF64Assembly_Symbol symbol1 = System_ELF64Assembly_getSymbol(fileName, &assembly1);
        System_Size * symbol1_value = null;
        if (symbol1) {
            symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
            entry = (function_System_Runtime_main)(symbol1_value);
            entryName = (System_String8)System_Memory_addReference((System_Var)fileName);
        }
        else {
            System_String8 fileName2 = System_String8_concat(fileName, "_main");
            symbol1 = System_ELF64Assembly_getSymbol(fileName2, &assembly1);
            if (symbol1) {
                symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
                entry = (function_System_Runtime_main)(symbol1_value);
                entryName = (System_String8)System_Memory_addReference((System_Var)fileName2);
            }
            else {
                System_Memory_free(fileName2);
                fileName2 = System_String8_concat("main_", fileName);
                symbol1 = System_ELF64Assembly_getSymbol(fileName2, &assembly1);
                if (symbol1) {
                    symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
                    entry = (function_System_Runtime_main)(symbol1_value);
                    entryName = (System_String8)System_Memory_addReference((System_Var)fileName2);
                }
            }
            System_Memory_free(fileName2);
        }
        System_Memory_free(fileName);
    }

    #if DEBUG == DEBUG_System_ELFAssembly
    if (interp) System_Console_writeLine__string("This is INTERP");
    System_Console_writeLine("AddressOf System_Runtime_stack: {0:uint:hex}", 1, System_Runtime_stack);
    System_Console_writeLine("AddressOf {0:string}: {1:uint:hex}", 2, entryName, entry);
    System_Console_writeLine("System_Runtime_start: argc {0:uint}, envc {1:uint}, auxc {2:uint}: {3:string}", 4, argc, envc, auxc, argv[0]);
    #endif

    System_Memory_free(entryName);

    int reture = entry(argc, argv);
    #if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("System_Runtime_start: return {0:uint}", 1, reture);
    #endif
    System_Console_exit(reture);
}

#endif
