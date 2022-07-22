#define using_System
#include <min/System.h>

const Size sizeof_knownPrimes = 0x7FFFFFU;

internal UInt64 * knownPrimes;
internal UInt64 * knownPrimes_hoch2;

internal Size knownPrimesL = 0U;

Bool Eratosthenes_IsPrime(UInt64 n, UInt64 * minimalquotient, UInt64 * quotient) {

	UInt64 primeI = 2, primeN = 3, primeN_hoch2 = 9, quotient1 = 0, remainder = 0;

    /* UInt64 div2 = System_Math_divideRemain(n, 2, &remainder); */

	while (0U < ++primeI) {
		/* now primeI => [ 3 ] == 5 */

		if (primeI < sizeof_knownPrimes) {
			primeN = knownPrimes[primeI];
			primeN_hoch2 = knownPrimes_hoch2[primeI];
		}
		else {
			Console_writeLine__String8("SUPER !");
            Console_sync();
			Console_exit(1);
		}

		if (n == primeN) {
        	*minimalquotient = 1;
            *quotient = primeN;
            break;
        }
        if (n < primeN_hoch2) {
        	*minimalquotient = 1;
            break;
        }


        quotient1 = System_Math_divideRemain__UInt64(n, primeN, &remainder);

    	if ( remainder == 0 ) {
            *minimalquotient = primeN;
            *quotient = quotient1;
            goto FALSE;
        }

	}

    *minimalquotient = 1;
    return true;

FALSE:
	return false;
}

STRING8 text_n = " n";
STRING8 text_P = " P";

int main(int argc, char *argv[]) {
/* System_main(Eratosthenes,args) { */

	knownPrimes = (UInt64 *)Memory_allocArray(typeof(UInt64), sizeof_knownPrimes);
	knownPrimes_hoch2 = (UInt64 *)Memory_allocArray(typeof(UInt64), sizeof_knownPrimes);

	knownPrimes[1] = 2U; knownPrimes_hoch2[1] = 4U;
	knownPrimes[2] = 3U; knownPrimes_hoch2[2] = 9U;
	knownPrimes[3] = 5U; knownPrimes_hoch2[3] = 25U;
	knownPrimesL = 4U;

    System_Char8 nP[] = "n                    P                     \n";
    System_Char8 decimol[System_UInt64_String8base10Length_DEFAULT - 1] = { };

	UInt64 n = 5U;
	UInt64 minimalquotient = 0, quotient = 0; /* knownPrimesL_remainder = 0; */

    Size numbers;

	while (n > 3U) {

		n += 2U;
		if (Eratosthenes_IsPrime(n, &minimalquotient, &quotient)) {

			// THIS IS PRIME: n

			if (knownPrimesL < sizeof_knownPrimes) {
				knownPrimes[knownPrimesL++] = n;
				knownPrimes_hoch2[knownPrimesL] = n * n;
			}
            else knownPrimesL++;
			/* else {
    			Console_writeLine__String8("SUPER !");
                Console_sync();
				goto FALSE;
			} */

            numbers = System_UInt64_toString8base10__stack(knownPrimesL, decimol);
            System_String8_copySubstringTo(decimol, numbers, (nP + 1));

            numbers = System_UInt64_toString8base10__stack(n, decimol);
            System_String8_copySubstringTo(decimol, numbers, (nP + 22));

            Syscall_write(File_special_STDOUT, nP, sizeof(nP) - 1);
            // Console_write__String8_size(nP);
		}
		/* if (minimalquotient > 1 && n < 65538U) {
            Console_writeLine("       \t {0:uint} == {1:uint} · {2:uint}", 3, n, minimalquotient, quotient);
            Console_sync();
        } */

		n += 4U;
		if (Eratosthenes_IsPrime(n, &minimalquotient, &quotient)) {

			// THIS IS PRIME: n

			if (knownPrimesL < sizeof_knownPrimes) {
				knownPrimes[knownPrimesL++] = n;
				knownPrimes_hoch2[knownPrimesL] = n * n;
			}
            else knownPrimesL++;
			/* else {
    			Console_writeLine__String8("SUPER !");
                Console_sync();
				goto FALSE;
			} */

            numbers = System_UInt64_toString8base10__stack(knownPrimesL, decimol);
            System_String8_copySubstringTo(decimol, numbers, (nP + 1));

            numbers = System_UInt64_toString8base10__stack(n, decimol);
            System_String8_copySubstringTo(decimol, numbers, (nP + 22));

            Syscall_write(File_special_STDOUT, nP, sizeof(nP) - 1);
            // Console_write__String8_size(nP);
		}
		/* if (minimalquotient > 1 && n < 65538U) {
            Console_writeLine("       \t {0:uint} == {1:uint} · {2:uint}", 3, n, minimalquotient, quotient);
            Console_sync();
        } */
	}

    Memory_free(knownPrimes);
    Memory_free(knownPrimes_hoch2);

	return true;

FALSE:
    Memory_free(knownPrimes);
    Memory_free(knownPrimes_hoch2);

    return false;
}
