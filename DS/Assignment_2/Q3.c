#include <stdio.h>
#include <stdlib.h>

int pthFactor(int n, int p) {
    int count = 0;
    int i;
    int *factors;

    // Allocate memory for the array of factors
    factors = (int *) malloc((n+1) * sizeof(int));

    // Generate the list of factors
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors[count] = i;
            count++;
        }
    }

    // Sort the list in ascending order
    for (i = 0; i < count - 1; i++) {
        int j = 0;
        int min = i;
        for (j = i + 1; j < count; j++) {
            if (factors[j] < factors[min]) {
                min = j;
            }
        }
        int temp = factors[i];
        factors[i] = factors[min];
        factors[min] = temp;
    }

    // If p is greater than the length of the list, return 0
    if (p > count) {
        free(factors);
        return 0;
    }

    // Return the p-th element of the list
    int result = factors[p-1];
    free(factors);
    return result;
}

int main() {
    int n = 20;
    int p = 3;
    printf("%d\n", pthFactor(n, p));  // Output: 4
    return 0;
}
