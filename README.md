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
0xE8E7E4A139BB3C3D: System.Type
0x36C602317CA4A42D: System_Type

CubeHash256:
0xB2FF183593B30CEF9997A03D4A3E8A8A5370B270DF73365C68EC5ECB3A39D41A617D6BCCE77BF4935048180ADBD5D4DD1353D5411F5675BF5125AA04C4A0C2D: System.Type
0x7D949044D58D628DC53A48DFF429BA933F9844A29EBAC01D7B0D4C68DA646997FDB6D49C636D16EF4BA48827AF0DEBDB4EACEAA39C2556906657BD141A98D: System_Type

CubeHash512:
0x7373DD7981DBDFE8BF0104549FA56F5D23772400DB0A5678FAECC80DC1D09EEBBA70C3A21553729460EF1F2885619E525E2A669AF7429AC7B75953F5ED2D4B9EE3B98A23FA004D5458B5F395A1608033EDF2488CF4B195924D22ECFDDE60C1E695DA2A64640D36E70276FA895CE03CAC5BFEFF62E71997D44A5EB521F0102: System.Type
0x2D386EED645736C81D396FF8201BF107465CBAE8D0E9E92363DF6B603B3160CB20E38F3AA8A0039A80D93F31F4131DFC06DF8FC999442FE73617E25EED3177272B3D609D360674B4764BEB42929D1C8C6597F9E6105C5C35978DB9AB5B43C723D624B01F1ACDB02FC03C3C836E8AF890233A04C8F92F21B52F3700C9BECDB4: System_Type

System.Syscall:
Syscall is right
__vdso_gettimeofday: 1794730904.653226 timezone: minutesWest 0, dstTime 0
System_Syscall_time: now 1794730904, das sind etwa 865 Tage, 8 Stunden, 21 Minuten, 44 Sekunden
DateTime_now_toString: 15.11.2026 8:21:44

ECQLite:
Person: Name Hans, Geburtsdatum 12.11.1984, Email hans@mail.de, Telefon +491765432109
Produkt: Name Redmi6A, Kategorie Android, Größe 16x9, Gewicht 300g
Produkt deleted.
Produkt not found.
Katalog not found.
TERMINIERT: throws System.IOException: No Table Katalog

System.Exception:
SUCCESS: catch System.IOException
This is finally.
SUCCESS: returning false
TERMINIERT: throws System.IOException: error ENOENT(2): File not found

System.File:
Position 5 is correct
HaLLo is correct, 5 bytes read
SUCCESS: catch System.IOException

