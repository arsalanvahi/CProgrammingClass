#include <stdio.h>

#define MAX_DIGITS 1000

void multiply(int result[], int* result_size, int multiplier);

void factorial(int n);

int main() {
    int n = 3;
    

    factorial(n);

    return 0;
}

void multiply(int result[], int* result_size, int multiplier) {
    int carry = 0;

    for (int i = 0; i < *result_size; i++) {
        int product = result[i] * multiplier + carry;

        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        result[*result_size] = carry % 10;
        carry = carry / 10;
        (*result_size)++;
    }
}

void factorial(int n) {
    int result[MAX_DIGITS] = { 0 };
    result[0] = 1;
    int result_size = 1;

    for (int i = 2; i <= n; i++) {
        multiply(result, &result_size, i);
    }

    printf("Factorial of %d is: ", n);
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }

    printf("\n");
}
