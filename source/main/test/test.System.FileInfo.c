#define using_System
#include <min/System.h>

STRING8  HALLOtxt = "./.test.txt";
STRING8  FILENOTFOUND = "FileNotFound";

//main(test43_System_FileInfo, args) {
int main(int argc, char * argv[]) {

	/* Test00: Create a FileInfo */
    FileInfo fileInfo = new_FileInfo(HALLOtxt);

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) Console_write__string8(", File");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) Console_write__string8(", Directory");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) Console_write__string8(", Link");
    else Console_write__string8(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->mode, fileInfo->userId, fileInfo->groupId);
    Console_write("DeviceId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->deviceId, fileInfo->iNodeId, fileInfo->hardlinks);
    Console_writeLine(", isDevice: {0:uint:hex}, Size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->isDevice, fileInfo->size, fileInfo->bulkSize, fileInfo->blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a Directory */
    fileInfo = new_FileInfo(".");

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) Console_write__string8(", File");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) Console_write__string8(", Directory");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) Console_write__string8(", Link");
    else Console_write__string8(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->mode, fileInfo->userId, fileInfo->groupId);
    Console_write("DeviceId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->deviceId, fileInfo->iNodeId, fileInfo->hardlinks);
    Console_writeLine(", isDevice: {0:uint:hex}, Size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->isDevice, fileInfo->size, fileInfo->bulkSize, fileInfo->blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a non-existent file */
    fileInfo = new_FileInfo(FILENOTFOUND);

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Regular)) Console_write__string8(", File");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Directory)) Console_write__string8(", Directory");
    else if (enum_hasFlag(fileInfo->mode, System_FileInfo_type_Link)) Console_write__string8(", Link");
    else if (!fileInfo->mode) Console_write__string8(", null 404");
    else Console_write__string8(", Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->mode, fileInfo->userId, fileInfo->groupId);
    Console_write("DeviceId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->deviceId, fileInfo->iNodeId, fileInfo->hardlinks);
    Console_writeLine(", isDevice: {0:uint:hex}, Size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->isDevice, fileInfo->size, fileInfo->bulkSize, fileInfo->blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	return true;	/* false would be FAILED */
}