System.FileInfo:
FileInfo.name: ./.System.File.test.txt, File (100664), UserID: 1000, GroupID: 1000
ContainerId: 804, INodeId: 6293023, Hardlinks: 1, deviceId: 0, size: 5, BulkSize: 4096, Blocks: 8
FileInfo.name: ./.System.File.test.txt, Directory (40775), UserID: 1000, GroupID: 1000
ContainerId: 804, INodeId: 6292867, Hardlinks: 2, deviceId: 0, size: 4096, BulkSize: 4096, Blocks: 8
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
File System.core...C, size 727841
MemoryStream size*1 727841, capacity 786432, position 727841
MemoryStream size/2 363920, capacity 393216, position 363920

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
inode 600583 type 4 name .
inode 5FC00C type 4 name ..
inode 600611 type 8 name CubeHash256
inode 6005D3 type 8 name CubeHash256...ASM
inode 6005D2 type 8 name CubeHash256...C
inode 6005F7 type 8 name CubeHash256...o
inode 600612 type 8 name CubeHash512
inode 6005D5 type 8 name CubeHash512...ASM
inode 6005D4 type 8 name CubeHash512...C
inode 6005F8 type 8 name CubeHash512...o
inode 6005FF type 8 name ECQLite.test
inode 6005AE type 8 name ECQLite.test...ASM
inode 6005AD type 8 name ECQLite.test...C
inode 6005E5 type 8 name ECQLite.test...o
inode 60060E type 8 name ECQLite1
inode 6005CD type 8 name ECQLite1...ASM
inode 6005CC type 8 name ECQLite1...C
inode 6005F4 type 8 name ECQLite1...o
inode 60060F type 8 name ELFAssembly.read
inode 6005CF type 8 name ELFAssembly.read...ASM
inode 6005CE type 8 name ELFAssembly.read...C
inode 6005F5 type 8 name ELFAssembly.read...o
inode 600610 type 8 name Eratosthenes
inode 6005D1 type 8 name Eratosthenes...ASM
inode 6005D0 type 8 name Eratosthenes...C
inode 6005F6 type 8 name Eratosthenes...o
inode 60061B type 8 name Extension...ASM
inode 60061A type 8 name Extension...C
inode 60061C type 8 name Extension...o
inode 60061D type 8 name Extension.so
inode 600613 type 8 name Shell1
inode 6005D9 type 8 name Shell1...ASM
inode 6005D6 type 8 name Shell1...C
inode 6005F9 type 8 name Shell1...o
inode 600614 type 8 name SipHash48
inode 6005DB type 8 name SipHash48...ASM
inode 6005DA type 8 name SipHash48...C
inode 6005FA type 8 name SipHash48...o
inode 600619 type 8 name System...html
inode 600618 type 8 name System...txt
inode 600600 type 8 name System.Directory.test
inode 6005B1 type 8 name System.Directory.test...ASM
inode 6005B0 type 8 name System.Directory.test...C
inode 6005E6 type 8 name System.Directory.test...o
inode 60059F type 8 name System.ELF64Assembly.jump.gas...ASM
inode 6005A0 type 8 name System.ELF64Assembly.jump.gas...o
inode 600601 type 8 name System.Exception.test
inode 6005B3 type 8 name System.Exception.test...ASM
inode 6005B2 type 8 name System.Exception.test...C
inode 6005E7 type 8 name System.Exception.test...o
inode 600602 type 8 name System.File.test
inode 6005B5 type 8 name System.File.test...ASM
inode 6005B4 type 8 name System.File.test...C
inode 6005E8 type 8 name System.File.test...o
inode 600603 type 8 name System.FileInfo.test
inode 6005B7 type 8 name System.FileInfo.test...ASM
inode 6005B6 type 8 name System.FileInfo.test...C
inode 6005E9 type 8 name System.FileInfo.test...o
inode 60059D type 8 name System.Integers.gas...ASM
inode 60059E type 8 name System.Integers.gas...o
inode 600604 type 8 name System.Integers.test
inode 6005B9 type 8 name System.Integers.test...ASM
inode 6005B8 type 8 name System.Integers.test...C
inode 6005EA type 8 name System.Integers.test...o
inode 6005FE type 8 name System.Interpreter
inode 6005AB type 8 name System.Interpreter...ASM
inode 6005A9 type 8 name System.Interpreter...C
inode 6005E4 type 8 name System.Interpreter...o
inode 600605 type 8 name System.Math.test
inode 6005BB type 8 name System.Math.test...ASM
inode 6005BA type 8 name System.Math.test...C
inode 6005EB type 8 name System.Math.test...o
inode 600606 type 8 name System.Memory.test
inode 6005BD type 8 name System.Memory.test...ASM
inode 6005BC type 8 name System.Memory.test...C
inode 6005EC type 8 name System.Memory.test...o
inode 600607 type 8 name System.MemoryStream.test
inode 6005BF type 8 name System.MemoryStream.test...ASM
inode 6005BE type 8 name System.MemoryStream.test...C
inode 6005ED type 8 name System.MemoryStream.test...o
inode 600608 type 8 name System.Path.test
inode 6005C1 type 8 name System.Path.test...ASM
inode 6005C0 type 8 name System.Path.test...C
inode 6005EE type 8 name System.Path.test...o
inode 6005A8 type 8 name System.Runtime.shared...ASM
inode 6005A7 type 8 name System.Runtime.shared...C
inode 6005E3 type 8 name System.Runtime.shared...o
inode 600609 type 8 name System.Signal.test
inode 6005C3 type 8 name System.Signal.test...ASM
inode 6005C2 type 8 name System.Signal.test...C
inode 6005EF type 8 name System.Signal.test...o
inode 60060A type 8 name System.String8.test
inode 6005C5 type 8 name System.String8.test...ASM
inode 6005C4 type 8 name System.String8.test...C
inode 6005F0 type 8 name System.String8.test...o
inode 60059B type 8 name System.Syscall.gas...ASM
inode 60059C type 8 name System.Syscall.gas...o
inode 6005A3 type 8 name System.Syscall.sigreturn.gas...ASM
inode 6005A4 type 8 name System.Syscall.sigreturn.gas...o
inode 60060B type 8 name System.Syscall.test
inode 6005C7 type 8 name System.Syscall.test...ASM
inode 6005C6 type 8 name System.Syscall.test...C
inode 6005F1 type 8 name System.Syscall.test...o
inode 60060C type 8 name System.Terminal.test
inode 6005C9 type 8 name System.Terminal.test...ASM
inode 6005C8 type 8 name System.Terminal.test...C
inode 6005F2 type 8 name System.Terminal.test...o
inode 6005A1 type 8 name System.Thread.boot.gas...ASM
inode 6005A2 type 8 name System.Thread.boot.gas...o
inode 60060D type 8 name System.Thread.test
inode 6005CB type 8 name System.Thread.test...ASM
inode 6005CA type 8 name System.Thread.test...C
inode 6005F3 type 8 name System.Thread.test...o
inode 60059A type 8 name System.core...ASM
inode 600599 type 8 name System.core...C
inode 6005A5 type 8 name System.core...o
inode 6005A6 type 8 name System.so
inode 600615 type 8 name WebService2
inode 6005DD type 8 name WebService2...ASM
inode 6005DC type 8 name WebService2...C
inode 6005FB type 8 name WebService2...o
inode 600616 type 8 name WebService3
inode 6005E0 type 8 name WebService3...ASM
inode 6005DE type 8 name WebService3...C
inode 6005FC type 8 name WebService3...o
inode 600617 type 8 name WebService4
inode 6005E2 type 8 name WebService4...ASM
inode 6005E1 type 8 name WebService4...C
inode 6005FD type 8 name WebService4...o
inode 60061E type 8 name database.ecql

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
SIGILL: number 4, errno 0, code 2, sigfault.address 7F2E6941785F
SIGFPE: number 8, errno 0, code 1, sigfault.address 7F2E69417884
SUCCESS
SIGBUS:

