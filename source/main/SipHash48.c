#define using_System
#define using_Crypto
#include <min/System.h>

int SipHash48_main(int argc, char * argv[]) {

    if (argc == 1) {
        System_Console_writeLine("Use SipHash \"Hallo Welt\" or specify --file HalloWelt.txt", 0);
        System_Console_exit(false);
    }

    struct SipHash48 sipHash48;
    struct System_File file;

    for (Size i = 1; i < argc; ++i) {
        Stack_clear(sipHash48); SipHash48_init(&sipHash48);
        Stack_clearType(file, typeof(System_File));
        UInt64 hash_value = 0;
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
                System_File_close(&file);
                continue;
            } 
            System_Size fileSize = System_File_get_Length(&file);
            if (!fileSize) {
                System_Console_writeLine("Empty: {0:string}", 1, argv[i]); 
                System_File_close(&file);
                continue;
            }
            String8 text = System_Memory_allocArray(typeof(System_Char8), fileSize + 1);
            System_File_read(&file, text, fileSize);
            System_File_close(&file);

            SipHash48_update(&sipHash48, text, fileSize);
            hash_value = SipHash48_final(&sipHash48);
            System_Console_writeLine("0x{1:uint64:hex} {0:string}", 2, argv[i], hash_value);
            Memory_free(text);
            continue;
        }
        SipHash48_update(&sipHash48, argv[i], String8_get_Length(argv[i]));
        hash_value = SipHash48_final(&sipHash48);
        System_Console_writeLine("0x{1:uint64:hex}: {0:string}", 2, argv[i], hash_value);
    }
    return true;
}
