#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

# System
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=System precompile include/ source/AMD64/GNU.Linux/GAS/System.Syscall.gas.S source/AMD64/GNU.Linux/GAS/System.Math.gas.S source/AMD64/GNU.Linux/GAS/System.ELF64Assembly.gas.S source/System.core.c source/System.ELFAssembly.c  compile library executable  source/main/System.Runtime.shared.c source/main/System.Interpreter.c source/main/Eratosthenes.c source/main/ELFAssembly_read.c source/main/test/test.System.values.c source/main/test/test.Crypto.SipHash.c source/main/test/test.System.File.c source/main/test/test.System.FileInfo.c source/main/test/test.System.Exception.c source/main/test/test.System.Memory.c source/main/.try2.c 1>&2 2>.System...report

# Extension
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=Extension precompile include/ .Extension.c compile library 1>&2 2>.Extension...report


cd .make

./try.ELFAssembly > try.ELFAssembly.read 2>&1
