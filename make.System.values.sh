#!/bin/sh
# Gemeinfrei. Public Domain.
# 2020 Hans Riehm

./make.Generic.T.awk Namespace=System Type=uint8  generic/uint.awk.h generic/uint.awk.inc
./make.Generic.T.awk Namespace=System Type=uint16 generic/uint.awk.h generic/uint.awk.inc
./make.Generic.T.awk Namespace=System Type=uint32 generic/uint.awk.h generic/uint.awk.inc
./make.Generic.T.awk Namespace=System Type=uint64 generic/uint.awk.h generic/uint.awk.inc

./make.Generic.T.awk Namespace=System Type=int8 generic/int.awk.h generic/int.awk.inc
./make.Generic.T.awk Namespace=System Type=int16 generic/int.awk.h generic/int.awk.inc
./make.Generic.T.awk Namespace=System Type=int32 generic/int.awk.h generic/int.awk.inc
./make.Generic.T.awk Namespace=System Type=int64 generic/int.awk.h generic/int.awk.inc


file_h="include/min/System.values.auto.h"
file_inc="source/System.values.auto.c"
echo -n > $file_h
echo -n > $file_inc

cat include/min/.System.uint8.h >> $file_h
cat include/min/.System.uint16.h >> $file_h
cat include/min/.System.uint32.h >> $file_h
cat include/min/.System.uint64.h >> $file_h

cat include/min/.System.int8.h >> $file_h
cat include/min/.System.int16.h >> $file_h
cat include/min/.System.int32.h >> $file_h
cat include/min/.System.int64.h >> $file_h

cat source/.System.uint8.inc >> $file_inc
cat source/.System.uint16.inc >> $file_inc
cat source/.System.uint32.inc >> $file_inc
cat source/.System.uint64.inc >> $file_inc

cat source/.System.int8.inc >> $file_inc
cat source/.System.int16.inc >> $file_inc
cat source/.System.int32.inc >> $file_inc
cat source/.System.int64.inc >> $file_inc


rm include/min/.System.uint8.h
rm include/min/.System.uint16.h
rm include/min/.System.uint32.h
rm include/min/.System.uint64.h
rm include/min/.System.int8.h
rm include/min/.System.int16.h
rm include/min/.System.int32.h
rm include/min/.System.int64.h

rm source/.System.uint8.inc
rm source/.System.uint16.inc
rm source/.System.uint32.inc
rm source/.System.uint64.inc
rm source/.System.int8.inc
rm source/.System.int16.inc
rm source/.System.int32.inc
rm source/.System.int64.inc


# file_AUTO_h="include/meta/System.AUTO.h"
# file_AUTO_inc="source/System/System.AUTO.inc"

# do_replace() {
#     mv $file_AUTO_h "$file_AUTO_h.old"
#     mv $file_AUTO_inc "$file_AUTO_inc.old"

#     grep -v $1 "$file_AUTO_h.old" > $file_AUTO_h
#     grep -v $1 "$file_AUTO_inc.old" > $file_AUTO_inc

#     rm "$file_AUTO_h.old"
#     rm "$file_AUTO_inc.old"
# }

# do_replace "System.uint8.AUTO"
# do_replace "System.uint16.AUTO"
# do_replace "System.uint32.AUTO"
# do_replace "System.uint64.AUTO"
# do_replace "System.int8.AUTO"
# do_replace "System.int16.AUTO"
# do_replace "System.int32.AUTO"
# do_replace "System.int64.AUTO"
