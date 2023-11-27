#!/bin/sh
# Gemeinfrei. Public Domain.
# 2020 Hans Riehm

./make.Generic.T.awk Namespace=System Type=UInt8  generic/uint.awk.h generic/uint.awk.c
./make.Generic.T.awk Namespace=System Type=UInt16 generic/uint.awk.h generic/uint.awk.c
./make.Generic.T.awk Namespace=System Type=UInt32 generic/uint.awk.h generic/uint.awk.c
./make.Generic.T.awk Namespace=System Type=UInt64 generic/uint.awk.h generic/uint.awk.c

./make.Generic.T.awk Namespace=System Type=Int8 generic/int.awk.h generic/int.awk.c
./make.Generic.T.awk Namespace=System Type=Int16 generic/int.awk.h generic/int.awk.c
./make.Generic.T.awk Namespace=System Type=Int32 generic/int.awk.h generic/int.awk.c
./make.Generic.T.awk Namespace=System Type=Int64 generic/int.awk.h generic/int.awk.c

file_h="include/min/System.Integers.auto.h"
file_c="source/System.Integers.auto.c"
echo -n > $file_h
echo -n > $file_c

cat include/min/.System.UInt8.h >> $file_h
cat include/min/.System.UInt16.h >> $file_h
cat include/min/.System.UInt32.h >> $file_h
cat include/min/.System.UInt64.h >> $file_h

cat include/min/.System.Int8.h >> $file_h
cat include/min/.System.Int16.h >> $file_h
cat include/min/.System.Int32.h >> $file_h
cat include/min/.System.Int64.h >> $file_h

cat source/.System.UInt8.c >> $file_c
cat source/.System.UInt16.c >> $file_c
cat source/.System.UInt32.c >> $file_c
cat source/.System.UInt64.c >> $file_c

cat source/.System.Int8.c >> $file_c
cat source/.System.Int16.c >> $file_c
cat source/.System.Int32.c >> $file_c
cat source/.System.Int64.c >> $file_c


rm include/min/.System.UInt8.h
rm include/min/.System.UInt16.h
rm include/min/.System.UInt32.h
rm include/min/.System.UInt64.h
rm include/min/.System.Int8.h
rm include/min/.System.Int16.h
rm include/min/.System.Int32.h
rm include/min/.System.Int64.h

rm source/.System.UInt8.c
rm source/.System.UInt16.c
rm source/.System.UInt32.c
rm source/.System.UInt64.c
rm source/.System.Int8.c
rm source/.System.Int16.c
rm source/.System.Int32.c
rm source/.System.Int64.c


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
