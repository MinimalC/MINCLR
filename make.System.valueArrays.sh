#!/bin/sh
# Gemeinfrei. Public Domain.
# 2020 Hans Riehm

./make.Generic.T.awk Namespace=System Type=uint8  generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=uint16 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=uint32 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=uint64 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=int8 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=int16 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=int32 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=int64 generic/valueArrayT.awk.h generic/valueArrayT.awk.c

./make.Generic.T.awk Namespace=System Type=uint8  generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=uint16 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=uint32 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=uint64 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=int8 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=int16 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=int32 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=int64 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c


file_h="include/min/System.valueArrays.auto.h"
file_c="source/System.valueArrays.auto.c"
echo -n > $file_h
echo -n > $file_c

cat include/min/.System.uint8Array.h >> $file_h
cat include/min/.System.uint16Array.h >> $file_h
cat include/min/.System.uint32Array.h >> $file_h
cat include/min/.System.uint64Array.h >> $file_h
cat include/min/.System.int8Array.h >> $file_h
cat include/min/.System.int16Array.h >> $file_h
cat include/min/.System.int32Array.h >> $file_h
cat include/min/.System.int64Array.h >> $file_h

cat include/min/.System.uint8ArrayEnumerator.h >> $file_h
cat include/min/.System.uint16ArrayEnumerator.h >> $file_h
cat include/min/.System.uint32ArrayEnumerator.h >> $file_h
cat include/min/.System.uint64ArrayEnumerator.h >> $file_h
cat include/min/.System.int8ArrayEnumerator.h >> $file_h
cat include/min/.System.int16ArrayEnumerator.h >> $file_h
cat include/min/.System.int32ArrayEnumerator.h >> $file_h
cat include/min/.System.int64ArrayEnumerator.h >> $file_h


cat source/.System.uint8Array.c >> $file_c
cat source/.System.uint16Array.c >> $file_c
cat source/.System.uint32Array.c >> $file_c
cat source/.System.uint64Array.c >> $file_c
cat source/.System.int8Array.c >> $file_c
cat source/.System.int16Array.c >> $file_c
cat source/.System.int32Array.c >> $file_c
cat source/.System.int64Array.c >> $file_c

cat source/.System.uint8ArrayEnumerator.c >> $file_c
cat source/.System.uint16ArrayEnumerator.c >> $file_c
cat source/.System.uint32ArrayEnumerator.c >> $file_c
cat source/.System.uint64ArrayEnumerator.c >> $file_c
cat source/.System.int8ArrayEnumerator.c >> $file_c
cat source/.System.int16ArrayEnumerator.c >> $file_c
cat source/.System.int32ArrayEnumerator.c >> $file_c
cat source/.System.int64ArrayEnumerator.c >> $file_c


rm include/min/.System.uint8Array.h
rm include/min/.System.uint16Array.h
rm include/min/.System.uint32Array.h
rm include/min/.System.uint64Array.h
rm include/min/.System.int8Array.h
rm include/min/.System.int16Array.h
rm include/min/.System.int32Array.h
rm include/min/.System.int64Array.h

rm source/.System.uint8Array.c
rm source/.System.uint16Array.c
rm source/.System.uint32Array.c
rm source/.System.uint64Array.c
rm source/.System.int8Array.c
rm source/.System.int16Array.c
rm source/.System.int32Array.c
rm source/.System.int64Array.c


rm include/min/.System.uint8ArrayEnumerator.h
rm include/min/.System.uint16ArrayEnumerator.h
rm include/min/.System.uint32ArrayEnumerator.h
rm include/min/.System.uint64ArrayEnumerator.h
rm include/min/.System.int8ArrayEnumerator.h
rm include/min/.System.int16ArrayEnumerator.h
rm include/min/.System.int32ArrayEnumerator.h
rm include/min/.System.int64ArrayEnumerator.h

rm source/.System.uint8ArrayEnumerator.c
rm source/.System.uint16ArrayEnumerator.c
rm source/.System.uint32ArrayEnumerator.c
rm source/.System.uint64ArrayEnumerator.c
rm source/.System.int8ArrayEnumerator.c
rm source/.System.int16ArrayEnumerator.c
rm source/.System.int32ArrayEnumerator.c
rm source/.System.int64ArrayEnumerator.c


# file_AUTO_h="include/meta/System.AUTO.h"
# file_AUTO_c="source/System/System.AUTO.c"

# do_replace() {
#     mv $file_AUTO_h "$file_AUTO_h.old"
#     mv $file_AUTO_c "$file_AUTO_c.old"

#     grep -v $1 "$file_AUTO_h.old" > $file_AUTO_h
#     grep -v $1 "$file_AUTO_c.old" > $file_AUTO_c

#     rm "$file_AUTO_h.old"
#     rm "$file_AUTO_c.old"
# }

# do_replace "System.uint8.AUTO"
# do_replace "System.uint16.AUTO"
# do_replace "System.uint32.AUTO"
# do_replace "System.uint64.AUTO"
# do_replace "System.int8.AUTO"
# do_replace "System.int16.AUTO"
# do_replace "System.int32.AUTO"
# do_replace "System.int64.AUTO"
