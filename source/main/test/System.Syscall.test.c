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
    System_Console_writeLine("gettimeofday: {0:int} {1:int} timezone: {2:int32} {3:int32}", 4, value.sec, value.usec, zone.minutesWest, zone.dstTime);


    System_Size seconds, minutes, hours, days = 0;
    System_Size rest = Math_divRem__UInt64(value.sec,60,&seconds);
    rest = Math_divRem__UInt64(rest,60,&minutes);
    rest = Math_divRem__UInt64(rest,24,&hours);
    days = rest / 24;

    System_Console_writeLine("etwa {0:uint} Tage, {1:uint} Stunden, {2:uint} Minuten, {3:uint} Sekunden", 4, days, hours, minutes, seconds);


    System_SSize now = System_Syscall_time();
    System_Console_writeLine("time: now {0:int}", 1, now);

    seconds, minutes, hours, days = 0;
    rest = Math_divRem__UInt64(now,60,&seconds);
    rest = Math_divRem__UInt64(rest,60,&minutes);
    rest = Math_divRem__UInt64(rest,24,&hours);
    days = rest / 24;

    System_Console_writeLine("etwa {0:uint} Tage, {1:uint} Stunden, {2:uint} Minuten, {3:uint} Sekunden", 4, days, hours, minutes, seconds);


    return true;
}
