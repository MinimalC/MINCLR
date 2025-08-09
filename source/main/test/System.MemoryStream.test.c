#define using_System
#include <min/System.h>

System_Char8 pretext[] =
    "#define using_System\n"
    "#define using_Crypto\n"
    "#include <min/System.h>\n";

int System_MemoryStream_test_main (int argc, String8 argv[]) {

    if (argc < 2) {
        Console_writeLine__string("Usage: MemoryStream_test file");
        return false;
    }

    MemoryStream stream = new_System_MemoryStream();

    String8 fileName = argv[1];
    File file = System_File_open(fileName, System_File_Mode_readOnly);
    Size fileSize = System_File_get_Length(file);

    Char8 buffer[65536]; Stack_clear(buffer);
    Size bytes = 0;
    while (0 < (bytes = System_File_read(file, buffer, 65536)))
        System_MemoryStream_write__string_size(stream, buffer, bytes);

    System_File_close(file);
    System_Console_writeLine("MemoryStream size*1 {1:uint}, capacity {2:uint}, position {3:uint}", 4,
        stream->buffer, stream->size, stream->capacity, stream->position);

    System_MemoryStream_set_Length(stream, fileSize / 2);

    System_Console_writeLine("MemoryStream size/2 {1:uint}, capacity {2:uint}, position {3:uint}", 4,
        stream->buffer, stream->size, stream->capacity, stream->position);

    Memory_free(buffer);
    Memory_free(file);
    Memory_free(stream);
    return false;
}
