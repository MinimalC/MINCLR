#define using_System
#include <min/System.h>


int System_Runtime_main(int argc, char * argv[]) {

    String8 directoryName = null;
    if (argc > 1) {
        directoryName = argv[1];
    }
    if (!directoryName) directoryName = ".";

	struct Directory directory; Stack_clear(directory);
    stack_Directory_open(&directory, directoryName);

    System_DirectoryList directory_list = System_Directory_list__recursive(&directory, true);
    for (Size i = 0; i < directory_list->length; ++i) {
        System_DirectoryEntry directory_entry = &array_item(directory_list->value, i);
        Console_writeLine("inode {0:uint:hex} type {1:uint8} name {2:string}", 3, directory_entry->inode, directory_entry->type, directory_entry->name);
    }
    Memory_free(directory_list);
    Directory_close(&directory);

	return true;	/* false would be FAILED */
}
