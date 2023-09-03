#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

# System
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=System precompile include/ source/AMD64/GNU.Linux/GAS/System.Syscall.gas.S source/AMD64/GNU.Linux/GAS/System.Math.gas.S source/AMD64/GNU.Linux/GAS/System.ELF64Assembly.gas.S source/AMD64/GNU.Linux/GAS/System.Thread.boot.gas.S source/System.core.c source/System.ELFAssembly.c source/Network.TCPSocket.c  compile library executable  source/main/System.Runtime.shared.c source/main/System.Interpreter.c source/main/Eratosthenes.c source/main/ELFAssembly.read.c source/main/WebService.c source/main/test/Crypto.SipHash.test.c source/main/test/System.Exception.test.c source/main/test/System.File.test.c source/main/test/System.FileInfo.test.c source/main/test/System.Math.test.c source/main/test/System.Memory.test.c source/main/test/System.Path.test.c source/main/test/System.Syscall.test.c source/main/test/System.Thread.test.c source/main/test/System.string8.test.c source/main/test/System.values.test.c 1>&2 2>.System...report

# Extension
run.awk ~/FIKTIV/make.awk/make.awk -std +shared +debug project=Extension precompile include/ .Extension.c compile library 1>&2 2>.Extension...report


cd .make

INTERP=
#INTERP=./System.Interpreter
REPORT=System.test...report

$INTERP ./ELFAssembly.read Crypto.SipHash.test > ELFAssembly.read...report 2>&1
echo -n > $REPORT
$INTERP ./Crypto.SipHash.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Exception.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.File.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.FileInfo.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Math.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Memory.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Path.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Syscall.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Thread.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.string8.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.values.test >> $REPORT 2>&1 ; echo >> $REPORT
