#include <stdlib.h>
#include "euler.h"
#include <math.h>
#include <unistd.h>

/**
 * log10 of i gives exponential, converting exponential to int and
 * adding 1 gives number of digits. Unless i = 0 in which case we have
 * ONE digit.
 */
unsigned count_digits (unsigned i) {
	if (i > 0) {
		return (int) log10 ((double) i) + 1;
	}
	return 1;
}

/**
 * Construct one forward and one backward array, each containing every
 * digit in the original candidate in opposite orders.
 *
 * If the two arrays are identical, we have a "palindrome" number.
 */
bool is_palindrome(int candidate) {
	int digit_count = (int)count_digits((unsigned)candidate);
	int remainder = candidate;
	int backward[digit_count];
	int forward[digit_count];
	int backward_result = 0;

	for (int i = 0; i < digit_count; i++) {
		backward[i] = remainder % 10;
		remainder = remainder / 10;
		forward[digit_count-i-1] = backward[i];
	}

	for (int i = 0; i <= (digit_count / 2) ; i++) {
		if (forward[i] != backward[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	int max_palindrome = 0;
	int factor1, factor2;
	int product;
	for (int i = 900; i < 1000; i++) {
		for (int j = 999; j >= 900; j--) {
			product = i*j;
			if (is_palindrome(i*j) && product >= max_palindrome) {
				max_palindrome = product;
				factor1 = i, factor2 = j;
			}
		}
	}

	printf("Max palindrome: %d. From products: %d * %d.\n", max_palindrome, factor1, factor2);
}
