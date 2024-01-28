#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for the double stack
typedef struct {
    int array[MAX_SIZE];
    int top1;  // Top of the first stack
    int top2;  // Top of the second stack
} DoubleStack;

// Function to initialize the double stack
void initialize(DoubleStack *ds) {
    ds->top1 = -1;
    ds->top2 = MAX_SIZE;
}

// Function to check if the first stack is empty
int isEmpty1(DoubleStack *ds) {
    return ds->top1 == -1;
}

// Function to check if the second stack is empty
int isEmpty2(DoubleStack *ds) {
    return ds->top2 == MAX_SIZE;
}

// Function to check if the double stack is full
int isFull(DoubleStack *ds) {
    return ds->top1 + 1 == ds->top2;
}

// Function to push an element onto the first stack
void push1(DoubleStack *ds, int value) {
    if (!isFull(ds)) {
        ds->array[++ds->top1] = value;
    } else {
        printf("Stack Overflow in Stack 1\n");
    }
}

// Function to push an element onto the second stack
void push2(DoubleStack *ds, int value) {
    if (!isFull(ds)) {
        ds->array[--ds->top2] = value;
    } else {
        printf("Stack Overflow in Stack 2\n");
    }
}

// Function to pop an element from the first stack
int pop1(DoubleStack *ds) {
    if (!isEmpty1(ds)) {
        return ds->array[ds->top1--];
    } else {
        printf("Stack 1 Underflow\n");
        return -1;  // Assuming -1 represents an error value
    }
}

// Function to pop an element from the second stack
int pop2(DoubleStack *ds) {
    if (!isEmpty2(ds)) {
        return ds->array[ds->top2++];
    } else {
        printf("Stack 2 Underflow\n");
        return -1;  // Assuming -1 represents an error value
    }
}

// Additional functions or operations can be added based on specific requirements

