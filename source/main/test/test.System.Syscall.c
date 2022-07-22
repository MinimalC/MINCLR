#define using_System
#include <min/System.h>

STRING8 isRight = " is right\n";
STRING8 isWrong = " is wrong\n";

IntPtr Beispiel(IntPtr a, IntPtr b, IntPtr c, IntPtr d, IntPtr e, IntPtr f, IntPtr g) {

    return a + b + c + d + e + f + g;
}

//main(test40_System_syscall, args) {
int main(int argc, char * argv[]) {

    IntPtr  k = Beispiel(2, 4, 8, 16, 32, 64, 128);

    IntPtr  l = Syscall_write(File_special_STDOUT, &k, sizeof(IntPtr));

    if (l == sizeof(IntPtr) && k == 254)
        Syscall_write(File_special_STDOUT, isRight, String8_get_Length(isRight));
    else {
        Syscall_write(File_special_STDOUT, isWrong, String8_get_Length(isWrong));
    }

    return true;
}
