/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_ECQLite)
#include <min/System.ECQLite.h>
#endif

/** class System_ECQLite  **/

struct System_Type_FunctionInfo  System_ECQLiteTypeFunctions[] = {
    { .function = base_System_Object_init, .value = base_System_ECQLite_init },
    { .function = base_System_Object_free, .value = base_System_ECQLite_free },
};

struct System_Type System_ECQLiteType = { .base = { .type = typeof(System_Type) }, 
    .name = "ECQLite", 
    .size = sizeof(struct System_ECQLite), 
    .baseType = typeof(System_Object), 
	.functions  = { .length = sizeof_array(System_ECQLiteTypeFunctions), .value = &System_ECQLiteTypeFunctions },
};

System_ECQLite  new_System_ECQLite() {
    System_ECQLite that = (System_ECQLite)System_Memory_allocClass(typeof(System_ECQLite));
    base_System_ECQLite_init(that);
    return that;
}

void  base_System_ECQLite_init(System_ECQLite that) { }

typedef struct System_ECQLite_Database {

    Char8 intro[16];

    Size size;

    atomic Int32 lock;

}  * System_ECQLite_Database;

typedef struct System_ECQLite_Table {

    Size length;

    UInt64 hash;

}  * System_ECQLite_Table;

typedef struct System_ECQLite_Row {

    Size length;

    UInt64 next;

    UInt64 hash;

} * System_ECQLite_Row;

typedef struct System_ECQLite_Column {

    System_TypeCode typeCode;

    System_Char8 data[7];

} * System_ECQLite_Column;

typedef System_Char8 System_Operator;
enum {
    System_Operator_Not,
    System_Operator_Value,
    System_Operator_Expression,
    System_Operator_AND,
    System_Operator_OR,
    System_Operator_NAND,
    System_Operator_NOR,
    System_Operator_XOR,
    System_Operator_Add,
    System_Operator_Subtract,
    System_Operator_Multiply,
    System_Operator_Divide,
    System_Operator_Equals,
    System_Operator_NotEquals,
    System_Operator_Like,
    System_Operator_Unlike,
    System_Operator_Regex,
    System_Operator_NotRegex,
};

typedef struct System_ECQLite_Expression  * System_ECQLite_Expression;

struct System_ECQLite_Expression {

    System_Operator operator;

    union { 
        System_String8 string0;
        System_Size integer0;
        System_ECQLite_Expression expression0;
    };

    union { 
        System_String8 string1;
        System_Size integer1;
        System_ECQLite_Expression expression1;
    };
};

void  base_System_ECQLite_free(System_ECQLite that) {
    if (that->link) { 
        System_ECQLite_Database database = (System_ECQLite_Database)that->link;
        System_Syscall_munmap(that->link, database->size); 
        that->link = null; 
    }
    if (that->file) Memory_free(that->file);
}

System_ECQLite System_ECQLite_open(System_String8 filename) {

    System_File file = System_File_open(filename, System_File_Mode_readWrite | System_File_Mode_create);
    if (!file) return null;

    struct System_ECQLite_Database database; Stack_clear(database);
    if (!base_System_File_read(file, (System_String8)&database, sizeof(struct System_ECQLite_Database))) {
        // CREATE DATABASE
        String8_copyTo("ECQLite", database.intro);
        database.size = 0xFFFFULL;
        base_System_File_write__string_size(file, (System_String8)&database, sizeof(struct System_ECQLite_Database));
        // CREATE TABLE ECQLite_Tables ( Name, Columns, Index )
        // INSERT INTO ECQLite_Tables ("ECQLite_Tables", "Name, Columns, Index", "Name")
        struct System_ECQLite_Table table; Stack_clear(table);
        table.length = 0xFFFFULL - sizeof(struct System_ECQLite_Database);
        struct System_ECQLite_Row row; Stack_clear(row);
        row.length = sizeof(struct System_ECQLite_Row);
        row.length += 1 + String8_get_Length("ECQLite_Tables") + 1;
        row.length += 1 + String8_get_Length("Name, Columns, Index") + 1;
        table.hash = row.hash = 0xCC08447FE3238121ULL; // "ECQLite_Tables"
        base_System_File_write__string_size(file, (System_String8)&table, sizeof(struct System_ECQLite_Table));
        base_System_File_write__string_size(file, (System_String8)&row, sizeof(struct System_ECQLite_Row));
        base_System_File_write(file, "{0:uint8}{1:string}", 2, System_TypeCode_String, "ECQLite_Tables");
        base_System_File_write__char(file, '\0');
        base_System_File_write(file, "{0:uint8}{1:string}", 2, System_TypeCode_String, "Name, Columns, Index");
        base_System_File_write__char(file, '\0');
        base_System_File_write(file, "{0:uint8}{1:string}", 2, System_TypeCode_String, "Name");
        base_System_File_write__char(file, '\0');
    }
    else if (!String8_equals(database.intro, "ECQLite")) {
        System_Exception_throw(new_System_Exception("IOException: No ECQLite database."));
        base_System_File_close(file);
        Memory_free(file);
        return null;
    }

    System_ECQLite that = new_System_ECQLite();
    that->file = file;
    that->link = System_Syscall_mmap__file(database.size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Shared, 
        that->file->fileId, /* offset */ 0 );
    return that;
}

void System_ECQLite_createTable(System_ECQLite that, System_String8 tableName, System_String8 columns) {

    /* Now there should be a pre-defined first-person table ECQLite_Tables */

    System_ECQLite_Table table = (System_ECQLite_Table)(that->link + sizeof(struct System_ECQLite_Database));

    if ( table->hash != 0xCC08447FE3238121ULL ) { // SipHash48("ECQLite_Tables")
        // this is wrong
        System_Exception_throw(new_System_IOException("No ECQLite_Tables"));
        return;
    }


}

void  System_ECQLite_insert(System_ECQLite that, System_String8 tableName, ...) {
    Debug_assert(tableName);
    arguments args;
    arguments_start(args, tableName);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_ECQLite_insert__arguments(that, tableName, argc, argv);
}

void System_ECQLite_insert__arguments(System_ECQLite that, System_String8 tableName, Size argc, Var argv[]) {

}

void System_ECQLite_select(System_ECQLite that) {

}
void System_ECQLite_update(System_ECQLite that) {

}
void System_ECQLite_delete(System_ECQLite that) {

}