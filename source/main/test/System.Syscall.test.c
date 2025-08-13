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

    struct System_TimeSpan value; Stack_clear(value);
    struct System_TimeZone zone; Stack_clear(zone);

    System_Syscall_gettimeofday(&value, &zone);
    System_Console_writeLine("__vdso_gettimeofday: {0:int}.{1:int} timezone: minutesWest {2:int32}, dstTime {3:int32}", 4, value.sec, value.usec, zone.minutesWest, zone.dstTime);

    System_SSize now = System_Syscall_time();
    System_Console_write("System_Syscall_time: now {0:int}, ", 1, now);

    System_Size seconds, minutes, hours, days = 0;
    System_Size rest = System_UInt64_divRem(value.sec,60,&seconds);
    rest = System_UInt64_divRem(rest,60,&minutes);
    rest = System_UInt64_divRem(rest,24,&hours);
    days = rest / 24;
    System_Console_writeLine("das sind etwa {0:uint} Tage, {1:uint} Stunden, {2:uint} Minuten, {3:uint} Sekunden", 4, days, hours, minutes, seconds);

    System_String8 nowString = System_DateTime_now_toString();
    System_Console_writeLine("DateTime_now_toString: {0:string}", 1, nowString);
    System_Memory_free(nowString);

    return true;
}
