/* #include <math.h>
#include <stdio.h> */

#define using_System
#include <min/System.h>

const __size sizeof_knownPrimes = 0x7FFFFFU;

__private __uint64 * knownPrimes;
__private __uint64 * knownPrimes_hoch2;

__private __size knownPrimesL = 0U;

__bool Eratosthenes_IsPrime(__uint64 n, __uint64 * minimalquotient, __uint64 * quotient) {

	__uint64 primeI = 2, primeN = 3, primeN_hoch2 = 9, quotient1 = 0, remainder = 0;

    /* __uint64 div2 = System_Math_divideRemain(n, 2, &remainder); */

	while (0U < ++primeI) {
		/* now primeI => [ 3 ] == 5 */

		if (primeI < sizeof_knownPrimes) {
			primeN = knownPrimes[primeI];
			primeN_hoch2 = knownPrimes_hoch2[primeI];
		}
		else {
			__Console_writeLine__string8("SUPER !");
            __Console_sync();
			__Console_exit(1);
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
    return __true;

FALSE:
	return __false;
}

struct_string text_n = " n";
struct_string text_P = " P";

int main(int argc, char *argv[]) {
/* System_main(Eratosthenes,args) { */

	knownPrimes = (__uint64 *)__Memory_alloc(sizeof(__uint64) * sizeof_knownPrimes);
	knownPrimes_hoch2 = (__uint64 *)__Memory_alloc(sizeof(__uint64) * sizeof_knownPrimes);

	knownPrimes[1] = 2U; knownPrimes_hoch2[1] = 4U;
	knownPrimes[2] = 3U; knownPrimes_hoch2[2] = 9U;
	knownPrimes[3] = 5U; knownPrimes_hoch2[3] = 25U;
	knownPrimesL = 4U;

    __char8 nP[] = "n                    P                     \n";
    __char8 decimal[System_uint64_string8base10Length_DEFAULT - 1] = { };

	__uint64 n = 5U;
	__uint64 minimalquotient = 0, quotient = 0; /* knownPrimesL_remainder = 0; */

    __size numbers;

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
    			__Console_writeLine__string8("SUPER !");
                __Console_sync();
				goto FALSE;
			} */

            numbers = System_uint64_tostring8base10__stack(knownPrimesL, decimal);
            System_string8_copySubstringTo(decimal, numbers, (nP + 1));

            numbers = System_uint64_tostring8base10__stack(n, decimal);
            System_string8_copySubstringTo(decimal, numbers, (nP + 22));

            __Syscall_write(__File_special_STDOUT, nP, sizeof(nP) - 1);
            // __Console_write__string8(nP);
		}
		/* if (minimalquotient > 1 && n < 65538U) {
            __Console_writeLine("       \t {0:uint} == {1:uint} · {2:uint}", 3, n, minimalquotient, quotient);
            __Console_sync();
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
    			__Console_writeLine__string8("SUPER !");
                __Console_sync();
				goto FALSE;
			} */

            numbers = System_uint64_tostring8base10__stack(knownPrimesL, decimal);
            System_string8_copySubstringTo(decimal, numbers, (nP + 1));

            numbers = System_uint64_tostring8base10__stack(n, decimal);
            System_string8_copySubstringTo(decimal, numbers, (nP + 22));

            __Syscall_write(__File_special_STDOUT, nP, sizeof(nP) - 1);
            // __Console_write__string8(nP);
		}
		/* if (minimalquotient > 1 && n < 65538U) {
            __Console_writeLine("       \t {0:uint} == {1:uint} · {2:uint}", 3, n, minimalquotient, quotient);
            __Console_sync();
        } */
	}

    __Memory_freeStruct(knownPrimes);
    __Memory_freeStruct(knownPrimes_hoch2);

	return __true;

FALSE:
    __Memory_freeStruct(knownPrimes);
    __Memory_freeStruct(knownPrimes_hoch2);

    return __false;
}
