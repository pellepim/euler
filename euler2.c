#include<stdio.h>


/**
 * Step forward two steps in the fibonacci sequence.
 */
void stepFib(int * fib) {
	int fib1 = fib[0] + fib[1];
	int fib2 = fib[1] + fib1;

	fib[0] = fib1;
	fib[1] = fib2;
}

/**
 * Return the sum of all the current members of the fibonacci array
 * that are even.
 */
int localSum(int * fib) {
	int localSum = 0;
	if (fib[0] % 2 == 0) localSum += fib[0];
	if (fib[1] % 2 == 0) localSum += fib[1];

	return localSum;
}

/**
 * An array with two members will suffice.
 *
 * We start the array with the two given members 1 and two.
 *
 * As long as the second member has a value below 4000, we sum the members
 * add to our sum.
 *
 * Then we replace the members of the array with the next two fibonacci members,
 * and repeat the addition.
 */
int main() {
	int fib[2];
	int sum = 0;
	fib[0] = 1;
	fib[1] = 2;

	while (fib[1] < 4000000) {
		sum += localSum(fib);
		stepFib(fib);
	}

	printf("%d\n", sum);

}
