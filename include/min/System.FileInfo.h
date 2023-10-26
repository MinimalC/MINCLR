/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Syscall)
#include "System.Syscall.h"
#endif
#if !defined(have_System_FileInfo)
#define have_System_FileInfo


typedef System_UInt32  System_FileInfo_Type;

#define System_FileInfo_Type_Regular            0100000
#define System_FileInfo_Type_Directory          0040000
#define System_FileInfo_Type_CharacterDevice    0020000
#define System_FileInfo_Type_BlockDevice        0060000
#define System_FileInfo_Type_Pipe               0010000
#define System_FileInfo_Type_Link               0120000
#define System_FileInfo_Type_Socket             0140000

#if defined(using_System)
#define FileInfo_Type  System_FileInfo_Type

#define FileInfo_Type_Regular  System_FileInfo_Type_Regular
#define FileInfo_Type_Directory  System_FileInfo_Type_Directory
#define FileInfo_Type_CharacterDevice  System_FileInfo_Type_CharacterDevice
#define FileInfo_Type_BlockDevice  System_FileInfo_Type_BlockDevice
#define FileInfo_Type_Pipe  System_FileInfo_Type_Pipe
#define FileInfo_Type_Link  System_FileInfo_Type_Link
#define FileInfo_Type_Socket  System_FileInfo_Type_Socket
#endif

typedef System_fixed struct System_FileInfo {
    struct System_Object base;

    System_String8 name;

    System_ErrorCode error;

    /* struct System_Syscall_stat */
    
    System_UInt64 containerId;
    System_UInt64 iNodeId;
    System_UInt64 hardlinks;
    System_UInt32 mode;
    System_UInt32 userId;
    System_UInt32 groupId;
    System_UInt32 __padding1;

    System_UInt64 deviceId;
    System_Int64 size;
    System_Int64 bulkSize;
    System_Int64 blocks;
    struct System_Syscall_timespec accessTime;
    struct System_Syscall_timespec modifyTime;
    struct System_Syscall_timespec changeTime;

    System_IntPtr __reserved[3];

}  * System_FileInfo;

export struct System_Type  System_FileInfoType;

typedef void delegate(System_FileInfo_init)(System_FileInfo that, System_String8 fileName);

export System_FileInfo  new_System_FileInfo();
export void  base_System_FileInfo_init(System_FileInfo that, System_String8 fileName);

export System_Bool System_FileInfo_isRegular(System_FileInfo that);
export System_Bool System_FileInfo_isDirectory(System_FileInfo that);
export System_Bool System_FileInfo_isLink(System_FileInfo that);

#define System_FileInfo_init(o,...)  ((function_System_FileInfo_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o, __VA_ARGS__)
#define System_FileInfo_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_System)
#define FileInfo  System_FileInfo
#define FileInfoType  System_FileInfoType
#define new_FileInfo  new_System_FileInfo
#define function_FileInfo_init  function_System_FileInfo_init
#define base_FileInfo_init  base_System_FileInfo_init
#define FileInfo_init  System_FileInfo_init
#define FileInfo_free  System_FileInfo_free
#endif
#endif
