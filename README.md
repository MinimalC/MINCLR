***MINCLR: Minimal C Language Runtime***

**Example Usage**

Open a text editor of your choice and create a file named `Hello.c`. For now you should place this file in the `~/FIKTIV/MINCLR/source/main/` folder.

```
#define using_System
#include <min/System.h>

Size Hello(Size argc, String8 argv[]) {

    if (argc > 1) {
        Console_writeLine("Hello {0:string}!", 1, argv[1]);
        return true;
    }

    Console_writeLine__string("Hello World!");
    return false;
}
```
To run this code, navigate to the `~/FIKTIV/MINCLR/` folder and execute the following command: `run.awk make.awk -std include/ executable source/main/Hello.c`.

**Quick Start for C developers**

- Instead of the old method,
    + I would use the new method.

- `int printf(char *, ...)`
    +  `Size  Console_write(String8 format, ...)`
    +  `Size  Console_writeLine(String8 format, ...)`

        Usage:

        `Console_writeLine("{0:string} {1:bool}", 2, string, boolean);`

        `Console_writeLine("{0:uint} {1:uint:hex} {2:int} {3:int32}", 4, uint, uint, int, int);`

- `int strcmp(char * str1, char * str2)`

    strcmp returns the difference of the last two ASCII characters.

    +  `Size  String8_compare(String8 that, String8 other)`

        String8_compare returns the number of characters, which are equal.

    +  `Bool  String8_equals(String8 that, String8 other)`

        String8_equals returns true, if all of the characters are equal.

- `int strlen(char * str)`
    + `Size  String8_get_Length(String8 that)`

- `void * malloc (size_t size)`
    + `Var  Memory_allocClass(Type type)`

        Usage: `File file = Memory_allocClass(typeof(File));`

    + `Var  Memory_allocArray(Type type, Size size)`

        Usage: `String8 string = Memory_allocArray(typeof(Char8), length + 1);`


**Install Minimal C Language Runtime**

MINCLR is all about C `typedef struct System_Object * System_Object;`, which doesn't work in C++, CPP, you'd get a compiler exception.

This is currently a DEBUG version. You need to use make.awk, GCC and AMD64 Linux. I didn't try this on other compilers or on Windows.

