#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

# System
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=System precompile include/ source/AMD64/GNU.Linux/GAS/System.Syscall.gas.S source/AMD64/GNU.Linux/GAS/System.Math.gas.S source/AMD64/GNU.Linux/GAS/System.ELF64Assembly.gas.S source/System.core.c source/System.ELFAssembly.c  compile library executable  source/main/System.Runtime.shared.c source/main/System.Interpreter.c source/main/Eratosthenes.c source/main/ELFAssembly_read.c source/main/test/test.Crypto.SipHash.c source/main/test/test.System.Exception.c source/main/test/test.System.File.c source/main/test/test.System.FileInfo.c source/main/test/test.System.Math.c source/main/test/test.System.Memory.c source/main/test/test.System.Syscall.c source/main/test/test.System.string8.c source/main/test/test.System.values.c 1>&2 2>.System...report

# Extension
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=Extension precompile include/ .Extension.c compile library 1>&2 2>.Extension...report

cd .make

INTERP=
#INTERP=./System.Interpreter

$INTERP ./ELFAssembly.read > ELFAssembly.read...report 2>&1
$INTERP ./test.Crypto.SipHash > test.Crypto.SipHash...report 2>&1
$INTERP ./test.System.Exception > test.System.Exception...report 2>&1
$INTERP ./test.System.File > test.System.File...report 2>&1
$INTERP ./test.System.FileInfo > test.System.FileInfo...report 2>&1
$INTERP ./test.System.Math > test.System.Math...report 2>&1
$INTERP ./test.System.Memory > test.System.Memory...report 2>&1
$INTERP ./test.System.Syscall > test.System.Syscall...report 2>&1
$INTERP ./test.System.string8 > test.System.string8...report 2>&1
$INTERP ./test.System.values > test.System.values...report 2>&1
