/* #include <math.h> */

#define using_System
#include <min/System.h>

//main(test61_System_Math, args) {
int main(int argc, char * argv[]) {

	Int8 a = 2, b = 3, c;

	/* Test00 */
	c = Math_addInt8(a, b);
	if (c != 5)
		Console_writeLine__String8("Test00: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test00: SUCCESS: System_Math_addInt8");

	/* Test01 */
	c = Math_addInt8(a, -b);
	if (c != -1)
		Console_writeLine__String8("Test01: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test01: SUCCESS: System_Math_addInt8");

	/* Test02 */
	c = Math_addInt8(-a, b);
	if (c != 1)
		Console_writeLine__String8("Test02: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test02: SUCCESS: System_Math_addInt8");

	/* Test03 */
	c = Math_addInt8(-a, -b);
	if (c != -5)
		Console_writeLine__String8("Test03: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test03: SUCCESS: System_Math_addInt8");

	/* Test04 */
	c = Math_addInt8(Int8_Max, b);
	if (c != 0)
		Console_writeLine__String8("Test04: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test04: SUCCESS: System_Math_addInt8");

	/* Test05 */
	c = Math_addInt8(a, Int8_Max);
	if (c != 0)
		Console_writeLine__String8("Test05: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test05: SUCCESS: System_Math_addInt8");

	/* Test06 */
	c = Math_addInt8(Int8_Min, -b);
	if (c != 0)
		Console_writeLine__String8("Test06: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test06: SUCCESS: System_Math_addInt8");

	/* Test07 */
	c = Math_addInt8(-a, Int8_Min);
	if (c != 0)
		Console_writeLine__String8("Test07: ERROR: System_Math_addInt8");
	else
		Console_writeLine__String8("Test07: SUCCESS: System_Math_addInt8");


    UInt64 divident = 14, divisor = 2, remainder = 0;
    UInt64 quotient = System_Math_divideRemain__UInt64(divident, divisor, &remainder);
	Console_writeLine("Test08: System_Math_divideRemain({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident, divisor, quotient, remainder);
    divident = 15; divisor = 2; remainder = 0;
    quotient = System_Math_divideRemain__UInt64(divident, divisor, &remainder);
	Console_writeLine("Test09: System_Math_divideRemain({0:uint}, {1:uint}) => {2:uint} Rest {3:uint}", 4, divident, divisor, quotient, remainder);

	return true;	/* OK (1 == true) */
}
