/* #include <math.h> */

#define using_System
#include <min/System.h>

//__main(test61_System_Math, args) {
int main(int argc, char * argv[]) {

	__int8 a = 2, b = 3, c;

	/* Test00 */
	c = __Math_addInt8(a, b);
	if (c != 5)
		__Console_writeLine__string8("Test00: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test00: SUCCESS: System_Math_addInt8");

	/* Test01 */
	c = __Math_addInt8(a, -b);
	if (c != -1)
		__Console_writeLine__string8("Test01: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test01: SUCCESS: System_Math_addInt8");

	/* Test02 */
	c = __Math_addInt8(-a, b);
	if (c != 1)
		__Console_writeLine__string8("Test02: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test02: SUCCESS: System_Math_addInt8");

	/* Test03 */
	c = __Math_addInt8(-a, -b);
	if (c != -5)
		__Console_writeLine__string8("Test03: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test03: SUCCESS: System_Math_addInt8");

	/* Test04 */
	c = __Math_addInt8(__int8_Max, b);
	if (c != 0)
		__Console_writeLine__string8("Test04: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test04: SUCCESS: System_Math_addInt8");

	/* Test05 */
	c = __Math_addInt8(a, __int8_Max);
	if (c != 0)
		__Console_writeLine__string8("Test05: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test05: SUCCESS: System_Math_addInt8");

	/* Test06 */
	c = __Math_addInt8(__int8_Min, -b);
	if (c != 0)
		__Console_writeLine__string8("Test06: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test06: SUCCESS: System_Math_addInt8");

	/* Test07 */
	c = __Math_addInt8(-a, __int8_Min);
	if (c != 0)
		__Console_writeLine__string8("Test07: ERROR: System_Math_addInt8");
	else
		__Console_writeLine__string8("Test07: SUCCESS: System_Math_addInt8");


    __uint64 divident = 14, divisor = 2, remainder = 0;
    __uint64 quotient = System_Math_divideRemain__uint64(divident, divisor, &remainder);
	__Console_writeLine("Test08: System_Math_divideRemain({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident, divisor, quotient, remainder);
    divident = 15; divisor = 2; remainder = 0;
    quotient = System_Math_divideRemain__uint64(divident, divisor, &remainder);
	__Console_writeLine("Test09: System_Math_divideRemain({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident, divisor, quotient, remainder);

	return __true;	/* OK (1 == true) */
}
