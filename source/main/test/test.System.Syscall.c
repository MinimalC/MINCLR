#define using_System
#include <min/System.h>

struct_string8 isRight = " is right\n";
struct_string8 isWrong = " is wrong\n";

intptr Beispiel(intptr a, intptr b, intptr c, intptr d, intptr e, intptr f, intptr g) {

    return a + b + c + d + e + f + g;
}

//main(test40_System_syscall, args) {
int main(int argc, char * argv[]) {

    intptr  k = Beispiel(2, 4, 8, 16, 32, 64, 128);

    intptr  l = Syscall_write(File_special_STDOUT, &k, sizeof(intptr));

    if (l == sizeof(intptr) && k == 254)
        Syscall_write(File_special_STDOUT, isRight, string8_get_Length(isRight));
    else {
        Syscall_write(File_special_STDOUT, isWrong, string8_get_Length(isWrong));
    }

    return true;
}
