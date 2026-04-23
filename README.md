***MINCLR: Minimal C Language Runtime***

**Example Usage**

Open a text editor of your choice and create a file named `Hello.c`.

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

**Quick Start for C developers**

- Instead of the old method,
    + I would use the new method.

- int printf(char *, ...)
    +  Size  Console_write(String8 format, ...)
    +  Size  Console_writeLine(String8 format, ...)

        Usage: Console_writeLine("{0:string} {1:bool} {2:uint} {3:uint:hex} {4:int} {5:int32}", 6, string, boolean, uint, uint, int, int);

- int strcmp(char * str1, char * str2)

    strcmp returns the difference of the last two ASCII characters.

    +  Size  String8_compare(String8 that, String8 other)

        String8_compare returns the number of characters, which are equal.

    +  Bool  String8_equals(String8 that, String8 other)

        String8_equals returns true, if all of the characters are equal.

- int strlen(char * str)
    + Size  String8_get_Length(String8 that)

- void * malloc (size_t size)
    + Var  Memory_allocClass(Type type)

        Usage: File file = Memory_allocClass(typeof(File));

    + Var  Memory_allocArray(Type type, Size size)

        Usage: String8 string = Memory_allocArray(typeof(Char8), length + 1);


This is currently a DEBUG version. You need t use make.awk, GCC and AMD64 Linux. I didn't try this on other compilers or on Windows.

MINCLR is all about C `typedef struct System_Object * System_Object;`, which doesn't work in C++, CPP, you'd get a compiler exception.

I do want you to use `run.sh`, which is using [make.awk](//github.com/MinimalC/make.awk):

```
# System
run.awk @System.config make.awk 1>&2 2>.System...report

# Extension
run.awk @System.Extension.config make.awk 1>&2 2>.Extension...report
```

To run MINCLR, you need to go to the folder `.make`, because of `System.Interpreter`, this is currently hardcoded into the binaries.

For example, use `./test.sh`, or `cd .make` and then try `./CubeHash512 Hello` or `./SipHash48 Hello`.


This is creating the following files:

```
.make/CubeHash256
.make/CubeHash256...ASM
.make/CubeHash256...C
.make/CubeHash256...o
.make/CubeHash512
.make/CubeHash512...ASM
.make/CubeHash512...C
.make/CubeHash512...o
.make/ELFAssembly.read
.make/ELFAssembly.read...ASM
.make/ELFAssembly.read...C
.make/ELFAssembly.read...o
.make/Eratosthenes
.make/Eratosthenes...ASM
.make/Eratosthenes...C
.make/Eratosthenes...o
.make/Extension...ASM
.make/Extension...C
.make/Extension...o
.make/Extension.so
.make/Shell1
.make/Shell1...ASM
.make/Shell1...C
.make/Shell1...o
.make/SipHash48
.make/SipHash48...ASM
.make/SipHash48...C
.make/SipHash48...o
.make/System...html
.make/System.ELF64Assembly.jump.gas...ASM
.make/System.ELF64Assembly.jump.gas...o
.make/System.Exception.test
.make/System.Exception.test...ASM
.make/System.Exception.test...C
.make/System.Exception.test...o
.make/System.File.test
.make/System.File.test...ASM
.make/System.File.test...C
.make/System.File.test...o
.make/System.FileInfo.test
.make/System.FileInfo.test...ASM
.make/System.FileInfo.test...C
.make/System.FileInfo.test...o
.make/System.Integers.gas...ASM
.make/System.Integers.gas...o
.make/System.Integers.test
.make/System.Integers.test...ASM
.make/System.Integers.test...C
.make/System.Integers.test...o
.make/System.Interpreter
.make/System.Interpreter...ASM
.make/System.Interpreter...C
.make/System.Interpreter...o
.make/System.Math.test
.make/System.Math.test...ASM
.make/System.Math.test...C
.make/System.Math.test...o
.make/System.Memory.test
.make/System.Memory.test...ASM
.make/System.Memory.test...C
.make/System.Memory.test...o
.make/System.Path.test
.make/System.Path.test...ASM
.make/System.Path.test...C
.make/System.Path.test...o
.make/System.Runtime.shared...ASM
.make/System.Runtime.shared...C
.make/System.Runtime.shared...o
.make/System.Signal.test
.make/System.Signal.test...ASM
.make/System.Signal.test...C
.make/System.Signal.test...o
.make/System.String8.test
.make/System.String8.test...ASM
.make/System.String8.test...C
.make/System.String8.test...o
.make/System.Syscall.gas...ASM
.make/System.Syscall.gas...o
.make/System.Syscall.sigreturn.gas...ASM
.make/System.Syscall.sigreturn.gas...o
.make/System.Syscall.test
.make/System.Syscall.test...ASM
.make/System.Syscall.test...C
.make/System.Syscall.test...o
.make/System.Terminal.test
.make/System.Terminal.test...ASM
.make/System.Terminal.test...C
.make/System.Terminal.test...o
.make/System.Thread.boot.gas...ASM
.make/System.Thread.boot.gas...o
.make/System.Thread.test
.make/System.Thread.test...ASM
.make/System.Thread.test...C
.make/System.Thread.test...o
.make/System.core...ASM
.make/System.core...C
.make/System.core...o
.make/System.so
.make/System.string8.test
.make/System.string8.test...ASM
.make/System.string8.test...C
.make/System.string8.test...o
.make/WebService1
.make/WebService1...ASM
.make/WebService1...C
.make/WebService1...o
.make/WebService2
.make/WebService2...ASM
.make/WebService2...C
.make/WebService2...o
.make/.System.File.test.txt
```
