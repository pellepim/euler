#ifndef EULER
#define EULER

#include "vector.h"
#include <stdio.h>

typedef enum { false, true } bool;

bool is_prime(long int n);

void factorize(long int n, Vector *factors);

void primes_in(long int n, Vector *primes);

void generate_primes(long int n, Vector *primes);

#endif
