/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_Crypto_SipHash48)
#include <min/Crypto.SipHash48.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
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

/** struct System_ECQLite  **/

struct System_Type_FunctionInfo  System_ECQLiteTypeFunctions[] = {
    { .function = base_System_Object_init, .value = System_ECQLite_init },
    { .function = base_System_Object_free, .value = System_ECQLite_free },
};

struct System_Type System_ECQLiteType = { .base = { .type = typeof(System_Type) }, 
    .name = "ECQLite", 
    .size = sizeof(struct System_ECQLite), 
    .baseType = typeof(System_Object), 
	.functions  = { .length = sizeof_array(System_ECQLiteTypeFunctions), .value = &System_ECQLiteTypeFunctions },
};

System_ECQLite  new_System_ECQLite() {
    System_ECQLite that = (System_ECQLite)System_Memory_allocClass(typeof(System_ECQLite));
    System_ECQLite_init(that);
    return that;
}

void  System_ECQLite_init(System_ECQLite that) { }

typedef struct System_ECQLite_Database {

    Char8 intro[16];

    Size tableSize;

    Size size;

    /* atomic Int32 lock; */

} align(8) * System_ECQLite_Database;

typedef struct System_ECQLite_DataTable {

    UInt64 hash;

}  * System_ECQLite_DataTable;

typedef struct System_ECQLite_DataRow {

    UInt64 hash;

    UInt16 length;

} * System_ECQLite_DataRow;


void  System_ECQLite_free(System_ECQLite that) {
    if (that->link) { 
        System_ECQLite_Database database = (System_ECQLite_Database)that->link;
        System_Syscall_munmap(that->link, database->size); 
        that->link = null; 
    }
}

#define ROUND(X,ALIGN)  (((X) + (ALIGN - 1)) & ~(ALIGN - 1))

System_ECQLite System_ECQLite_open(System_String8 filename) {

    System_File file = System_File_open(filename, System_File_Mode_readWrite | System_File_Mode_create);
    if (!file) return null;

    struct System_ECQLite_Database database; Stack_clear(database);
    if (!System_File_read(file, (System_String8)&database, sizeof(struct System_ECQLite_Database))) {
        // CREATE DATABASE
        String8_copyTo("ECQLite", database.intro);
        database.size = database.tableSize = 0xFFFFULL + 1;
        System_File_set_Length(file, database.size);
        System_File_write__string_size(file, (System_String8)&database, sizeof(struct System_ECQLite_Database));
        struct System_ECQLite_DataTable table; Stack_clear(table);
        struct System_ECQLite_DataRow row; Stack_clear(row);
        row.length = sizeof(struct System_ECQLite_DataRow);
        row.length += 1 + String8_get_Length("Table") + 1;
        row.length += 1 + String8_get_Length("....") + 1;
        row.length += 1 + String8_get_Length("1000") + 1;
        row.length += 1 + String8_get_Length("Name Types Indices Columns") + 1;
        row.length = ROUND(row.length, 8) + 8;
        table.hash = row.hash = 0xD448264D19F3348A; // "Table"
        System_File_write__string_size(file, (System_String8)&table, sizeof(struct System_ECQLite_DataTable));
        System_File_write__string_size(file, (System_String8)&row, sizeof(struct System_ECQLite_DataRow));
        System_File_write(file, ".{0:string}", 1, "Table");
        System_File_write__char(file, '\0');
        System_File_write(file, ".{0:string}", 1, "....");
        System_File_write__char(file, '\0');
        System_File_write(file, ".{0:string}", 1, "1000");
        System_File_write__char(file, '\0');
        System_File_write(file, ".{0:string}", 1, "Name Types Indices Columns");
        System_File_write__char(file, '\0');
        System_File_seek(file, -1, Origin_End);
        System_File_write__char(file, '\n');
    }
    else if (!String8_equals(database.intro, "ECQLite")) {
        System_Exception_throw(new_System_Exception("IOException: No ECQLite database."));
        System_File_close(file);
        Memory_free(file);
        return null;
    }

    System_ECQLite that = new_System_ECQLite();
    that->fileName = System_Memory_addReference(filename);
    // TODO check System_File_get_Length and database.size
    that->link = System_Syscall_mmap__file(database.size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Shared, file->fileId, /* offset */ 0 );
    System_File_close(file);
    Memory_free(file);
    return that;
}

