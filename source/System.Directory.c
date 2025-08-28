/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Path)
#include <min/System.Path.h>
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
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo)); System_FileInfo_init(&info, name);
    return info.status.mode & FileInfo_Type_Directory;
}

System_Bool System_Directory_change(System_String8 path) {
    System_Syscall_chdir(path);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return false; // throw
    return true;
}

System_Bool System_Directory_create(System_String8 directoryName) {
    return System_Directory_create__recursive(directoryName, null);
}

System_Bool System_Directory_create__recursive(System_String8 rootDirectoryName, System_String8 recursive) {
    System_ErrorCode error = 0;
    if (!recursive) {
        System_Syscall_mkdir(rootDirectoryName, 0777);
        error = System_Syscall_get_Error();
        if (error) {
            System_Exception_throw(new_System_IOException__error(error, "Directory not removed"));
            return false;
        }
        return true;
    }
    String8 directory0Name = String8_copy(recursive);
    String8 directory[8]; Stack_clear(directory); Size directoryC = 0;
    while (directoryC < 8) {
        Size directory0NameL = String8_get_Length(directory0Name);
        if (directory0Name[directory0NameL - 1] == '/') 
            directory0Name[directory0NameL - 1] = '\0';
        String8 directory1Name = Path_getDirectoryName(directory0Name);
        String8 file1Name = Path_getFileName(directory0Name);

        if (String8_isNullOrEmpty(file1Name)) {
            Memory_free(file1Name);
            Memory_free(directory1Name);
            break;
        }
        directory[directoryC++] = file1Name;
        if (String8_isNullOrEmpty(directory1Name)) {
            Memory_free(directory1Name);
            break;
        }
        Memory_free(directory0Name);
        directory0Name = directory1Name;
    }
    Memory_free(directory0Name);

    String8 final_directory = String8_copy(rootDirectoryName);
    Size final_directoryL = String8_get_Length(final_directory);
    if (final_directory[final_directoryL - 1] == '/') 
        final_directory[final_directoryL - 1] = '\0';
    Size dir = directoryC;
    struct FileInfo info; Stack_clear(info);
    for (; dir; --dir) {
        String8_exchange(&final_directory, String8_concat3(final_directory, "/", directory[dir - 1]));
        FileInfo_init(&info, final_directory);
        if (!info.status.iNodeId) {
            System_Syscall_mkdir(final_directory, 0777);
            error = System_Syscall_get_Error();
            if (error) {
                System_Exception_throw(new_System_IOException__error(error, "Directory not created"));
                // Console_writeLine("Exception: Directory_create: not created {0:string}", 1, final_directory);
                break;
            }
            // Console_writeLine("Exception: Directory_create: created {0:string}", 1, final_directory);
        }
        // else Console_writeLine("Exception: Directory_create: exists already {0:string}", 1, final_directory);
    }
    Memory_free(final_directory);
    for (Size d = 0; d < directoryC; ++d) Memory_free(directory[d]);
    if (dir) return false;
    return true;
}

System_Bool System_Directory_remove(System_String8 rootDirectoryName) {
    return System_Directory_remove__recursive(rootDirectoryName, null);
}