System.Thread:
System_Thread_PID: 1469970, System_Thread_TID: 1469970
Child2
Child2: 0. wrote number 10.
Child8
Child32
Child16
Child8: 0. wrote number 1000.
Child4
Child1024
Child128
Child64
Child128: 0. wrote number 10000000.
Child64: 8899. wrote number 1000000.
Wait on Child1, threadId 1469971
Child2 return number 10.
Child1024: 17776. wrote number 10000000000.
Child512
Child512: 2976. wrote number 1000000000.
Child16384
Child4: 45164. wrote number 100.
Child2048
Child16384: 7247. wrote number 100000000000000.
Child2048: 21358. wrote number 100000000000.
Child256
Wait on Child4, threadId 1469973
Child8 return number 1000.
Wait on Child16, threadId 1469975
Wait on Child32, threadId 1469976
Child64 return number 1000000.
Child128 return number 10000000.
Wait on Child256, threadId 1469979
Child8192
Child1
Child4096
Child512 return number 1000000000.
Child1024 return number 10000000000.
Wait on Child2048, threadId 1469982
Wait on Child4096, threadId 1469983
Wait on Child8192, threadId 1469984
Child16384 return number 100000000000000.
Wait on Child32768, threadId 1469986
Child32768
Child8192: 89701. wrote number 10000000000000.
Child1: 509019. wrote number 1.
System_Thread_TID: 1469971 System_Thread_getRegister: 7F9431E1AFE8
System_Thread_Current: 0x7F9431E1B058, base.type 0xA4978BFB1B82602B, threadId 1469971, returnValue 0
Child32: 101683. wrote number 100000.
Child16: 258989. wrote number 10000.
Child4096: 316745. wrote number 1000000000000.
Child256: 214989. wrote number 100000000.
THREAD TERMINIERT: Child32768: 177878. wrote number 1000000000000000.
throws System.IOException: TestException
Child1 return number 1.
Child4 return number 100.
Child16 return number 10000.
Child32 return number 100000.
Child256 return number 100000000.
Child2048 return number 100000000000.
Child4096 return number 1000000000000.
Child8192 return number 10000000000000.
Child32768 return number 1000000000000000.
This is Parent
```