System_Bool  System_ECQLite_create(System_ECQLite that, System_String8 tableName, ...) {
    Arguments args;
    Arguments_start(args, tableName);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_ECQLite_create__arguments(that, tableName, argc, argv);
}

System_Bool  System_ECQLite_create__arguments(System_ECQLite that, System_String8 tableName, Size argc, Var argv[]) {

    System_ECQLite_Database database = (System_ECQLite_Database)that->link;

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLineEmpty();
    Console_debugLine("Database_create: sizeof(struct System_ECQLite_Database) {0:uint}, size {1:uint}", 2, sizeof(struct System_ECQLite_Database), database->size);
    #endif

    System_String8 table_position = ((System_String8)that->link) + sizeof(struct System_ECQLite_Database), row_position = null, column = null;

    System_ECQLite_DataTable table = (System_ECQLite_DataTable)table_position;

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("ECQLite Table: position {0:uint}", 1, table_position - (System_String8)that->link);
    #endif

    if ( table->hash != 0xD448264D19F3348A ) {
        System_Exception_throw(new_System_IOException("No ECQLite Table"));
        return false;
    }

    UInt64 table_hash = System_String8_getSipHash(tableName);
    String8 table_types = null, table_indices = null, table_columns = null;
    /* Get Table Data */
    while (table_position < ((System_String8)that->link) + database->size) {
        table = (System_ECQLite_DataTable)table_position;
        if (table->hash != 0xD448264D19F3348A) goto next_table0;

        row_position = table_position + sizeof(struct System_ECQLite_DataTable);
        while (row_position < table_position + database->tableSize) {
            System_ECQLite_DataRow row = (System_ECQLite_DataRow)row_position;
            if (!row->length) break;
            if (row->hash == table_hash) {
                column = row_position + sizeof(struct System_ECQLite_DataRow);
                ++column; column += String8_get_Length(column) + 1;
                ++column; table_types = column; column += String8_get_Length(column) + 1;
                ++column; table_indices = column; column += String8_get_Length(column) + 1;
                ++column; table_columns = column;
                break;
            }
            row_position += row->length;
        }
        if (table_types) break;

next_table0:
        if (table_position == ((System_String8)that->link) + sizeof(struct System_ECQLite_Database)) table_position = (System_String8)that->link;
        table_position += database->tableSize;
    }
    if (!table_types) {
        System_Exception_throw(new_System_IOException(System_String8_format("No Table {0:string}", 1, tableName)));
        return false;
    }
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Found Table {0:string} {1:string} {2:string} {3:string}", 4, tableName, table_types, table_indices, table_columns);
    #endif
    Size table_types_length = String8_get_Length(table_types);

    // Calculate Size and Hash of Data
    struct System_ECQLite_DataRow neu; Stack_clear(neu);
    neu.length = sizeof(struct System_ECQLite_DataRow);
    struct Crypto_SipHash48 sipHash48; Stack_clear(sipHash48); Crypto_SipHash48_init(&sipHash48);
    for (Size c = 0; c < argc && c < table_types_length; ++c)
        if (table_types[c] == System_TypeCode_String)
            if (argv[c]) {
                Size length = String8_get_Length(argv[c]);
                neu.length += 1 + length + 1; 
                if (table_indices[c] == '1')
                    Crypto_SipHash48_update(&sipHash48, argv[c], length);
            }
    neu.length = ROUND(neu.length, 8) + 8;
    neu.hash = Crypto_SipHash48_final(&sipHash48);

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: row length {1:uint32}, hash 0x{2:uint64:hex}", 3, tableName, neu.length, neu.hash);
    #endif

    table_position = ((System_String8)that->link) + sizeof(struct System_ECQLite_Database);

    while (table_position < ((System_String8)that->link) + database->size) {
        table = (System_ECQLite_DataTable)table_position;
        if (table->hash != table_hash) {
            goto next_table1;
        }
        row_position = table_position + sizeof(struct System_ECQLite_DataTable);
        while (row_position < table_position + database->tableSize) {
            System_ECQLite_DataRow row = (System_ECQLite_DataRow)row_position;
            if (row->length) {
                if (row->hash == neu.hash) {
                    if (neu.length == row->length) {
                        /* Update */
                        Memory_clear(row, row->length);
                        Memory_copyTo(&neu, sizeof(struct System_ECQLite_DataRow), row_position);
                        column = row_position + sizeof(struct System_ECQLite_DataRow);
                        for (Size c = 0; c < table_types_length; ++c) {
                            if (table_types[c] == System_TypeCode_String) {
                                Size length = String8_get_Length(argv[c]);
                                // Console_debugLine("Table {0:string}: write {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
                                *column++ = '.';
                                if (c < argc && argv[c] && length) { String8_copyTo(argv[c], column); column += length; }
                                *column++ = 0;
                                #if DEBUG == DEBUG_System_ECQLite
                                Console_debugLine("Table {0:string}: wrote {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
                                #endif
                            }
                        }
                        #if DEBUG == DEBUG_System_ECQLite
                        Console_debugLine("Table {0:string}: row updated, length {1:uint32}, hash 0x{2:uint64:hex}", 3, tableName, neu.length, neu.hash);
                        #endif
                        // Stack_clear(neu);
                        // System_Syscall_msync__flags(that->link, database->size, System_Syscall_MSync_Sync & System_Syscall_MSync_Invalidate);
                        return true;
                    }

                    // Delete this one, Insert a new one
                    Size length = row->length - sizeof(struct System_ECQLite_DataRow);
                    Memory_clear(row + sizeof(struct System_ECQLite_DataRow), length);
                    row->hash = 0;
                    #if DEBUG == DEBUG_System_ECQLite
                    Console_debugLine("Table {0:string}: row deleted, length {1:uint32}, hash 0x{2:uint64:hex}", 3, tableName, neu.length, neu.hash);
                    #endif
                    goto continue_insert;
                }
                row_position += row->length;
                continue;
            }
            break;
        }

next_table1:
        if (table_position == ((System_String8)that->link) + sizeof(struct System_ECQLite_Database)) table_position = (System_String8)that->link;
        table_position += database->tableSize;
    }

continue_insert:

    table_position = ((System_String8)that->link) + sizeof(struct System_ECQLite_Database);

    while (table_position < ((System_String8)that->link) + database->size) {
        table = (System_ECQLite_DataTable)table_position;
        if (table->hash != table_hash) goto next_table2;

        SSize free_space = database->tableSize - 1 - sizeof(struct System_ECQLite_DataTable);
        row_position = table_position + sizeof(struct System_ECQLite_DataTable);
        while (row_position < table_position + database->tableSize) {
            System_ECQLite_DataRow row = (System_ECQLite_DataRow)row_position;
            if (row->length) {
                free_space -= row->length;
                row_position += row->length;
                continue;
            }
            break;
        }
        if (neu.length > free_space) goto next_table2;
        #if DEBUG == DEBUG_System_ECQLite
        else Console_debugLine("Table {0:string}: Free Space {1:int64}: row position {2:int64}", 3, tableName, free_space, row_position - (System_String8)that->link);
        #endif

        /* Insert */
        Memory_copyTo(&neu, sizeof(struct System_ECQLite_DataRow), row_position);
        column = row_position + sizeof(struct System_ECQLite_DataRow);
        for (Size c = 0; c < table_types_length; ++c) {
            if (table_types[c] == System_TypeCode_String) {
                Size length = String8_get_Length(argv[c]);
                // Console_debugLine("Table {0:string}: write {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
                *column++ = '.';
                if (c < argc && argv[c] && length) { String8_copyTo(argv[c], column); column += length; }
                *column++ = 0;
                #if DEBUG == DEBUG_System_ECQLite
                Console_debugLine("Table {0:string}: wrote {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
                #endif
            }
        }
        #if DEBUG == DEBUG_System_ECQLite
        Console_debugLine("Table {0:string}: row inserted, length {1:uint32}, hash 0x{2:uint64:hex}", 3, tableName, neu.length, neu.hash);
        #endif
        // Stack_clear(neu);
        // System_Syscall_msync__flags(that->link, database->size, System_Syscall_MSync_Sync & System_Syscall_MSync_Invalidate);
        return true;

next_table2:
        if (table_position == ((System_String8)that->link) + sizeof(struct System_ECQLite_Database)) table_position = (System_String8)that->link;
        table_position += database->tableSize;
    }

    // Create New Table
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: create new table", 1, tableName);
    #endif

    System_Size old_size = database->size;
    System_Size table_size = database->tableSize;
    System_Size new_size = database->size + table_size;
    System_File database_file = System_File_open(that->fileName, System_File_Mode_readWrite);
    System_File_set_Length(database_file, new_size);
    System_File_set_Position(database_file, offsetof(struct System_ECQLite_Database, size));
    System_File_write__string_size(database_file, (System_String8)&new_size, sizeof(System_Size));
    if (new_size > old_size) {
        System_Var old_link = that->link;
        System_Var new_link = System_Syscall_mmap__full(old_link, database->size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Shared, database_file->fileId, /* offset */ 0 );
        if (!new_link) return false;
        that->link = new_link;
        if (new_link != old_link){
            System_Syscall_munmap(old_link, old_size);
#if DEBUG == DEBUG_System_ECQLite
System_Console_debugLine__string("DANGER: Database link moved.");
#endif
            database = (System_ECQLite_Database)that->link;
        }
    }
    System_File_close(database_file);
    Memory_free(database_file);

    table_position = ((System_String8)that->link) + new_size - table_size;
    Memory_clear(table_position, table_size);
    table_position[table_size - 1] = '\n';

    table = (System_ECQLite_DataTable)table_position;
    table->hash = table_hash;
    
    row_position = table_position + sizeof(struct System_ECQLite_DataTable);
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: create new table, insert row position {1:uint}, table_position {2:uint}, table_size {3:uint}, new_size {4:uint}", 5, 
        tableName, row_position - (System_String8)that->link, table_position - (System_String8)that->link, table_size, new_size);
    #endif

    /* Insert */
    Memory_copyTo(&neu, sizeof(struct System_ECQLite_DataRow), row_position);
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: ECQLite_Row, length {1:uint}, hash {2:uint:hex}, position {3:uint}", 4, tableName, sizeof(struct System_ECQLite_DataRow), neu.hash, row_position - (System_String8)that->link);
    #endif
    column = row_position + sizeof(struct System_ECQLite_DataRow);
    for (Size c = 0; c < table_types_length; ++c) {
        if (table_types[c] == System_TypeCode_String) {
            Size length = String8_get_Length(argv[c]);
            // Console_debugLine("Table {0:string}: length {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
            *column++ = '.';
            if (c < argc && argv[c] && length) { String8_copyTo(argv[c], column); column += length; }
            *column++ = 0;
            #if DEBUG == DEBUG_System_ECQLite
            Console_debugLine("Table {0:string}: length {1:uint} \"{2:string}\", position {3:uint}", 4, tableName, 1 + length + 1, argv[c], column - (String8)that->link);
            #endif
        }
    }
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: table created, row inserted, length {1:uint32}, hash 0x{2:uint64:hex}", 3, tableName, neu.length, neu.hash);
    #endif
    // Stack_clear(neu);
    // System_Syscall_msync__flags(that->link, database->size, System_Syscall_MSync_Sync & System_Syscall_MSync_Invalidate);
    return true;
}

System_Bool  System_ECQLite_select(System_ECQLite that, System_String8 tableName, System_ECQLite_Table reture, ...) {
    Arguments args;
    Arguments_start(args, reture);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_ECQLite_select__arguments(that, tableName, reture, argc, argv);
}

System_Bool  System_ECQLite_select__arguments(System_ECQLite that, System_String8 tableName, System_ECQLite_Table reture, Size argc, Var argv[]) {

    Memory_clear(reture, sizeof(struct System_ECQLite_Table));

    System_ECQLite_Database database = (System_ECQLite_Database)that->link;

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLineEmpty();
    Console_debugLine("Database_query: sizeof(struct System_ECQLite_Database) {0:uint}, size {1:uint}", 2, sizeof(struct System_ECQLite_Database), database->size);
    #endif

    System_String8 table_position = ((System_String8)that->link) + sizeof(struct System_ECQLite_Database), row_position = null, column = null;

    System_ECQLite_DataTable table = (System_ECQLite_DataTable)table_position;

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("ECQLite Table: position {0:uint}", 1, table_position - (System_String8)that->link);
    #endif

    if ( table->hash != 0xD448264D19F3348A ) {
        System_Exception_throw(new_System_IOException("No ECQLite Table"));
        return false;
    }

    UInt64 table_hash = System_String8_getSipHash(tableName);
    String8 table_types = null, table_indices = null, table_columns = null;
    /* Get Table Data */
    while (table_position < ((System_String8)that->link) + database->size) {
        table = (System_ECQLite_DataTable)table_position;
        if (table->hash != 0xD448264D19F3348A) goto next_table3;

        row_position = table_position + sizeof(struct System_ECQLite_DataTable);
        while (row_position < table_position + database->tableSize) {
            System_ECQLite_DataRow row = (System_ECQLite_DataRow)row_position;
            if (!row->length) break;
            if (row->hash == table_hash) {
                column = row_position + sizeof(struct System_ECQLite_DataRow);
                ++column; column += String8_get_Length(column) + 1;
                ++column; table_types = column; column += String8_get_Length(column) + 1;
                ++column; table_indices = column; column += String8_get_Length(column) + 1;
                ++column; table_columns = column;
                break;
            }
            row_position += row->length;
        }
        if (table_types) break;

next_table3:
        if (table_position == ((System_String8)that->link) + sizeof(struct System_ECQLite_Database)) table_position = (System_String8)that->link;
        table_position += database->tableSize;
    }
    if (!table_types) {
        System_Exception_throw(new_System_IOException(System_String8_format("No Table {0:string}", 1, tableName)));
        return false;
    }
    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Found Table {0:string} {1:string} {2:string} {3:string}", 4, tableName, table_types, table_indices, table_columns);
    #endif
    Size table_types_length = String8_get_Length(table_types);

    // Calculate Hash of arguments
    struct Crypto_SipHash48 sipHash48; Stack_clear(sipHash48); Crypto_SipHash48_init(&sipHash48);
    for (Size c = 0; c < argc && c < table_types_length; ++c)
        if (table_types[c] == System_TypeCode_String)
            if (argv[c]) {
                Size length = String8_get_Length(argv[c]);
                if (table_indices[c] == '1')
                    Crypto_SipHash48_update(&sipHash48, argv[c], length);
            }
    System_UInt64 row_hash = Crypto_SipHash48_final(&sipHash48);

    String8 scratch = reture->scratch;
    *scratch++ = 0;
    String8_copyTo(tableName, scratch);
    reture->tableName = scratch;
    scratch += String8_get_Length(tableName) + 1;
    reture->tableSize = 64;

    for (Size c = 0, table_columns_position = 0; c < table_types_length; ++c) {
        SSize i = System_String8_indexOf(table_columns + table_columns_position, ' ');
        if (i < 0) i = System_String8_get_Length(table_columns + table_columns_position);
        if (!i) break;
        Memory_copyTo(table_columns + table_columns_position, i, scratch);
        reture->columns[c].columnName = scratch;
        table_columns_position += i + 1;
        scratch += i + 1;
    }

    table_position = ((System_String8)that->link) + sizeof(struct System_ECQLite_Database);

    while (table_position < ((System_String8)that->link) + database->size) {
        table = (System_ECQLite_DataTable)table_position;
        if (table->hash != table_hash) goto next_table4;

        row_position = table_position + sizeof(struct System_ECQLite_DataTable);
        while (row_position < table_position + database->tableSize) {
            System_ECQLite_DataRow row = (System_ECQLite_DataRow)row_position;
            if (!row->length) break;

            if (row->hash == row_hash) {

                column = row_position + sizeof(struct System_ECQLite_DataRow);
                for (Size c = 0; c < table_types_length; ++c) {
                    if (*column == System_TypeCode_String) {
                        #if DEBUG == DEBUG_System_ECQLite
                        if (table_types[c] != System_TypeCode_String) Console_debugLine("table_types mismatch {0:string}", 1, column);
                        #endif
                        reture->columns[c].typeCode = System_TypeCode_String;
                        Size length = String8_get_Length(++column);
                        if (length) {
                            String8_copyTo(column, scratch);
                            reture->columns[c].string = scratch;
                        }
                        scratch += length + 1;
                        column += length + 1;
                    }
                }
                goto reture_true;
            }

            row_position += row->length;
        }

next_table4:
        if (table_position == ((System_String8)that->link) + sizeof(struct System_ECQLite_Database)) table_position = (System_String8)that->link;
        table_position += database->tableSize;
    }

    #if DEBUG == DEBUG_System_ECQLite
    Console_debugLine("Table {0:string}: Data not found.", 1, tableName);
    #endif

reture_false:
    #if DEBUG == DEBUG_System_ECQLite
    System_Console_debug__string("Scratch, returning false: ");
    System_Console_debug__string_size(reture->scratch, scratch - reture->scratch);
    System_Console_debugLineEmpty();
    #endif
    return false;

reture_true:
    #if DEBUG == DEBUG_System_ECQLite
    System_Console_debug__string("Scratch, returning true: ");
    System_Console_debug__string_size(reture->scratch, scratch - reture->scratch);
    System_Console_debugLineEmpty();
    #endif
    return true;
}
