#define using_System
#include <min/System.h>

struct_string8  HALLO = "HaLLo";
struct_string8  HALLOtxt = "./.test.txt";

__main(test43_System_FileInfo, args) {

	/* Test00: Create a FileInfo */
    __FileInfo fileInfo = __FileInfo_create(HALLOtxt);

    __Console_write("File.Name: {0:string} ({1:uint:octal) ", 2, fileInfo->name, fileInfo->mode);
    if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) __Console_write__string8("File.type: Regular ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) __Console_write__string8("File.type: Directory ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) __Console_write__string8("File.type: Link ");
    else __Console_write__string8("File.type: ? ");

    __Console_write("DeviceId: {0:uint:hex} ", 1, fileInfo->deviceId);
    __Console_write("INodeId: {0:uint} ", 1, fileInfo->iNodeId);
    __Console_write("Hardlinks: {0:uint} ", 1, fileInfo->hardlinks);

    __Console_write("UserID: {0:uint} ", 1, fileInfo->userId);
    __Console_writeLine("GroupID: {0:uint} ", 1, fileInfo->groupId);

    __Console_write("isDevice: {0:uint:hex} ", 1, fileInfo->isDevice);

    __Console_write("Size: {0:uint} ", 1, fileInfo->size);
    __Console_write("BulkSize: {0:uint} ", 1, fileInfo->bulkSize);
    __Console_writeLine("Blocks: {0:uint} ", 1, fileInfo->blocks);

	/* Test02: Free the FileInfo */
    __Object_freeClass(&fileInfo);

	/* Test01: Create a FileInfo for a Directory */
    fileInfo = __FileInfo_create(".");

    __Console_write("File.Name: {0:string} ({1:uint:octal) ", 2, fileInfo->name, fileInfo->mode);
    if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) __Console_write__string8("File.Type: Regular ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) __Console_write__string8("File.Type: Directory ");
    else if (__enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) __Console_write__string8("File.Type: Link ");
    else __Console_write__string8("File.Type: unknown? ");

    __Console_write("DeviceId: {0:uint:hex} ", 1, fileInfo->deviceId);
    __Console_write("INodeId: {0:uint} ", 1, fileInfo->iNodeId);
    __Console_write("Hardlinks: {0:uint} ", 1, fileInfo->hardlinks);

    __Console_write("UserID: {0:uint} ", 1, fileInfo->userId);
    __Console_writeLine("GroupID: {0:uint} ", 1, fileInfo->groupId);

    __Console_write("isDevice: {0:uint:hex} ", 1, fileInfo->isDevice);

    __Console_write("Size: {0:uint} ", 1, fileInfo->size);
    __Console_write("BulkSize: {0:uint} ", 1, fileInfo->bulkSize);
    __Console_writeLine("Blocks: {0:uint} ", 1, fileInfo->blocks);

	/* Test02: Free the FileInfo */
    __Object_freeClass(&fileInfo);

	return __true;	/* __false would be FAILED */
}
