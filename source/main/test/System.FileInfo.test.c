#define using_System
#include <min/System.h>

STRING8  HALLOtxt = "./.System.File.test.txt";
STRING8  FILENOTFOUND = "FileNotFound";

int System_Runtime_main(int argc, char * argv[]) {

	/* Test00: Create a FileInfo */
    FileInfo fileInfo = new_FileInfo(HALLOtxt);

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Regular)) Console_write__string(", File");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Directory)) Console_write__string(", Directory");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Link)) Console_write__string(", Link");
    else Console_write__string(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->stat.mode, fileInfo->stat.userId, fileInfo->stat.groupId);
    Console_write("ContainerId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->stat.containerId, fileInfo->stat.iNodeId, fileInfo->stat.hardlinks);
    Console_writeLine(", deviceId: {0:uint:hex}, size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->stat.deviceId, fileInfo->stat.size, fileInfo->stat.bulkSize, fileInfo->stat.blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a Directory */
    fileInfo = new_FileInfo(".");

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Regular)) Console_write__string(", File");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Directory)) Console_write__string(", Directory");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Link)) Console_write__string(", Link");
    else Console_write__string(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->stat.mode, fileInfo->stat.userId, fileInfo->stat.groupId);
    Console_write("ContainerId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->stat.containerId, fileInfo->stat.iNodeId, fileInfo->stat.hardlinks);
    Console_writeLine(", deviceId: {0:uint:hex}, size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->stat.deviceId, fileInfo->stat.size, fileInfo->stat.bulkSize, fileInfo->stat.blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a non-existent file */
    fileInfo = new_FileInfo(FILENOTFOUND);

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Regular)) Console_write__string(", File");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Directory)) Console_write__string(", Directory");
    else if (enum_hasFlag(fileInfo->stat.mode, FileInfo_Type_Link)) Console_write__string(", Link");
    else if (!fileInfo->stat.mode) Console_write__string(", null 404");
    else Console_write__string(", Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->stat.mode, fileInfo->stat.userId, fileInfo->stat.groupId);
    Console_write("ContainerId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->stat.containerId, fileInfo->stat.iNodeId, fileInfo->stat.hardlinks);
    Console_writeLine(", deviceId: {0:uint:hex}, size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->stat.deviceId, fileInfo->stat.size, fileInfo->stat.bulkSize, fileInfo->stat.blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	return true;	/* false would be FAILED */
}
