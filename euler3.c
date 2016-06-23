#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "vector.h"
#include "euler.h"


long int biggest_prime_factor(long int n) {
	if (is_prime(n)) {
		printf("%ld is a prime number!\n", n);
		return n;

	}

	Vector primes;
	vector_init(&primes);

	factorize(n, &primes);
	printf("Prime factors: [");
	for (int i = 0; i < primes.size; i++) {
		printf("%d", primes.data[i]);
		if (i < primes.size - 1) {
			printf(", ");
		}
	}
	printf("]\n\n");
	return vector_get(&primes, primes.size-1);

}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Please provide an integer for prime factorization\n");
		return 0;
	}
	char *ptr;
	long int subject = strtol(argv[1], &ptr, 10);

	printf("%ld\n", biggest_prime_factor(subject));

}
