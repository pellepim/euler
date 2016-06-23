#include "euler.h"
#include "vector.h"
#include <time.h>
#include <math.h>

/**
 * Tests whether a long int `candidate` is in fact a prime number.
 */
bool is_prime(long int n) {
	long int limit = sqrt(n);

	if (n == 2) { // 2 is a prime
		return true;
	}

	if (n % 2 == 0) {  // 2 Is also the only even prime
		return false;
	}

	for (long int i = 3; i <= limit; i += 2) { // Lets limit our search to odds from 3
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

/**
 * Does prime factorization of subject `n` and puts the resulting factors
 * in the `factors` vector.
 */
void factorize(long int n, Vector *factors) {
	long int remainder = n;
	long int limit = (n / 2) + 1;
	long int candidate = 3;
	int primeFactorIndex = 0;
	while (remainder % 2 == 0) {
		vector_set(factors, primeFactorIndex++, 2);
		remainder = (long int)remainder / 2;
	}

	if (remainder == 1) return;

	while (candidate <= limit) {
		if (remainder % candidate == 0) {
			if (is_prime(candidate)) {
				vector_set(factors, primeFactorIndex++, candidate);
				remainder = (long int)remainder / (long int) candidate;
			}
		} else {
			candidate += 2;
		}

		if (remainder == 1) return;
	}
}
