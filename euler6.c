#include "euler.h"
#include <math.h>

int main() {
	int sum_of_squares = 0;
	int square_of_sum = pow(101 * 50, 2);

	for (int i = 1; i <= 100; i++) {
		sum_of_squares += pow(i, 2);
	}

	printf("Square of sum:\t%d\n", square_of_sum);
	printf("Sum of squares:\t -%d\n", sum_of_squares);
	printf("Difference:\t%d\n", square_of_sum - sum_of_squares);
}


