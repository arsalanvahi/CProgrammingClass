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
//the idea is as follows :
//First, every number is written inversely. example 24 is 42
//second, every product is done this way example:
//carry = 0
// 42 *
// 5
//-------------------------------------
// (4*5 + carry )  (5*2)+carry) 
// and write them in array[*result_size] and update result_size whenever we have the last carry
//Also result_size controls how many numbers are going to be multiplied.  



