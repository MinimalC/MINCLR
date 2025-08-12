/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Directory)
#include <min/System.Directory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/** class System_Directory  **/


System_Bool System_Directory_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo));
    System_FileInfo_init(&info, name);
    return System_FileInfo_isDirectory(&info);
}

System_Bool System_Directory_change(System_String8 path) {
    System_Syscall_chdir(path);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return false; // throw
    return true;
}

System_Bool System_Directory_create(System_String8 directoryName) {
    return !System_Syscall_mkdir(directoryName, 0777);
}

System_String8 System_Directory_get_current() {

    System_Char8 buffer[4096]; System_Stack_clear(buffer);
    System_Syscall_getcwd(buffer, 4096);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return null; // throw

    System_Size length = System_String8_get_Length(buffer);
    System_String8 System_Directory_current = System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(buffer, System_Directory_current);

    return System_Directory_current;
}

System_Directory  new_System_Directory() {
    System_Directory that = (System_Directory)System_Memory_allocClass(typeof(System_Directory));
    return that;
}

System_Directory  System_Directory_open(String8 dirName) {

    Directory that = new_Directory();
    if (stack_System_Directory_open(that, dirName)) return that;
    Memory_free(that);
    return null;
}

System_Bool  stack_System_Directory_open(System_Directory that, System_String8 dirName) {

    if (that->dirId) return false;

    System_IntPtr id = System_Syscall_openat(System_Syscall_StandardFile_CurrentWorkingDirectory, dirName,
        System_File_Mode_noControllingTerminal | System_File_Mode_Directory | System_File_Mode_readOnly,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error) {
        System_Exception_throw(new_System_IOException__error(error, "Directory not found"));
        return false;
    }

    that->dirId = id;
    that->name = Memory_addReference(dirName);
    return true;
}

typedef struct Linux_DirectoryEntry64 {
  System_UInt64  inode;
  System_Int64  offset;
  System_UInt16  recordLength;
  System_UInt8  type;
  System_Char8  name[0];
} * Linux_DirectoryEntry64;

System_SSize System_DirectoryEntry_alphacompare(System_DirectoryEntry memory0, System_DirectoryEntry memory1, System_Size itemSize) {
    Size length0 = String8_get_Length(memory0->name);
    Size length1 = String8_get_Length(memory1->name);
    Size length_expected = length0 < length1 ? length0 : length1;
    System_Size length = System_String8_compareSubstring(memory0->name, memory1->name, length_expected);
    if (length == length0) return -1;
    if (length == length1) return 1;
    System_Char8 c0 = memory0->name[length];
    System_Char8 c1 = memory1->name[length];
    return c0 - c1;
}

System_DirectoryEntryArray  System_Directory_list(System_Directory that) {
    Char8 buffer[65536]; Stack_clear(buffer);
    System_Syscall_lseek(that->dirId, 0, System_Origin_Begin);
    Size size = System_Syscall_getdents64(that->dirId, buffer, 65536);
    if (!size) return 0;
    Size linuxC = 0, systemC = 0;
    System_DirectoryEntryArray entries = Memory_allocClass(typeof(System_DirectoryEntryArray));
    while (true) {
        for (Size position = 0; position < size; ) {
            Linux_DirectoryEntry64 linux_directory = (Linux_DirectoryEntry64)(buffer + position);
            position += linux_directory->recordLength;
            ++linuxC;
        }        
        if (!entries->length) {
            entries->length = linuxC;
            entries->value = Memory_allocArray(typeof(System_DirectoryEntry), linuxC);
        }
        else {
            entries->length = linuxC;
            Memory_reallocArray((System_Var ref)&entries->value, linuxC);
        }
        for (Size position = 0; position < size; ) {
            Linux_DirectoryEntry64 linux_directory = (Linux_DirectoryEntry64)(buffer + position);
            System_DirectoryEntry system_directory = &array_item(entries->value, systemC);
            system_directory->inode = linux_directory->inode;
            system_directory->type = linux_directory->type;
            system_directory->name = String8_copy(linux_directory->name);
            position += linux_directory->recordLength;
            ++systemC;
        }
        if (size > 0) {
            size = System_Syscall_getdents64(that->dirId, buffer, 65536);
            continue; 
        }
        break;
    }
    System_Memory_sort(entries->value, systemC, sizeof(struct System_DirectoryEntry), (function_System_Memory_comparison)&System_DirectoryEntry_alphacompare);
    return entries;
}

void System_Directory_close(System_Directory that) {
    if (that->dirId) {
        System_Syscall_close(that->dirId);
        that->dirId = null;
    }
}

void  System_Directory_free(System_Directory that) {
    System_Directory_close(that);
}

struct System_Type_FunctionInfo  System_DirectoryTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_Directory_free },
};

struct System_Type System_DirectoryType = { 
    .base = { .type = typeof(System_Type) }, .name = "Directory",
    .size = sizeof(struct System_Directory), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryTypeFunctions), .value = &System_DirectoryTypeFunctions },
};

struct System_Type System_DirectoryEntryType = { 
    .base = { .type = typeof(System_Type) }, .name = "DirectoryEntry",
    .size = sizeof(struct System_DirectoryEntry),
};


void System_DirectoryEntryArray_free(System_DirectoryEntryArray that) {
    if (that->value) {
        for (Size i = 0; i < that->length; ++i) {
            System_DirectoryEntry directory_entry = &array_item(that->value, i);
            if (directory_entry->name)
                Memory_free(directory_entry->name);
        }
        Memory_free(that->value);
    }
}

struct System_Type_FunctionInfo  System_DirectoryEntryArrayTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_DirectoryEntryArray_free },
};

struct System_Type System_DirectoryEntryArrayType = { 
    .base = { .type = typeof(System_Type) }, .name = "DirectoryEntryArray",
    .size = sizeof(struct System_DirectoryEntryArray), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryEntryArrayTypeFunctions), .value = &System_DirectoryEntryArrayTypeFunctions },
};