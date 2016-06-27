#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 Problem 9:
 A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 
 a^2 + b^2 = c^2
 For example, 32 + 42 = 9 + 16 = 25 = 52.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 
 Find the product abc.
 
 Solution: 
 Lets try to find some boundries to the problem first, in order to make it slightly
 less "brute-forceish".
 
 The given constraints are the a < b < c and that a + b + c = 1000.
 
 HYPOTHESIS 1: c <= 500.
 PROOF: Assume that c > 500. That would mean that a + b < 500, for each given b
 it would have to hold that b > a and a >= 1 in order for the original constraints to hold.
 Assuming the lowest possible value for a (1) gives that the maximum possible value for b
 is 499. Therefore it is impossible for c to be larger than 500.
 
 HYPOTHESIS 2: c >= 334
 PROOF: Assume that c < 334. Then it would have to hold that a + b = 666. Assuming the lowest
 possible value for a (1) would mean that b would have to be 665, invalidating the given
 constaint of c > b. To find the minimum possible value of c that leaves enough "space" for
 b to be larger than a while still being lower than c i 666/2 + 1. E.g 334.
 
 These two proofs are represented below as c_upper_boundry and c_lower_boundry
 */
int main() {
    int a;
    int comparisons = 0;
    int c_upper_boundry = 500;
    int c_lower_boundry = 334;
    
    // While c is between 500 and 334, counting downwards
    for (int c = c_upper_boundry; c >= c_lower_boundry; c--) {
        a = 0;
        
        // For every possible value of b between 1000 - c - 1, that is still higher
        // than a which in turn is at least 1, count downwards
        for (int b = 1000 - c - 1; b > a >= 1; b--) {
            a = 1000 - c - b; // What is a for current b and c?
            comparisons++;
            
            // Do we have a pytagorean triplet? Then we win.
            if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                printf("%d + %d + %d = %d\n", a, b, c, a+b+c);
                printf("and\n");
                printf("%d^2 + %d^2 = %.0f + %.0f = %.0f = %d^2\n",
                       a, b, pow(a, 2), pow(b, 2), pow(c, 2), c);
                printf("and\n");
                printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
                printf("Calculated with %d comparisons\n", comparisons);
                exit(0);
            }
        }
    }
}