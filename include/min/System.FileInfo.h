/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#warning "System.h not included"
#include "System.h"
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


#define struct_System_FileInfo  struct class_System_FileInfo
typedef __fixed struct_System_FileInfo {
    struct_System_Object base;

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
    struct_System_Syscall_stat_timestamp lastAccessTime;
    struct_System_Syscall_stat_timestamp lastWriteTime;
    struct_System_Syscall_stat_timestamp changeTime;

}  * System_FileInfo;

#define stack_System_FileInfo()  (struct_System_FileInfo){ .base = stack_System_Object(System_FileInfo), }

__export struct_System_Type  System_FileInfoType;


typedef System_FileInfo __delegate(System_FileInfo_init)(System_FileInfo that);
typedef System_void __delegate(System_FileInfo_free)(System_FileInfo that);

#define System_FileInfo_new  System_FileInfo_new__00

__export System_FileInfo  System_FileInfo_new();
__export System_FileInfo  base_System_FileInfo_init(System_FileInfo that);
/* __export System_void  base_System_FileInfo_free(System_FileInfo that); */
__export System_FileInfo  System_FileInfo_create(System_string8 fileName);

#define System_FileInfo_init(o)  ((function_System_FileInfo_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_FileInfo_free(o)  ((function_System_FileInfo_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_System_FileInfo_new()  (base_System_FileInfo_init(inline_System_Object_allocClass(System_FileInfo)))

#if !defined(have_System_internal)
#undef  System_FileInfo_new
#define System_FileInfo_new  inline_System_FileInfo_new
#endif

#if defined(using_System)
#define struct_FileInfo  struct_System_FileInfo
#define __FileInfo  System_FileInfo
#define __FileInfoType  System_FileInfoType
#define function_FileInfo_init  function_System_FileInfo_init
#define function_FileInfo_free  function_System_FileInfo_free
#define base_FileInfo_init  base_System_FileInfo_init
/* #define base_FileInfo_free  base_System_FileInfo_free */
#define __FileInfo_new  System_FileInfo_new
#define __FileInfo_init  System_FileInfo_init
#define __FileInfo_free  System_FileInfo_free
#define __FileInfo_create  System_FileInfo_create
#endif

#endif
