/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_File)
#include "System.File.h"
#endif
#if !defined(have_System_ECQLite)
#define have_System_ECQLite

export struct System_Type  System_ECQLiteType;

typedef struct System_ECQLite {
    struct System_Object base;

    System_File file;

    System_Var link;

}  * System_ECQLite;

export System_ECQLite  new_System_ECQLite();
export void  base_System_ECQLite_init(System_ECQLite that);
export void  base_System_ECQLite_free(System_ECQLite that);
export System_ECQLite System_ECQLite_open(System_String8 filename);
export void System_ECQLite_createTable(System_ECQLite that, System_String8 tableName, System_String8 columns);
export void  System_ECQLite_insert(System_ECQLite that, System_String8 tableName, ...);
export void System_ECQLite_insert__arguments(System_ECQLite that, System_String8 tableName, Size argc, Var argv[]);

#if defined(using_System)
#define ECQLite  System_ECQLite
#define ECQLiteType  System_ECQLiteType
#endif
#endif
