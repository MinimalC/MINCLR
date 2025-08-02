#!/bin/sh

# System
run.awk @System.config make.awk $1 1>&2 2>.System...report

# Extension
run.awk @System.Extension.config make.awk $1 1>&2 2>.Extension...report

[ -x ".test.sh" ] && ./.test.sh || ./test.sh
