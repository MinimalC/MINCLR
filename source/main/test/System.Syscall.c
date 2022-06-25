#define using_System
#include <min/System.h>

struct_string8 isRight = " is right\n";
struct_string8 isWrong = " is wrong\n";

__intptr Beispiel(__intptr a, __intptr b, __intptr c, __intptr d, __intptr e, __intptr f, __intptr g) {

    return a + b + c + d + e + f + g;
}

//__main(test40_System_syscall, args) {
int main(int argc, char * argv[]) {

    __intptr  k = Beispiel(2, 4, 8, 16, 32, 64, 128);

    __intptr  l = __Syscall_write(__File_special_STDOUT, &k, sizeof(__intptr));

    if (l == sizeof(__intptr) && k == 254)
        __Syscall_write(__File_special_STDOUT, isRight, __string8_get_Length(isRight));
    else {
        __Syscall_write(__File_special_STDOUT, isWrong, __string8_get_Length(isWrong));
    }

    return __true;
}
