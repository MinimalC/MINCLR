#define using_System
#include <min/System.h>

struct_string8  HALLO = "HaLLo";
struct_string8  HALLOtxt = "./.test.txt";

__main(test43_System_FileInfo, args) {

	/* Test00: Create a FileInfo */
    __FileInfo fileInfo = __FileInfo_create(HALLOtxt);

    __Console_print("File.Name: %s (%o) ", fileInfo->name, fileInfo->mode);
    if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) __Console_print("File.type: Regular ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) __Console_print("File.type: Directory ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) __Console_print("File.type: Link ");
    else __Console_print("File.type: ? ");

    __Console_print("Size: %lu ", fileInfo->size);
    __Console_print("BulkSize: %lu ", fileInfo->bulkSize);
    __Console_printLine("Blocks: %lu ", fileInfo->blocks);
    
    __Console_print("DeviceId: %lX ", fileInfo->deviceId);
    __Console_print("isDevice: %lX ", fileInfo->isDevice);
    __Console_print("INodeId: %lu ", fileInfo->iNodeId);
    __Console_print("Hardlinks: %lu ", fileInfo->hardlinks);
    __Console_print("UserID: %u ", fileInfo->userId);
    __Console_printLine("GroupID: %u ", fileInfo->groupId);

	/* Test02: Free the FileInfo */
    __Object_freeClass(&fileInfo);

	/* Test01: Create a FileInfo for a Directory */
    fileInfo = __FileInfo_create(".");

    __Console_print("File.Name: %s (%o) ", fileInfo->name, fileInfo->mode);
    if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) __Console_print("File.Type: Regular ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) __Console_print("File.Type: Directory ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) __Console_print("File.Type: Link ");
    else __Console_print("File.Type: unknown? ");
    
    __Console_print("Size: %lu ", fileInfo->size);
    __Console_print("BulkSize: %lu ", fileInfo->bulkSize);
    __Console_printLine("Blocks: %lu ", fileInfo->blocks);

    __Console_print("DeviceId: %lX ", fileInfo->deviceId);
    __Console_print("isDevice: %lX ", fileInfo->isDevice);
    __Console_print("INodeId: %lu ", fileInfo->iNodeId);
    __Console_print("Hardlinks: %lu ", fileInfo->hardlinks);
    __Console_print("UserID: %u ", fileInfo->userId);
    __Console_printLine("GroupID: %u ", fileInfo->groupId);

	/* Test02: Free the FileInfo */
    __Object_freeClass(&fileInfo);

	return __true;	/* __false would be FAILED */
}
