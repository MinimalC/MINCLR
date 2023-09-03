#define using_System
#include <min/System.h>

STRING8 isRight = "Syscall is right\n";
STRING8 isWrong = "Syscall is wrong\n";

IntPtr Beispiel(IntPtr a, IntPtr b, IntPtr c, IntPtr d, IntPtr e, IntPtr f, IntPtr g) {

    return a + b + c + d + e + f + g;
}

int System_Runtime_main(int argc, char * argv[]) {

    IntPtr  k = Beispiel(2, 4, 8, 16, 32, 64, 128);

    if (k == 254)
        Syscall_write(Syscall_StandardFile_STDOUT, isRight, String8_get_Length(isRight));
    else {
        Syscall_write(Syscall_StandardFile_STDOUT, isWrong, String8_get_Length(isWrong));
    }

    return true;
}
