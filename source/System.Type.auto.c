/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#include <min/System.h>
#endif

struct System_HashTableItem System_TypeTableItems[] = {
    { .hash = typeof_System_File, .value = &System_FileType },
    { .hash = typeof_System_FileInfo, .value = &System_FileInfoType },
    { .hash = typeof_System_MemoryStream, .value = &System_MemoryStreamType },
    { .hash = typeof_System_ECQLite, .value = &System_ECQLiteType },
    { .hash = typeof_System_Thread, .value = &System_ThreadType },
    { .hash = typeof_System_DirectoryList, .value = &System_DirectoryListType },
    { .hash = typeof_System_DirectoryEntry, .value = &System_DirectoryEntryType },
    { .hash = typeof_System_Directory, .value = &System_DirectoryType },
};

struct System_HashTable System_TypeTable = { .length = sizeof_array(System_TypeTableItems), .items = &System_TypeTableItems };