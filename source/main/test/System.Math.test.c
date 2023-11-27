#define using_System
#include <min/System.h>

int System_Runtime_main(int argc, char * argv[]) {

    UInt64 divident64 = 14, divisor64 = 2, remainder64 = 0;
    UInt64 quotient64 = System_UInt64_divRem(divident64, divisor64, &remainder64);
	Console_writeLine("Test01: System_UInt64_divRem({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident64, divisor64, quotient64, remainder64);

    divident64 = 15; divisor64 = 2; remainder64 = 0;
    quotient64 = System_UInt64_divRem(divident64, divisor64, &remainder64);
	Console_writeLine("Test02: System_UInt64_divRem({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident64, divisor64, quotient64, remainder64);

	return true;	/* OK (1 == true) */
}
