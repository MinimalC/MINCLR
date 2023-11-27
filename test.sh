#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

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
$INTERP ./System.Signal.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Syscall.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Thread.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.string8.test >> $REPORT 2>&1 ; echo >> $REPORT
$INTERP ./System.Integers.test >> $REPORT 2>&1 ; echo >> $REPORT
