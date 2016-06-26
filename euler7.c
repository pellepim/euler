#include "euler.h"

int main() {
	int prime_candidate = 3;  // Let's start with three
	int nth_prime = 2; // which is the second prime

	while (nth_prime < 10001) {
		prime_candidate += 2;
		if (is_prime(prime_candidate)) {
			nth_prime++;
		}
	}

	printf("%d is the 10001th prime\n", prime_candidate);
}
