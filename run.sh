#!/bin/sh

# System
run.awk ~/FIKTIV/make.awk/make.awk -std +shared project=System +debug precompile include/ source/AMD64/GNU.Linux/GAS/System.Syscall.gas.S source/AMD64/GNU.Linux/GAS/System.Math.gas.S source/System.core.c source/System.ELFAssembly.c  compile library executable  source/main/System.Interpreter.c source/main/System.Runtime.shared.c source/main/Eratosthenes.c source/main/ELFAssembly_read.c source/main/.try.c source/main/test/test.System.values.c source/main/test/test.Crypto.SipHash.c source/main/test/test.System.File.c source/main/test/test.System.FileInfo.c source/main/test/test.System.Exception.c source/main/test/test.System.Memory.c 2>.System...report

# Extension
run.awk ~/FIKTIV/make.awk/make.awk -std +shared project=Extension +debug precompile include/ .Extension.c compile library libSystem.so 2>.Extension...report
