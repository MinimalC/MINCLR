#!/bin/sh
# Gemeinfrei. Public Domain.
# 2020 Hans Riehm

./make.Generic.T.awk Namespace=System Type=UInt8  generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt16 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt32 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt64 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=Int8 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=Int16 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=Int32 generic/valueArrayT.awk.h generic/valueArrayT.awk.c
./make.Generic.T.awk Namespace=System Type=Int64 generic/valueArrayT.awk.h generic/valueArrayT.awk.c

./make.Generic.T.awk Namespace=System Type=UInt8  generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt16 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt32 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=UInt64 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=Int8 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=Int16 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=Int32 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c
./make.Generic.T.awk Namespace=System Type=Int64 generic/valueArrayEnumeratorT.awk.h generic/valueArrayEnumeratorT.awk.c


file_h="include/min/System.valueArrays.auto.h"
file_c="source/System.valueArrays.auto.c"
echo -n > $file_h
echo -n > $file_c

cat include/min/.System.UInt8Array.h >> $file_h
cat include/min/.System.UInt16Array.h >> $file_h
cat include/min/.System.UInt32Array.h >> $file_h
cat include/min/.System.UInt64Array.h >> $file_h
cat include/min/.System.Int8Array.h >> $file_h
cat include/min/.System.Int16Array.h >> $file_h
cat include/min/.System.Int32Array.h >> $file_h
cat include/min/.System.Int64Array.h >> $file_h

cat include/min/.System.UInt8ArrayEnumerator.h >> $file_h
cat include/min/.System.UInt16ArrayEnumerator.h >> $file_h
cat include/min/.System.UInt32ArrayEnumerator.h >> $file_h
cat include/min/.System.UInt64ArrayEnumerator.h >> $file_h
cat include/min/.System.Int8ArrayEnumerator.h >> $file_h
cat include/min/.System.Int16ArrayEnumerator.h >> $file_h
cat include/min/.System.Int32ArrayEnumerator.h >> $file_h
cat include/min/.System.Int64ArrayEnumerator.h >> $file_h


cat source/.System.UInt8Array.c >> $file_c
cat source/.System.UInt16Array.c >> $file_c
cat source/.System.UInt32Array.c >> $file_c
cat source/.System.UInt64Array.c >> $file_c
cat source/.System.Int8Array.c >> $file_c
cat source/.System.Int16Array.c >> $file_c
cat source/.System.Int32Array.c >> $file_c
cat source/.System.Int64Array.c >> $file_c

cat source/.System.UInt8ArrayEnumerator.c >> $file_c
cat source/.System.UInt16ArrayEnumerator.c >> $file_c
cat source/.System.UInt32ArrayEnumerator.c >> $file_c
cat source/.System.UInt64ArrayEnumerator.c >> $file_c
cat source/.System.Int8ArrayEnumerator.c >> $file_c
cat source/.System.Int16ArrayEnumerator.c >> $file_c
cat source/.System.Int32ArrayEnumerator.c >> $file_c
cat source/.System.Int64ArrayEnumerator.c >> $file_c


rm include/min/.System.UInt8Array.h
rm include/min/.System.UInt16Array.h
rm include/min/.System.UInt32Array.h
rm include/min/.System.UInt64Array.h
rm include/min/.System.Int8Array.h
rm include/min/.System.Int16Array.h
rm include/min/.System.Int32Array.h
rm include/min/.System.Int64Array.h

rm source/.System.UInt8Array.c
rm source/.System.UInt16Array.c
rm source/.System.UInt32Array.c
rm source/.System.UInt64Array.c
rm source/.System.Int8Array.c
rm source/.System.Int16Array.c
rm source/.System.Int32Array.c
rm source/.System.Int64Array.c


rm include/min/.System.UInt8ArrayEnumerator.h
rm include/min/.System.UInt16ArrayEnumerator.h
rm include/min/.System.UInt32ArrayEnumerator.h
rm include/min/.System.UInt64ArrayEnumerator.h
rm include/min/.System.Int8ArrayEnumerator.h
rm include/min/.System.Int16ArrayEnumerator.h
rm include/min/.System.Int32ArrayEnumerator.h
rm include/min/.System.Int64ArrayEnumerator.h

rm source/.System.UInt8ArrayEnumerator.c
rm source/.System.UInt16ArrayEnumerator.c
rm source/.System.UInt32ArrayEnumerator.c
rm source/.System.UInt64ArrayEnumerator.c
rm source/.System.Int8ArrayEnumerator.c
rm source/.System.Int16ArrayEnumerator.c
rm source/.System.Int32ArrayEnumerator.c
rm source/.System.Int64ArrayEnumerator.c


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

# do_replace "System.UInt8.AUTO"
# do_replace "System.UInt16.AUTO"
# do_replace "System.UInt32.AUTO"
# do_replace "System.UInt64.AUTO"
# do_replace "System.Int8.AUTO"
# do_replace "System.Int16.AUTO"
# do_replace "System.Int32.AUTO"
# do_replace "System.Int64.AUTO"
