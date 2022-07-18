/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Syscall)
#include "System.Syscall.h"
#endif
#if !defined(have_System_FileInfo)
#define have_System_FileInfo


typedef System_uint32  System_FileInfo_type;

#define System_FileInfo_type_Regular            0100000
#define System_FileInfo_type_Directory          0040000
#define System_FileInfo_type_CharacterDevice    0020000
#define System_FileInfo_type_BlockDevice        0060000
#define System_FileInfo_type_Pipe               0010000
#define System_FileInfo_type_Link               0120000
#define System_FileInfo_type_Socket             0140000



typedef fixed struct System_FileInfo {
    struct System_Object base;

    System_string8 name;

    System_uint64 deviceId;
    System_uint64 iNodeId;
    System_uint64 hardlinks;

    System_uint32 mode;
    System_uint32 userId;
    System_uint32 groupId;

    System_uint64 isDevice;
    System_int64 size;
    System_int64 bulkSize;
    System_int64 blocks;
    struct System_Syscall_stat_timestamp lastAccessTime;
    struct System_Syscall_stat_timestamp lastWriteTime;
    struct System_Syscall_stat_timestamp changeTime;

}  * System_FileInfo;

export struct System_Type  System_FileInfoType;

#define stack_System_FileInfo()  (struct System_FileInfo){ .base = stack_System_Object(System_FileInfo), }

typedef System_FileInfo delegate(System_FileInfo_init)(System_FileInfo that, System_string8 fileName);
typedef void delegate(System_FileInfo_free)(System_FileInfo that);

export System_FileInfo  base_System_FileInfo_init(System_FileInfo that, System_string8 fileName);
/* export void  base_System_FileInfo_free(System_FileInfo that); */

#define System_FileInfo_init(o)  ((function_System_FileInfo_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_FileInfo_free(o)  ((function_System_FileInfo_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define new_System_FileInfo(fileName)  (base_System_FileInfo_init((System_FileInfo)System_Memory_allocClass(typeof(System_FileInfo)), fileName))

#if defined(using_System)

#define FileInfo  System_FileInfo
#define FileInfoType  System_FileInfoType
#define function_FileInfo_init  function_System_FileInfo_init
#define function_FileInfo_free  function_System_FileInfo_free
#define base_FileInfo_init  base_System_FileInfo_init
/* #define base_FileInfo_free  base_System_FileInfo_free */
#define new_FileInfo  new_System_FileInfo
#define FileInfo_init  System_FileInfo_init
#define FileInfo_free  System_FileInfo_free
#define FileInfo_create  System_FileInfo_create
#endif

#endif
