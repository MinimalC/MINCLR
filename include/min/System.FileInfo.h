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

enum {
    System_FileInfo_Type_Regular          = 0100000,
    System_FileInfo_Type_Directory        = 0040000,
    System_FileInfo_Type_CharacterDevice  = 0020000,
    System_FileInfo_Type_BlockDevice      = 0060000,
    System_FileInfo_Type_Pipe             = 0010000,
    System_FileInfo_Type_Link             = 0120000,
    System_FileInfo_Type_Socket           = 0140000,
};

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

    struct System_Syscall_status status;

}  * System_FileInfo;

export struct System_Type  System_FileInfoType;

export System_FileInfo  new_System_FileInfo();
export void  System_FileInfo_init(System_FileInfo that, System_String8 fileName);

export System_Bool System_FileInfo_isRegular(System_FileInfo that);
export System_Bool System_FileInfo_isDirectory(System_FileInfo that);
export System_Bool System_FileInfo_isLink(System_FileInfo that);

#if defined(using_System)
#define FileInfo  System_FileInfo
#define FileInfoType  System_FileInfoType
#define new_FileInfo  new_System_FileInfo
#define function_FileInfo_init  function_System_FileInfo_init
#define base_FileInfo_init  System_FileInfo_init
#define FileInfo_init  System_FileInfo_init
#define FileInfo_free  System_FileInfo_free
#endif
#endif
