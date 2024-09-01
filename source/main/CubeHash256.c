#define using_System
#define using_Crypto
#include <min/System.h>

int CubeHash256_main(int argc, char * argv[]) {

    if (argc == 1) {
        System_Console_writeLine("Use CubeHash256 \"Hallo Welt\" or specify --file HalloWelt.txt", 0);
        System_Console_exit(false);
    }

    struct CubeHash512 cubeHash512;
    struct System_File file;
    String8 hash_value = null;
    
    for (Size i = 1; i < argc; ++i) {
        Stack_clear(cubeHash512); CubeHash512_init__size(&cubeHash512, 256);
        Stack_clearType(file, typeof(System_File));
        if (String8_equals(argv[i], "--file")) {
            if (i + 1 == argc) { 
                System_Console_writeLine("No file specified.", 0); 
                break;
            } 
            if (!System_File_exists(argv[++i])) {
                System_Console_writeLine("File {0:string} not found.", 1, argv[i]); 
                continue;
            }
            if (!stack_System_File_open(&file, argv[i], System_File_Mode_readOnly)) {
                System_Console_writeLine("Can't read file {0:string}.", 1, argv[i]); 
                base_System_File_close(&file);
                continue;
            } 
            System_Size fileSize = base_System_File_get_Length(&file);
            if (!fileSize) {
                System_Console_writeLine("Empty: {0:string}", 1, argv[i]); 
                base_System_File_close(&file);
                continue;
            }
            String8 text = System_Memory_allocArray(typeof(System_Char8), fileSize + 1);
            base_System_File_read(&file, text, fileSize);
            base_System_File_close(&file);

            CubeHash512_update(&cubeHash512, text, fileSize);
            CubeHash512_final(&cubeHash512);
            hash_value = Crypto_CubeHash512_toString(&cubeHash512);
            System_Console_writeLine("0x{1:string} {0:string}", 2, argv[i], hash_value);
            Memory_free(text);
            Memory_free(hash_value);
            continue;
        }
        CubeHash512_update(&cubeHash512, argv[i], String8_get_Length(argv[i]));
        CubeHash512_final(&cubeHash512);
        hash_value = Crypto_CubeHash512_toString(&cubeHash512);
        System_Console_writeLine("0x{1:string}: {0:string}", 2, argv[i], hash_value);
        Memory_free(hash_value);
    }
    return true;
}