I do want you to use `run.sh`, which is using [make.awk](//github.com/MinimalC/make.awk):

```
## Install make.awk
sudo gawk -f run.awk install

/usr/bin/run.awk is now linked to ~/FIKTIV/make.awk/run.awk.
/usr/bin/make.awk is now linked to ~/FIKTIV/make.awk/make.awk.

# System
run.awk @System.config make.awk 1>&2 2>.System...report

# Extension
run.awk @System.Extension.config make.awk 1>&2 2>.Extension...report
```

To run MINCLR, you need to go to the folder `.make`, because of `System.Interpreter`, this is currently hardcoded into the binaries.

For example, use `./test.sh`, or `cd .make` and then try `./CubeHash512 Hello` or `./SipHash48 Hello`.

```
SipHash48:
0x634858001AB66950: System.Type
0x577F630E3A272ECD: System_Type

CubeHash256:
0xB2FF183593B30CEF9997A03D4A3E8A8A5370B270DF73365C68EC5ECB3A39D41A617D6BCCE77BF4935048180ADBD5D4DD1353D5411F5675BF5125AA04C4A0C2D: System.Type
0x7D949044D58D628DC53A48DFF429BA933F9844A29EBAC01D7B0D4C68DA646997FDB6D49C636D16EF4BA48827AF0DEBDB4EACEAA39C2556906657BD141A98D: System_Type

CubeHash512:
0x7373DD7981DBDFE8BF0104549FA56F5D23772400DB0A5678FAECC80DC1D09EEBBA70C3A21553729460EF1F2885619E525E2A669AF7429AC7B75953F5ED2D4B9EE3B98A23FA004D5458B5F395A1608033EDF2488CF4B195924D22ECFDDE60C1E695DA2A64640D36E70276FA895CE03CAC5BFEFF62E71997D44A5EB521F0102: System.Type
0x2D386EED645736C81D396FF8201BF107465CBAE8D0E9E92363DF6B603B3160CB20E38F3AA8A0039A80D93F31F4131DFC06DF8FC999442FE73617E25EED3177272B3D609D360674B4764BEB42929D1C8C6597F9E6105C5C35978DB9AB5B43C723D624B01F1ACDB02FC03C3C836E8AF890233A04C8F92F21B52F3700C9BECDB4: System_Type

System.Syscall:
Syscall is right
__vdso_gettimeofday: 1777110079.945883 timezone: minutesWest 0, dstTime 0
System_Syscall_time: now 1777110079, das sind etwa 857 Tage, 9 Stunden, 41 Minuten, 19 Sekunden
DateTime_now_toString: 25.4.2026 9:41:19

ECQLite:
Person: Name Hans, Geburtsdatum 12.11.1984, Email hans@mail.de, Telefon +491765432109
Produkt: Name Redmi6A, Kategorie Android, Größe 16x9, Gewicht 300g
Produkt deleted.
Produkt not found.
Katalog not found.
TERMINIERT: throws IOException: No Table Katalog

System.Exception:
SUCCESS: catch IOException
This is finally.
SUCCESS: returning false
TERMINIERT: throws IOException: error ENOENT(2): File not found

System.File:
Position 5 is correct
HaLLo is correct, 5 bytes read
SUCCESS: catch IOException

System.FileInfo:
FileInfo.name: ./.System.File.test.txt, File (100664), UserID: 1000, GroupID: 1000
ContainerId: 804, INodeId: 6232225, Hardlinks: 1, deviceId: 0, size: 5, BulkSize: 4096, Blocks: 8 
FileInfo.name: ./.System.File.test.txt, Directory (40775), UserID: 1000, GroupID: 1000
ContainerId: 804, INodeId: 6275210, Hardlinks: 2, deviceId: 0, size: 12288, BulkSize: 4096, Blocks: 24 
SUCCESS: FILENOTFOUND ENOFILE

System.Math:
Test01: System_UInt64_divRem(14, 2) => 7 Rest 0
Test02: System_UInt64_divRem(15, 2) => 7 Rest 1

System.Memory:
Test01: SUCCESS: System_Memory_allocClass
Test01: SUCCESS: System_Memory_isAllocated
Test02: SUCCESS: System_Memory_compare
Test03: SUCCESS: System_Memory_equals
Test04: SUCCESS: System_Memory_indexOf
Test04: SUCCESS: System_Memory_indexOf__other
Test05: SUCCESS: System_Memory_free
Test06: SUCCESS: System_Memory_moveTo
Test07: SUCCESS: System_Memory_moveTo
Test08: SUCCESS: System_Memory_sort ascending 0000111122223333444455556666777788889999AAAABBBBCCCCDDDDEEEEFFFF
Test09: SUCCESS: System_Memory_sort descending FFFFEEEEDDDDCCCCBBBBAAAA9999888877776666555544443333222211110000
Test10: SUCCESS: System_Memory_reallocArray AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDEEEEEEEEEEEEEEEEFFFFFFFFFFFFFFFF

System.MemoryStream:
File System.core...C, size 707029
MemoryStream size*1 707029, capacity 720896, position 707029
MemoryStream size/2 353514, capacity 393216, position 353514

System.String8:
Test00: SUCCESS: String8_isNullOrEmpty
Test01: SUCCESS: String8_get_Length
Test02: SUCCESS: String8_indexOf__char
Test03: SUCCESS: String8_indexOf
Test04: SUCCESS: String8_lastIndexOf__char
Test05: SUCCESS: String8_lastIndexOf
Test06: SUCCESS: String8_concat2
Test07: SUCCESS: String8_concat__arguments
Test08: SUCCESS: System_String8_encodeBase64
Test09: SUCCESS: System_String8_decodeBase64

System.Directory:
inode 5FC08A type 4 name .
inode 5FC00C type 4 name ..
inode 5E005E type 8 name CubeHash256
inode 5F1845 type 8 name CubeHash256...ASM
inode 5F1844 type 8 name CubeHash256...C
inode 5F1868 type 8 name CubeHash256...o
inode 5F1479 type 8 name CubeHash256.a
inode 5E0064 type 8 name CubeHash512
inode 5F1843 type 8 name CubeHash512...ASM
inode 5F1842 type 8 name CubeHash512...C
inode 5F1867 type 8 name CubeHash512...o
inode 5F147A type 8 name CubeHash512.a
inode 5E000F type 8 name ECQLite.test
inode 5F183D type 8 name ECQLite.test...ASM
inode 5F183C type 8 name ECQLite.test...C
inode 5F1864 type 8 name ECQLite.test...o
inode 5F1466 type 8 name ECQLite.test.a
inode 5E005D type 8 name ECQLite1
inode 5F1853 type 8 name ECQLite1...ASM
inode 5F1852 type 8 name ECQLite1...C
inode 5F187D type 8 name ECQLite1...o
inode 5F1476 type 8 name ECQLite1.a
inode 5F1454 type 8 name ELFAssembly.read
inode 5F184F type 8 name ELFAssembly.read...ASM
inode 5F184E type 8 name ELFAssembly.read...C
inode 5F1877 type 8 name ELFAssembly.read...o
inode 5F1477 type 8 name ELFAssembly.read.a
inode 5E0060 type 8 name Eratosthenes
inode 5F184D type 8 name Eratosthenes...ASM
inode 5F184C type 8 name Eratosthenes...C
inode 5F1875 type 8 name Eratosthenes...o
inode 5F1478 type 8 name Eratosthenes.a
inode 5F189D type 8 name Extension...ASM
inode 5F189C type 8 name Extension...C
inode 5F189E type 8 name Extension...o
inode 5E006B type 8 name Extension.so
inode 5F145D type 8 name Hello...ASM
inode 5F1459 type 8 name Hello...C
inode 5F1462 type 8 name Hello...o
inode 5F1480 type 8 name Hello.a
inode 5F1899 type 8 name RenderC
inode 5F1855 type 8 name RenderC...ASM
inode 5F1854 type 8 name RenderC...C
inode 5F187E type 8 name RenderC...o
inode 5E005F type 8 name Shell1
inode 5F1847 type 8 name Shell1...ASM
inode 5F1846 type 8 name Shell1...C
inode 5F186F type 8 name Shell1...o
inode 5F147B type 8 name Shell1.a
inode 5E0067 type 8 name SipHash48
inode 5F1841 type 8 name SipHash48...ASM
inode 5F1840 type 8 name SipHash48...C
inode 5F1866 type 8 name SipHash48...o
inode 5F147C type 8 name SipHash48.a
inode 5F1573 type 8 name System...html
inode 5E0007 type 8 name System...txt
inode 5E0010 type 8 name System.Directory.test
inode 5F18A7 type 8 name System.Directory.test...ASM
inode 5F189F type 8 name System.Directory.test...C
inode 5F18A8 type 8 name System.Directory.test...o
inode 5F1467 type 8 name System.Directory.test.a
inode 5F1816 type 8 name System.ELF64Assembly.jump.gas...ASM
inode 5F1817 type 8 name System.ELF64Assembly.jump.gas...o
inode 5E0012 type 8 name System.Exception.test
inode 5F1824 type 8 name System.Exception.test...ASM
inode 5F1823 type 8 name System.Exception.test...C
inode 5F1858 type 8 name System.Exception.test...o
inode 5F1468 type 8 name System.Exception.test.a
inode 5E0014 type 8 name System.File.test
inode 5F1826 type 8 name System.File.test...ASM
inode 5F1825 type 8 name System.File.test...C
inode 5F1859 type 8 name System.File.test...o
inode 5F1469 type 8 name System.File.test.a
inode 5E0015 type 8 name System.FileInfo.test
inode 5F1829 type 8 name System.FileInfo.test...ASM
inode 5F1828 type 8 name System.FileInfo.test...C
inode 5F185A type 8 name System.FileInfo.test...o
inode 5F146A type 8 name System.FileInfo.test.a
inode 5F1814 type 8 name System.Integers.gas...ASM
inode 5F1815 type 8 name System.Integers.gas...o
inode 5E0017 type 8 name System.Integers.test
inode 5F183B type 8 name System.Integers.test...ASM
inode 5F183A type 8 name System.Integers.test...C
inode 5F1863 type 8 name System.Integers.test...o
inode 5F146B type 8 name System.Integers.test.a
inode 5E006A type 8 name System.Interpreter
inode 5F1822 type 8 name System.Interpreter...ASM
inode 5F1821 type 8 name System.Interpreter...C
inode 5F1857 type 8 name System.Interpreter...o
inode 5F1464 type 8 name System.Interpreter.a
inode 5E001E type 8 name System.Math.test
inode 5F182B type 8 name System.Math.test...ASM
inode 5F182A type 8 name System.Math.test...C
inode 5F185B type 8 name System.Math.test...o
inode 5F146C type 8 name System.Math.test.a
inode 5E0036 type 8 name System.Memory.test
inode 5F182D type 8 name System.Memory.test...ASM
inode 5F182C type 8 name System.Memory.test...C
inode 5F185C type 8 name System.Memory.test...o
inode 5F146D type 8 name System.Memory.test.a
inode 5F1453 type 8 name System.MemoryStream.test
inode 5F183F type 8 name System.MemoryStream.test...ASM
inode 5F183E type 8 name System.MemoryStream.test...C
inode 5F1865 type 8 name System.MemoryStream.test...o
inode 5F146F type 8 name System.MemoryStream.test.a
inode 5E007D type 8 name System.Path.test
inode 5F182F type 8 name System.Path.test...ASM
inode 5F182E type 8 name System.Path.test...C
inode 5F185D type 8 name System.Path.test...o
inode 5F1470 type 8 name System.Path.test.a
inode 5F1820 type 8 name System.Runtime.shared...ASM
inode 5F181F type 8 name System.Runtime.shared...C
inode 5F1856 type 8 name System.Runtime.shared...o
inode 5F1463 type 8 name System.Runtime.shared.a
inode 5E0059 type 8 name System.Signal.test
inode 5F1831 type 8 name System.Signal.test...ASM
inode 5F1830 type 8 name System.Signal.test...C
inode 5F185E type 8 name System.Signal.test...o
inode 5F1471 type 8 name System.Signal.test.a
inode 5E0058 type 8 name System.String8.test
inode 5F1833 type 8 name System.String8.test...ASM
inode 5F1832 type 8 name System.String8.test...C
inode 5F185F type 8 name System.String8.test...o
inode 5F1472 type 8 name System.String8.test.a
inode 5F1812 type 8 name System.Syscall.gas...ASM
inode 5F1813 type 8 name System.Syscall.gas...o
inode 5F181A type 8 name System.Syscall.sigreturn.gas...ASM
inode 5F181B type 8 name System.Syscall.sigreturn.gas...o
inode 5E005A type 8 name System.Syscall.test
inode 5F1835 type 8 name System.Syscall.test...ASM
inode 5F1834 type 8 name System.Syscall.test...C
inode 5F1860 type 8 name System.Syscall.test...o
inode 5F1473 type 8 name System.Syscall.test.a
inode 5E005B type 8 name System.Terminal.test
inode 5F1837 type 8 name System.Terminal.test...ASM
inode 5F1836 type 8 name System.Terminal.test...C
inode 5F1861 type 8 name System.Terminal.test...o
inode 5F1474 type 8 name System.Terminal.test.a
inode 5E0089 type 8 name System.Thread.boot.gas...ASM
inode 5F1819 type 8 name System.Thread.boot.gas...o
inode 5E005C type 8 name System.Thread.test
inode 5F1839 type 8 name System.Thread.test...ASM
inode 5F1838 type 8 name System.Thread.test...C
inode 5F1862 type 8 name System.Thread.test...o
inode 5F1475 type 8 name System.Thread.test.a
inode 5E0083 type 8 name System.Timer.test
inode 5F1456 type 8 name System.Timer.test...ASM
inode 5E006C type 8 name System.Timer.test...C
inode 5F1457 type 8 name System.Timer.test...o
inode 5F145F type 8 name System.a
inode 5F1811 type 8 name System.core...ASM
inode 5F180F type 8 name System.core...C
inode 5F181C type 8 name System.core...o
inode 5E0004 type 8 name System.so
inode 5E0068 type 8 name WebService2
inode 5F184B type 8 name WebService2...ASM
inode 5F184A type 8 name WebService2...C
inode 5F1874 type 8 name WebService2...o
inode 5F147E type 8 name WebService2.a
inode 5E0069 type 8 name WebService3
inode 5F1851 type 8 name WebService3...ASM
inode 5F1850 type 8 name WebService3...C
inode 5F187C type 8 name WebService3...o
inode 5F147F type 8 name WebService3.a
inode 5F145C type 8 name WebService4
inode 5F164A type 8 name WebService4...ASM
inode 5F1648 type 8 name WebService4...C
inode 5F164B type 8 name WebService4...o
inode 5F1465 type 8 name WebService4.a
inode 5F18A0 type 8 name database.ecql

System.Integers:
UInt8: 127 on stack
UInt8 to binary base2:       1111111
UInt8 to quadral base4:      1333
UInt8 to octal base8:        177
UInt8 to decimal base10:     127
UInt8 to hexadecimal base16: 7F
UInt16: 32767 on stack
UInt16 to binary base2:       111111111111111
UInt16 to quadral base4:      13333333
UInt16 to octal base8:        77777
UInt16 to decimal base10:     32767
UInt16 to hexadecimal base16: 7FFF
UInt32: 2147483647 on stack
UInt32 to binary base2:       1111111111111111111111111111111
UInt32 to quadral base4:      1333333333333333
UInt32 to octal base8:        17777777777
UInt32 to decimal base10:     2147483647
UInt32 to hexadecimal base16: 7FFFFFFF
UInt64: 18446744073709551615 on stack
UInt64 to binary base2:       1111111111111111111111111111111111111111111111111111111111111111
UInt64 to quadral base4:      33333333333333333333333333333333
UInt64 to octal base8:        1777777777777777777777
UInt64 to decimal base10:     18446744073709551615
UInt64 to hexadecimal base16: FFFFFFFFFFFFFFFF

Int8: -127 on stack
Int8 to binary base2:       -1111111
Int8 to quadral base4:      -1333
Int8 to octal base8:        -177
Int8 to decimal base10:     -127
Int8 to hexadecimal base16: -7F
Int16: -32767 on stack
Int16 to binary base2:       -111111111111111
Int16 to quadral base4:      -13333333
Int16 to octal base8:        -77777
Int16 to decimal base10:     -32767
Int16 to hexadecimal base16: -7FFF
Int32: -2147483647 on stack
Int32 to binary base2:       -1111111111111111111111111111111
Int32 to quadral base4:      -1333333333333333
Int32 to octal base8:        -17777777777
Int32 to decimal base10:     -2147483647
Int32 to hexadecimal base16: -7FFFFFFF
Int64: -9223372036854775807 on stack
Int64 to binary base2:       -111111111111111111111111111111111111111111111111111111111111111
Int64 to quadral base4:      -13333333333333333333333333333333
Int64 to octal base8:        -777777777777777777777
Int64 to decimal base10:     -9223372036854775807
Int64 to hexadecimal base16: -7FFFFFFFFFFFFFFF

System.Path:
Test0: "/home/user/../user1" & "/" => "/home/user1/": SUCCESS
Test1: "/home/user/../user1" & "index.html" => "/home/user1/index.html": SUCCESS
Test2: "/home/user/../user1" & "/index.html" => "/home/user1/index.html": SUCCESS
Test3: "/home/user/../user1" & "../index.html" => "/home/index.html": SUCCESS
Test4: "/home/user/../user1" & "/../index.html" => "/home/index.html": SUCCESS
Test5: "/home/user/../user1" & "/./Documents/whaat/../../Downloads/.System.File.test.txt" => "/home/user1/Downloads/.System.File.test.txt": SUCCESS
Test6: "/home/user/../user1" & "./Documents/whaat/Downloads/../../../../../.System.File.test.txt" => "/.System.File.test.txt": SUCCESS
Test7: "../../user1" & "/" => "../../user1/": SUCCESS
Test8: "../../user1" & "index.html" => "../../user1/index.html": SUCCESS
Test9: "../../user1" & "/index.html" => "../../user1/index.html": SUCCESS
Test10: "../../user1" & "../index.html" => "../../index.html": SUCCESS
Test11: "../../user1" & "/../index.html" => "../../index.html": SUCCESS
Test12: "../../user1" & "/./Documents/whaat/../../Downloads/.System.File.test.txt" => "../../user1/Downloads/.System.File.test.txt": SUCCESS
Test13: "../../user1" & "./Documents/whaat/Downloads/../../../../../.System.File.test.txt" => "../../../.System.File.test.txt": SUCCESS
Test14: "/home/user1/" & "/" => "/home/user1/": SUCCESS
Test15: "/home/user1/" & "index.html" => "/home/user1/index.html": SUCCESS
Test16: "/home/user1/" & "/index.html" => "/home/user1/index.html": SUCCESS
Test17: "/home/user1/" & "../index.html" => "/home/index.html": SUCCESS
Test18: "/home/user1/" & "/../index.html" => "/home/index.html": SUCCESS
Test19: "/home/user1/" & "/./Documents/whaat/../../Downloads/.System.File.test.txt" => "/home/user1/Downloads/.System.File.test.txt": SUCCESS
Test20: "/home/user1/" & "./Documents/whaat/Downloads/../../../../../.System.File.test.txt" => "/.System.File.test.txt": SUCCESS

System.Signal:
SIGSEGV: number 11, errno 0, code 1, sigfault.address FFFF
SIGILL: number 4, errno 0, code 2, sigfault.address 7F86F1F8681B
SIGFPE: number 8, errno 0, code 1, sigfault.address 7F86F1F86840
SUCCESS
SIGBUS:

System.Thread:
System_Thread_PID: 120046, System_Thread_TID: 120046
Wait on Child1, threadId 120047
Child64
Child8
Child32
Child64: 0. wrote number 1000000.
Child256
Child32: 12411. wrote number 100000.
Child32768
Child1024
Child2048
Child128
Child4096
Child512
Child2
Child1
Wait on Child2, threadId 120048
Wait on Child4, threadId 120049
Child16384
Child4
Child16
Child8192
Wait on Child8, threadId 120050
Wait on Child16, threadId 120051
Wait on Child32, threadId 120052
Child64 return number 1000000.
Wait on Child128, threadId 120054
Child1: 106005. wrote number 1.
Wait on Child256, threadId 120055
Wait on Child512, threadId 120056
Wait on Child1024, threadId 120057
Wait on Child2048, threadId 120058
Wait on Child4096, threadId 120059
Wait on Child8192, threadId 120060
Wait on Child16384, threadId 120061
Wait on Child32768, threadId 120062
System_Thread_TID: 120047 System_Thread_getRegister: 7FDD5CD58FE8
System_Thread_Current: 0x7FDD5CD59058, base.type 0x7FDD5D1A8860, threadId 120047, returnValue 0
Child4096: 105965. wrote number 1000000000000.
Child16384: 119416. wrote number 100000000000000.
Child4: 139687. wrote number 100.
Child8192: 178136. wrote number 10000000000000.
Child256: 325801. wrote number 100000000.
THREAD TERMINIERT: throws IOException: TestException
Child8: 560101. wrote number 1000.
Child1024: 429842. wrote number 10000000000.
Child16: 176951. wrote number 10000.
Child512: 401429. wrote number 1000000000.
Child128: 399099. wrote number 10000000.
Child32768: 325837. wrote number 1000000000000000.
Child2048: 246607. wrote number 100000000000.
Child2: 256101. wrote number 10.
Child1 return number 1.
Child2 return number 10.
Child4 return number 100.
Child8 return number 1000.
Child16 return number 10000.
Child32 return number 100000.
Child128 return number 10000000.
Child256 return number 100000000.
Child512 return number 1000000000.
Child1024 return number 10000000000.
Child2048 return number 100000000000.
Child4096 return number 1000000000000.
Child8192 return number 10000000000000.
Child16384 return number 100000000000000.
Child32768 return number 1000000000000000.
This is Parent
```