System_Bool System_Directory_remove__recursive(System_String8 rootDirectoryName, System_String8 recursive) {
    System_ErrorCode error = 0;
    if (!recursive) {
        System_Syscall_rmdir(rootDirectoryName);
        error = System_Syscall_get_Error();
        if (error) {
            System_Exception_throw(new_System_IOException__error(error, "Directory not removed"));
            return false;
        }
        return true;
    }
    String8 directory0Name = String8_copy(recursive);
    Size rootDirectoryNameL = String8_get_Length(rootDirectoryName);
    Bool reture = true;
    while (!String8_isNullOrEmpty(directory0Name)) {
        Size directory0NameL = String8_get_Length(directory0Name);
        if (!directory0NameL) break;
        if (directory0Name[directory0NameL - 1] == '/') 
            directory0Name[directory0NameL - 1] = '\0';
        if (String8_equalsSubstring(directory0Name, rootDirectoryName, rootDirectoryNameL)) break;
        System_Syscall_rmdir(directory0Name);
        error = System_Syscall_get_Error();
        if (error) {
            System_Exception_throw(new_System_IOException__error(error, "Directory not removed"));
            // Console_writeLine("Exception: Directory not removed {0:string}", 1, directory0Name);
            reture = false;
            break;
        }
        // Console_writeLine("Exception: Directory removed {0:string}", 1, directory0Name);
        String8_exchange(&directory0Name, Path_getDirectoryName(directory0Name));
    }
    Memory_free(directory0Name);
    return reture;
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

System_Bool  System_Directory_open(System_Directory that, System_String8 dirName) {
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

System_DirectoryList  System_Directory_list(System_String8 directoryName) {
    return System_Directory_list__hidden(directoryName, false);
}

System_DirectoryList  System_Directory_list__hidden(System_String8 directoryName, System_Bool hidden) {
    struct System_Directory directory; Stack_clear(directory);
    if (!System_Directory_open(&directory, directoryName)) return null;
    Char8 buffer[65536]; Stack_clear(buffer);
    // System_Syscall_lseek(directory.dirId, 0, System_Origin_Begin);
    Size size = System_Syscall_getdents64(directory.dirId, buffer, 65536);
    if (!size) return null;
    Size linuxC = 0, systemC = 0;
    System_DirectoryList entries = Memory_allocClass(typeof(System_DirectoryList));
    struct MemoryStream stream; Stack_clear(stream);
    MemoryStream_write__char(&stream, '\0');
    entries->name = (System_Var)1;
    MemoryStream_write__string(&stream, directoryName);
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
        size = System_Syscall_getdents64(directory.dirId, buffer, 65536);
    }
    System_Directory_close(&directory);
    entries->scratch.value = MemoryStream_final__size(&stream, &entries->scratch.length);
    entries->name = (System_Var)entries->name + (System_Size)entries->scratch.value;
    for (Size s = 0; s < systemC; ++s) {
        System_DirectoryEntry system_directory = &array_item(entries->value, s);
        system_directory->name = (System_Var)system_directory->name + (System_Size)entries->scratch.value;
    }
    System_Memory_sort(entries->value, systemC, sizeof(struct System_DirectoryEntry), (function_System_Memory_comparison)&System_DirectoryEntry_alphacompare);
    return entries;
}

System_DirectoryList  System_Directory_list__recursive(System_String8 directoryName, System_Bool recursive) {
    return System_Directory_list__recursive_hidden(directoryName, recursive, false);
}

System_DirectoryList  System_Directory_list__recursive_hidden(System_String8 directoryName, System_Bool recursive, System_Bool hidden) {

    System_DirectoryList directories[2048]; Stack_clear(directories); Size directoriesC = 1;
    System_Char8 subdirectoryName[4096]; Stack_clear(subdirectoryName); Size subdirectoryNameL = 0;
    directories[0] = System_Directory_list__hidden(directoryName, hidden);

    if (!recursive) return directories[0];

    for (Size position = 0; position < directoriesC; ++position) {
        DirectoryList list = directories[position];
        for (Size position1 = 0; position1 < list->length; ++position1) {
            DirectoryEntry entry = &array_item(list->value, position1);
            if (entry->type == System_Directory_Type_Directory) {
                if (String8_equals(entry->name, ".")) continue;
                if (String8_equals(entry->name, "..")) continue;
                subdirectoryNameL = String8_copyTo(list->name, subdirectoryName);
                subdirectoryName[subdirectoryNameL++] = '/';
                subdirectoryNameL += String8_copyTo(entry->name, subdirectoryName + subdirectoryNameL);
                subdirectoryName[subdirectoryNameL++] = '\0';
                if (directoriesC < 2048)
                    directories[directoriesC++] = System_Directory_list__hidden(subdirectoryName, hidden);
                // else todo: throw?
            }   
        }
    }

    // Now move them all together
    Size new_size = directories[0]->length;
    for (Size position = 1; position < directoriesC; ++position) {
        new_size += directories[position]->length - 2;
    }
    struct MemoryStream stream; Stack_clear(stream);
    MemoryStream_write__char(&stream, '\0');
    for (Size position1 = 0; position1 < directories[0]->length; ++position1) {
        DirectoryEntry entry = &array_item(directories[0]->value, position1);
        String8 entry_name = entry->name;
        entry->name = (System_Var)stream.position;
        MemoryStream_write__string(&stream, entry_name);
        MemoryStream_write__char(&stream, '\0');
    }
    Size directory0_name_length = String8_get_Length(directories[0]->name);
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
                MemoryStream_write__string(&stream, list->name + directory0_name_length + 1);
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
    Memory_free(directories[0]->scratch.value);
    directories[0]->scratch.value = MemoryStream_final(&stream);
    for (Size s = 0; s < directories[0]->length; ++s) {
        System_DirectoryEntry system_directory = &array_item(directories[0]->value, s);
        system_directory->name = (System_Var)system_directory->name + (System_Size)directories[0]->scratch.value;
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

void System_DirectoryList_free(System_DirectoryList that) {
    if (that->value) Memory_free(that->value);
    if (that->scratch.value) Memory_free(that->scratch.value);
}

struct System_Type_FunctionInfo  System_DirectoryListTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_DirectoryList_free },
};

struct System_Type System_DirectoryListType = { 
    .base = { .type = typeof(System_Type) }, .name = "DirectoryList",
    .size = sizeof(struct System_DirectoryList), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryListTypeFunctions), .value = &System_DirectoryListTypeFunctions },
};