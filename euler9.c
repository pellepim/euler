#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main() {
    int a;
    int comparisons = 0;
    for (int c = 500; c >= 334; c--) {
        a = 0;
        
        for (int b = 1000 - c - 1; b > a >= 1; b--) {
            a = 1000 - c - b;
            comparisons++;
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