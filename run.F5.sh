#!/bin/sh

[ -d "FIKTIV" ] && cd FIKTIV
[ -d "MINCLR" ] && cd MINCLR

[ -x ".run.sh" ] && ./.run.sh || ./run.sh
