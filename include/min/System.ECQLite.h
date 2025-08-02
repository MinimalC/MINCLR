/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_File)
#include "System.File.h"
#endif
#if !defined(have_System_ECQLite)
#define have_System_ECQLite

typedef struct System_ECQLite_Column {

    System_String8 columnName;

    union { 
        System_String8 string;
        System_Size integer;
    };

    System_TypeCode typeCode;

} * System_ECQLite_Column;

typedef struct System_ECQLite_Table {

    System_String8 tableName;

    System_Size tableSize;

    System_Size rows;

    struct System_ECQLite_Column columns[64];

    System_Char8 scratch[System_UInt16_Max];

} * System_ECQLite_Table;

typedef struct System_ECQLite {
    struct System_Object base;

    System_String8 fileName;

    System_Var link;

}  * System_ECQLite;

export struct System_Type  System_ECQLiteType;

export System_ECQLite  new_System_ECQLite();
export void  System_ECQLite_init(System_ECQLite that);
export void  System_ECQLite_free(System_ECQLite that);
export System_ECQLite  System_ECQLite_open(System_String8 filename);
export System_Bool  System_ECQLite_create(System_ECQLite that, System_String8 tableName, ...);
export System_Bool  System_ECQLite_create__arguments(System_ECQLite that, System_String8 tableName, System_Size argc, System_Var argv[]);
export System_Bool  System_ECQLite_select(System_ECQLite that, System_String8 tableName, System_ECQLite_Table reture, ...);
export System_Bool  System_ECQLite_select__arguments(System_ECQLite that, System_String8 tableName, System_ECQLite_Table reture, System_Size argc, System_Var argv[]);

#if defined(using_System)
#define ECQLite  System_ECQLite
#define ECQLiteType  System_ECQLiteType
#endif
#endif
