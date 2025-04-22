#!/bin/sh

if [ PWD != '${HOME}/FIKTIV/MINCLR' ]; then
    cd $HOME/FIKTIV/MINCLR
fi

cd .make

INTERP=
#INTERP=./System.Interpreter
REPORT=../.System.test...report

echo "ELFAssembly.read:" > ../.ELFAssembly.read...report ; $INTERP ./ELFAssembly.read SipHash48 >> ../.ELFAssembly.read...report 2>&1
echo -n > $REPORT
echo  "SipHash48:" >> $REPORT ; $INTERP ./SipHash48 System.Type System_Type >> $REPORT 2>&1 ; echo >> $REPORT
echo  "CubeHash256:" >> $REPORT ; $INTERP ./CubeHash256 System.Type System_Type >> $REPORT 2>&1 ; echo >> $REPORT
echo  "CubeHash512:" >> $REPORT ; $INTERP ./CubeHash512 System.Type System_Type >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Exception:" >> $REPORT ; $INTERP ./System.Exception.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.File:" >> $REPORT ; $INTERP ./System.File.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.FileInfo:" >> $REPORT ; $INTERP ./System.FileInfo.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Math:" >> $REPORT ; $INTERP ./System.Math.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Memory:" >> $REPORT ; $INTERP ./System.Memory.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Path:" >> $REPORT ; $INTERP ./System.Path.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Signal:" >> $REPORT ; $INTERP ./System.Signal.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Syscall:" >> $REPORT ; $INTERP ./System.Syscall.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Thread:" >> $REPORT ; $INTERP ./System.Thread.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.String8:" >> $REPORT ; $INTERP ./System.String8.test >> $REPORT 2>&1 ; echo >> $REPORT
echo  "System.Integers:" >> $REPORT ; $INTERP ./System.Integers.test >> $REPORT 2>&1 ; echo >> $REPORT
