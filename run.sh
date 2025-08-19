#!/bin/sh

# System
run.awk @System.config make.awk $1 1>&2 2>.System...report

# Extension
run.awk @System.Extension.config make.awk $1 1>&2 2>.Extension...report

cp -f .make/System...html ./System.html
cp -f .make/System...txt ./System.txt

[ -x ".test.sh" ] && ./.test.sh || ./test.sh
