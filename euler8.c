#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "euler.h"

unsigned count_digits (unsigned i) {
	if (i > 0) {
		return (int) log10 ((double) i) + 1;
	}
	return 1;
}


void convert_to_array(char huge_number[], int *digit_array[]) {

}

const char * huge_number[] = {
	"73167176531330624919225119674426574742355349194934",
	"96983520312774506326239578318016984801869478851843",
	"85861560789112949495459501737958331952853208805511",
	"12540698747158523863050715693290963295227443043557",
	"66896648950445244523161731856403098711121722383113",
	"62229893423380308135336276614282806444486645238749",
	"30358907296290491560440772390713810515859307960866",
	"70172427121883998797908792274921901699720888093776",
	"65727333001053367881220235421809751254540594752243",
	"52584907711670556013604839586446706324415722155397",
	"53697817977846174064955149290862569321978468622482",
	"83972241375657056057490261407972968652414535100474",
	"82166370484403199890008895243450658541227588666881",
	"16427171479924442928230863465674813919123162824586",
	"17866458359124566529476545682848912883142607690042",
	"24219022671055626321111109370544217506941658960408",
	"07198403850962455444362981230987879927244284909188",
	"84580156166097919133875499200524063689912560717606",
	"05886116467109405077541002256983155200055935729725",
	"71636269561882670428252483600823257530420752963450"
};

#define number_parts (sizeof (huge_number) / sizeof (const char *))

/**
 * Takes the array of numbers
 */
int move_and_multiply(int number_array[], int *current_index) {

	long int current_product = 1;
	for (int i = 0; i < 13; i++) {
		current_product *= number_array[*current_index+i];
		if (current_product == 0) {
			*current_index += i + 1;
			return 0;
		}
	}
	++*current_index;
	return current_product;
}

void print_result(long int max_product, int max_product_at_index, int number_array[]) {
	printf("Maximum product: %ld\n", max_product);
	printf("As given by factors: ");
	for (int i = 0; i < 13; i++) {
		printf("%d", number_array[max_product_at_index + i]);
		if (i < 12) {
			printf("x");
		}
	}
	printf("\n");
}

int main() {
	int number_array[1000];
	int number_index = 0;

	// Lets start with building an actual array of all the digits in the huge number

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			number_array[number_index++] = digit_to_int(huge_number[i][j]);
		}

	}

	long int max_product = 0;
	int max_product_at_index = 0;
	int current_index = 0;
	long int current_product;

		// Lets start at each point in the array, up to 13 from the end
	while (current_index < 1000 - 13) {
		current_product = move_and_multiply(number_array, &current_index);

		if (current_product > max_product) {
			max_product = current_product;
			max_product_at_index = current_index - 1;
		}
	}

	print_result(max_product, max_product_at_index, number_array);
}
