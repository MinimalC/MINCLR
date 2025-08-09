#define using_System
#include <min/System.h>
#include <min/System.ECQLite.h>

int ECQLite1_main(int argc, char * argv[]) {

    if (argc < 6) { 
        System_Console_writeLine__string("Usage:");
        System_Console_writeLine__string("  ECQLite1 database.ecql");
        System_Console_writeLine__string("  ... CREATE Table SET Person .... 1000 \"Name Birthdate Email Telefon\"");
        System_Console_writeLine__string("  ... CREATE Person SET Hans 12.11.1984 hans@mail.de +491765432109");
        System_Console_writeLine__string("  ... SELECT Person WHERE Hans");
        return false;
    }

    System_ECQLite database = System_ECQLite_open(argv[1]);
    if (!database) return false;

    String8 table_name = null;
    if (String8_equals("CREATE", argv[2]) || String8_equals("create", argv[2])) {
        table_name = argv[3];
        // if (!String8_equals("SET", argv[4]) || !String8_equals("set", argv[4])) ;

        if (System_ECQLite_create__arguments(database, table_name, argc - 5, (System_Var *)(argv + 5))) {

            Console_write("{0:string}", 1, table_name);
            for (Size c = 0; c < (argc - 5); ++c) Console_write(" {0:string}", 1, argv[5 + c]);
            Console_writeLineEmpty();
            goto return_true;
        }
        else Console_write("{0:string} not found.", 1, table_name);
        goto return_false;
    }

    struct System_ECQLite_Table table[1]; Stack_clear(table);
    
    if (String8_equals("SELECT", argv[2]) || String8_equals("select", argv[2])) {
        table_name = argv[3];
        // if (!String8_equals("WHERE", argv[4]) || !String8_equals("where", argv[4])) ;

        if (System_ECQLite_select__arguments(database, table_name, table, argc - 5, (System_Var *)(argv + 5))) {

            if (table->columns[0].string) {
                Console_write("{0:string}:", 1, table_name);
                for (Size i = 0; i < 64; ++i) {
                    if (!table->columns[i].string) continue;
                    if (i) Console_write__string(",");
                    Console_write(" {0:string} {1:string}", 2, table->columns[i].columnName, table->columns[i].string);
                }
                Console_writeLineEmpty();
                goto return_true;
            }
            else Console_writeLine("{0:string} not found.", 1, table_name);
        }
        else Console_writeLine("{0:string} not found.", 1, table_name);
        goto return_false;
    }

    Console_writeLine("Unknown command {0:string}.", 1, argv[2]);

return_false:
    Memory_free(database);
    return false;
return_true:
    Memory_free(database);
    return true;
}
