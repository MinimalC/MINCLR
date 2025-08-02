#define using_System
#include <min/System.h>

STRING8  HALLOtxt = "./.System.File.test.txt";
STRING8  FILENOTFOUND = ".FileNotFound";

int System_Runtime_main(int argc, char * argv[]) {

	/* Test00: Create a FileInfo */
    FileInfo fileInfo = new_FileInfo(HALLOtxt);

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Regular)) Console_write__string(", File");
    else if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Directory)) Console_write__string(", Directory");
    else if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Link)) Console_write__string(", Link");
    else Console_write__string(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->status.mode, fileInfo->status.userId, fileInfo->status.groupId);
    Console_write("ContainerId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->status.containerId, fileInfo->status.iNodeId, fileInfo->status.hardlinks);
    Console_writeLine(", deviceId: {0:uint:hex}, size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->status.deviceId, fileInfo->status.size, fileInfo->status.bulkSize, fileInfo->status.blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a Directory */
    fileInfo = new_FileInfo(".");

    Console_write("FileInfo.name: {0:string}", 1, fileInfo->name);
    if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Regular)) Console_write__string(", File");
    else if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Directory)) Console_write__string(", Directory");
    else if (enum_hasFlag(fileInfo->status.mode, FileInfo_Type_Link)) Console_write__string(", Link");
    else Console_write__string(" Unknown?");

    Console_writeLine(" ({0:uint32:octal}), UserID: {1:uint32}, GroupID: {2:uint32}", 3, fileInfo->status.mode, fileInfo->status.userId, fileInfo->status.groupId);
    Console_write("ContainerId: {0:uint:hex}, INodeId: {1:uint}, Hardlinks: {2:uint}", 3, fileInfo->status.containerId, fileInfo->status.iNodeId, fileInfo->status.hardlinks);
    Console_writeLine(", deviceId: {0:uint:hex}, size: {1:uint}, BulkSize: {2:uint}, Blocks: {3:uint} ", 4, fileInfo->status.deviceId, fileInfo->status.size, fileInfo->status.bulkSize, fileInfo->status.blocks);

	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	/* Test01: Create a FileInfo for a non-existent file */
    fileInfo = new_FileInfo(FILENOTFOUND);
    if (fileInfo->error == System_ErrorCode_ENOENT)
        Console_writeLine__string("SUCCESS: FILENOTFOUND ENOFILE");
    else
        Console_writeLine("ERROR: FILENOTFOUND: {0:string}", 1, enum_getName(typeof(System_ErrorCode), fileInfo->error));
    
	/* Test02: Free the FileInfo */
    Memory_free(fileInfo);

	return true;	/* false would be FAILED */
}
