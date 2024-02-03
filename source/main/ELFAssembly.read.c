
#include <min/System.String8.h>
#include <min/System.Console.h>
#include <min/System.Decimal.h>
#include <min/System.Memory.h>
#include <min/System.File.h>
#include <min/System.ELFAssembly.h>

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 2) {
        System_Console_writeLine__string("Usage: ELFAssembly.read <file>");
        return false;
    }

    struct System_ELF64Assembly assembly; System_Stack_clearType(assembly, typeof(System_ELF64Assembly));
    System_ELF64Assembly_read__print(&assembly, argv[1], true);

    return true;
}
