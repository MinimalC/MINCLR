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
#if !defined(have_System_MemoryStream)
#include <min/System.MemoryStream.h>
#endif

/** struct System_Directory  **/

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
    System_UInt64  offset;
    System_UInt16  recordLength;
    System_UInt8  type;
    System_Char8  name[0];
} * Linux_DirectoryEntry64;

System_SSize System_DirectoryEntry_alphacompare(System_DirectoryEntry memory0, System_DirectoryEntry memory1, System_Size itemSize) {
    Size length0 = String8_get_Length(memory0->name);
    Size length1 = String8_get_Length(memory1->name);
    Size length_expected = length0 < length1 ? length0 : length1;
    System_Size length = System_String8_compareSubstring(memory0->name, memory1->name, length_expected);
    if (length == length0 && length == length1) return 0;
    if (length == length0) return -1;
    if (length == length1) return 1;
    System_Char8 c0 = memory0->name[length];
    System_Char8 c1 = memory1->name[length];
    return c0 - c1;
}

System_DirectoryList  System_Directory_list(System_Directory that) {
    return System_Directory_list__hidden(that, false);
}

System_DirectoryList  System_Directory_list__hidden(System_Directory that, System_Bool hidden) {
    Char8 buffer[65536]; Stack_clear(buffer);
    // System_Syscall_lseek(that->dirId, 0, System_Origin_Begin);
    Size size = System_Syscall_getdents64(that->dirId, buffer, 65536);
    Size linuxC = 0, systemC = 0;
    System_DirectoryList entries = Memory_allocClass(typeof(System_DirectoryList));
    entries->name = String8_copy(that->name);
    if (!size) return entries;
    struct MemoryStream stream; Stack_clear(stream);
    stack_System_MemoryStream_open(&stream);
    MemoryStream_write__char(&stream, '\0');
    while (size) {
        for (Size position = 0; position < size; ) {
            Linux_DirectoryEntry64 linux_directory = (Linux_DirectoryEntry64)(buffer + position);
            position += linux_directory->recordLength;
            if (!hidden && String8_get_Length(linux_directory->name) > 1 && !String8_equals(linux_directory->name, ".."))
                if (String8_equalsSubstring(linux_directory->name, ".", 1))
                    continue;
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
            position += linux_directory->recordLength;
            if (!hidden && String8_get_Length(linux_directory->name) > 1 && !String8_equals(linux_directory->name, ".."))
                if (String8_equalsSubstring(linux_directory->name, ".", 1))
                    continue;
            System_DirectoryEntry system_directory = &array_item(entries->value, systemC);
            system_directory->inode = linux_directory->inode;
            system_directory->type = linux_directory->type;
            system_directory->name = (System_Var)stream.position;
            MemoryStream_write__string(&stream, linux_directory->name);
            MemoryStream_write__char(&stream, '\0');
            ++systemC;
        }
        size = System_Syscall_getdents64(that->dirId, buffer, 65536);
    }
    entries->scratch = MemoryStream_final(&stream);
    for (Size s = 0; s < systemC; ++s) {
        System_DirectoryEntry system_directory = &array_item(entries->value, s);
        system_directory->name = (System_Var)system_directory->name + (System_Size)entries->scratch;
    }
    System_Memory_sort(entries->value, systemC, sizeof(struct System_DirectoryEntry), (function_System_Memory_comparison)&System_DirectoryEntry_alphacompare);
    return entries;
}

System_DirectoryList  System_Directory_list__recursive(System_Directory that, System_Bool recursive) {
    return System_Directory_list__recursive_hidden(that, recursive, false);
}

