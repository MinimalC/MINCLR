#define using_System
#include <min/System.h>

const size sizeof_knownPrimes = 0x7FFFFFU;

internal uint64 * knownPrimes;
internal uint64 * knownPrimes_hoch2;

internal size knownPrimesL = 0U;

bool Eratosthenes_IsPrime(uint64 n, uint64 * minimalquotient, uint64 * quotient) {

	uint64 primeI = 2, primeN = 3, primeN_hoch2 = 9, quotient1 = 0, remainder = 0;

    /* uint64 div2 = System_Math_divideRemain(n, 2, &remainder); */

	while (0U < ++primeI) {
		/* now primeI => [ 3 ] == 5 */

		if (primeI < sizeof_knownPrimes) {
			primeN = knownPrimes[primeI];
			primeN_hoch2 = knownPrimes_hoch2[primeI];
		}
		else {
			Console_writeLine__string8("SUPER !");
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


        quotient1 = System_Math_divideRemain__uint64(n, primeN, &remainder);

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

	knownPrimes = (uint64 *)Memory_alloc(sizeof(uint64) * sizeof_knownPrimes);
	knownPrimes_hoch2 = (uint64 *)Memory_alloc(sizeof(uint64) * sizeof_knownPrimes);

	knownPrimes[1] = 2U; knownPrimes_hoch2[1] = 4U;
	knownPrimes[2] = 3U; knownPrimes_hoch2[2] = 9U;
	knownPrimes[3] = 5U; knownPrimes_hoch2[3] = 25U;
	knownPrimesL = 4U;

    System_char8 nP[] = "n                    P                     \n";
    System_char8 decimol[System_uint64_string8base10Length_DEFAULT - 1] = { };

	uint64 n = 5U;
	uint64 minimalquotient = 0, quotient = 0; /* knownPrimesL_remainder = 0; */

    size numbers;

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
    			Console_writeLine__string8("SUPER !");
                Console_sync();
				goto FALSE;
			} */

            numbers = System_uint64_tostring8base10__stack(knownPrimesL, decimol);
            System_string8_copySubstringTo(decimol, numbers, (nP + 1));

            numbers = System_uint64_tostring8base10__stack(n, decimol);
            System_string8_copySubstringTo(decimol, numbers, (nP + 22));

            Syscall_write(File_special_STDOUT, nP, sizeof(nP) - 1);
            // Console_write__string8(nP);
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
    			Console_writeLine__string8("SUPER !");
                Console_sync();
				goto FALSE;
			} */

            numbers = System_uint64_tostring8base10__stack(knownPrimesL, decimol);
            System_string8_copySubstringTo(decimol, numbers, (nP + 1));

            numbers = System_uint64_tostring8base10__stack(n, decimol);
            System_string8_copySubstringTo(decimol, numbers, (nP + 22));

            Syscall_write(File_special_STDOUT, nP, sizeof(nP) - 1);
            // Console_write__string8(nP);
		}
		/* if (minimalquotient > 1 && n < 65538U) {
            Console_writeLine("       \t {0:uint} == {1:uint} · {2:uint}", 3, n, minimalquotient, quotient);
            Console_sync();
        } */
	}

    Memory_freeStruct(knownPrimes);
    Memory_freeStruct(knownPrimes_hoch2);

	return true;

FALSE:
    Memory_freeStruct(knownPrimes);
    Memory_freeStruct(knownPrimes_hoch2);

    return false;
}
