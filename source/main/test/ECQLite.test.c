#define using_System
#include <min/System.h>
#include <min/System.ECQLite.h>

int main_ECQLite_test(int argc, char * argv[]) {

    if (argc < 2) { 
        System_Console_writeLine__string("Usage: ECQLite_test Database.ecql");
        return false;
    }

    System_ECQLite database = System_ECQLite_open(argv[1]);
    if (!database) return false;

    System_ECQLite_create(database, "Table", 4, "Person", "....", "1000", "Name Geburtsdatum Email Telefon");

    System_ECQLite_create(database, "Table", 4, "Produkt", "....", "1000", "Name Kategorie Größe Gewicht");

    System_ECQLite_create(database, "Person", 4, "Hans", "12.11.1984", "hans@mail.de", "+491765432109");

    System_ECQLite_create(database, "Produkt", 4, "Redmi6A", "Android", "16x9", "300g");

    struct System_ECQLite_Table table[1]; Stack_clear(table);

    if (System_ECQLite_select(database, "Person", table, 1, "Hans")) {
        Console_write("{0:string}:", 1, "Person");
        for (Size i = 0; i < 64; ++i) {
            if (!table->columns[i].string) continue;
            if (i) Console_write__string(",");
            Console_write(" {0:string} {1:string}", 2, table->columns[i].columnName, table->columns[i].string);
        }
        Console_writeLineEmpty();
    }
    else Console_writeLine("{0:string} not found.", 1, "Person");

    if (System_ECQLite_select(database, "Produkt", table, 1, "Redmi6A")) {
        Console_write("{0:string}:", 1, "Produkt");
        for (Size i = 0; i < 64; ++i) {
            if (!table->columns[i].string) continue;
            if (i) Console_write__string(",");
            Console_write(" {0:string} {1:string}", 2, table->columns[i].columnName, table->columns[i].string);
        }
        Console_writeLineEmpty();
    }
    else Console_writeLine("{0:string} not found.", 1, "Produkt");

    if (System_ECQLite_select(database, "Katalog", table, 1, "wer?")) {
        Console_write("{0:string}:", 1, "Katalog");
        for (Size i = 0; i < 64; ++i) {
            if (!table->columns[i].string) continue;
            if (i) Console_write__string(",");
            Console_write(" {0:string} {1:string}", 2, table->columns[i].columnName, table->columns[i].string);
        }
        Console_writeLineEmpty();
    }
    else Console_writeLine("{0:string} not found.", 1, "Katalog");

    Memory_free(database);
    return true;
}