System_DirectoryList  System_Directory_list__recursive_hidden(System_Directory that, System_Bool recursive, System_Bool hidden) {

    System_DirectoryList directories[2048]; Stack_clear(directories); Size directoriesC = 1;
    System_Char8 directoryName[4096]; Stack_clear(directoryName); Size directoryNameL = 0;
    directories[0] = System_Directory_list__hidden(that, hidden);

    if (!recursive) return directories[0];

    for (Size position = 0; position < directoriesC; ++position) {
        DirectoryList list = directories[position];
        for (Size position1 = 0; position1 < list->length; ++position1) {
            DirectoryEntry entry = &array_item(list->value, position1);
            if (entry->type == System_Directory_Type_Directory) {
                if (String8_equals(entry->name, ".")) continue;
                if (String8_equals(entry->name, "..")) continue;
                directoryNameL = String8_copyTo(list->name, directoryName);
                directoryName[directoryNameL++] = '/';
                directoryNameL += String8_copyTo(entry->name, directoryName + directoryNameL);
                directoryName[directoryNameL++] = '\0';
                struct System_Directory directory; Stack_clear(directory);
                if (stack_System_Directory_open(&directory, directoryName)) {
                    if (directoriesC < 2048)
                        directories[directoriesC++] = System_Directory_list__hidden(&directory, hidden);
                    // todo: else throw?
                }
                System_Directory_free(&directory);
            }   
        }
    }

    // Now move them all together
    Size new_size = directories[0]->length;
    for (Size position = 1; position < directoriesC; ++position) {
        new_size += directories[position]->length - 2;
    }
    struct MemoryStream stream; Stack_clear(stream);
    stack_System_MemoryStream_open(&stream);
    MemoryStream_write__char(&stream, '\0');
    for (Size position1 = 0; position1 < directories[0]->length; ++position1) {
        DirectoryEntry entry = &array_item(directories[0]->value, position1);
        String8 entry_name = entry->name;
        entry->name = (System_Var)stream.position;
        MemoryStream_write__string(&stream, directories[0]->name);
        MemoryStream_write__char(&stream, '/');
        MemoryStream_write__string(&stream, entry_name);
        MemoryStream_write__char(&stream, '\0');
    }
    if (new_size > directories[0]->length) {
        Size position2 = directories[0]->length;
        Memory_reallocArray((System_Var ref)&directories[0]->value, new_size);
        for (Size position = 1; position < directoriesC; ++position) {
            DirectoryList list = directories[position];
            for (Size position1 = 0; position1 < list->length; ++position1) {
                DirectoryEntry entry = &array_item(list->value, position1);
                if (entry->type == System_Directory_Type_Directory) {
                    if (String8_equals(entry->name, ".")) continue;
                    if (String8_equals(entry->name, "..")) continue;
                }
                String8 entry_name = entry->name;
                DirectoryEntry other = &array_item(directories[0]->value, position2++);
                Memory_moveTo((System_Var)entry, sizeof(struct System_DirectoryEntry), (System_Var)other);
                other->name = (System_Var)stream.position;
                MemoryStream_write__string(&stream, list->name);
                MemoryStream_write__char(&stream, '/');
                MemoryStream_write__string(&stream, entry_name);
                MemoryStream_write__char(&stream, '\0');
            }
        }
        directories[0]->length = position2;
    }
    for (Size position = 1; position < directoriesC; ++position) {
        Memory_free(directories[position]);
    }
    Memory_free(directories[0]->scratch);
    directories[0]->scratch = MemoryStream_final(&stream);
    for (Size s = 0; s < directories[0]->length; ++s) {
        System_DirectoryEntry system_directory = &array_item(directories[0]->value, s);
        system_directory->name = (System_Var)system_directory->name + (System_Size)directories[0]->scratch;
    }
    System_Memory_sort(directories[0]->value, directories[0]->length, sizeof(struct System_DirectoryEntry), (function_System_Memory_comparison)&System_DirectoryEntry_alphacompare);
    return directories[0];
}

void System_Directory_close(System_Directory that) {
    if (that->dirId) {
        System_Syscall_close(that->dirId);
        that->dirId = null;
    }
}

void  System_Directory_free(System_Directory that) {
    System_Directory_close(that);
    if (that->name) Memory_free(that->name);
}

struct System_Type_FunctionInfo  System_DirectoryTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_Directory_free },
};

struct System_Type System_DirectoryType = { 
    .base = { .type = typeof(System_Type) }, .name = "Directory",
    .size = sizeof(struct System_Directory), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryTypeFunctions), .value = &System_DirectoryTypeFunctions },
};

/*void System_DirectoryEntry_free(System_DirectoryEntry that) {
    // if (that->name) Memory_free(that->name);
}

struct System_Type_FunctionInfo  System_DirectoryEntryTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_DirectoryEntry_free },
};*/

struct System_Type System_DirectoryEntryType = { 
    .base = { .type = typeof(System_Type) }, .name = "DirectoryEntry",
    .size = sizeof(struct System_DirectoryEntry),
    // .functions = { .length = sizeof_array(System_DirectoryEntryTypeFunctions), .value = &System_DirectoryEntryTypeFunctions },
};

void System_DirectoryList_free(System_DirectoryList that) {
    if (that->name) Memory_free(that->name);
    if (that->value) {
        /*for (Size i = 0; i < that->length; ++i) {
            System_DirectoryEntry directory_entry = &array_item(that->value, i);
            System_DirectoryEntry_free(directory_entry);
        }*/
        Memory_free(that->value);
    }
    if (that->scratch) Memory_free(that->scratch);
}

struct System_Type_FunctionInfo  System_DirectoryListTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_DirectoryList_free },
};

struct System_Type System_DirectoryListType = { 
    .base = { .type = typeof(System_Type) }, .name = "DirectoryList",
    .size = sizeof(struct System_DirectoryList), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryListTypeFunctions), .value = &System_DirectoryListTypeFunctions },
};