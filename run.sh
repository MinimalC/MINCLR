#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

# System
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=System precompile include/ source/AMD64/Linux/GAS/System.Syscall.gas.S source/AMD64/Linux/GAS/System.Math.gas.S source/AMD64/Linux/GAS/System.ELF64Assembly.jump.gas.S source/AMD64/Linux/GAS/System.Thread.boot.gas.S source/AMD64/Linux/GAS/System.Syscall.sigreturn.gas.S source/System.core.c compile library executable  source/main/System.Runtime.shared.c source/main/System.Interpreter.c source/main/Eratosthenes.c source/main/ELFAssembly.read.c source/main/WebService1.c source/main/test/Crypto.SipHash.test.c source/main/test/System.Exception.test.c source/main/test/System.File.test.c source/main/test/System.FileInfo.test.c source/main/test/System.Math.test.c source/main/test/System.Memory.test.c source/main/test/System.Path.test.c source/main/test/System.Signal.test.c source/main/test/System.Syscall.test.c source/main/test/System.Thread.test.c source/main/test/System.string8.test.c source/main/test/System.values.test.c 1>&2 2>.System...report

# Extension
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=Extension precompile include/ .Extension.c compile library 1>&2 2>.Extension...report

./test.sh
