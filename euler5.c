#include <stdio.h>
#include "euler.h"

int main() {
	long int candidate = 20;
	while (true) {
		bool done = true;
		for (int i = 1; i <= 20; i++) {
			if (candidate % i != 0) {
				done = false;
				break;
			}
		}

		if (done) {
			break;
		} else {
			candidate += 20;
		}
	}

	printf("%ld\n", candidate);
}
