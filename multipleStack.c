#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for multiple stacks
typedef struct {
    int array[MAX_SIZE];
    int* tops;   // Array to store top indices for each stack
    int numStacks;  // Number of stacks
} MultiStack;

// Function to initialize multiple stacks
void initialize(MultiStack* ms, int numStacks) {
    ms->tops = (int*)malloc(numStacks * sizeof(int));
    ms->numStacks = numStacks;

    // Initialize tops for each stack
    for (int i = 0; i < numStacks; ++i) {
        ms->tops[i] = i * (MAX_SIZE / numStacks) - 1;
    }
}

// Function to check if a specific stack is full
int isFull(MultiStack* ms, int stackNumber) {
    int nextIndex = (stackNumber + 1) * (MAX_SIZE / ms->numStacks) - 1;
    return ms->tops[stackNumber] == nextIndex;
}

// Function to check if a specific stack is empty
int isEmpty(MultiStack* ms, int stackNumber) {
    int startIndex = stackNumber * (MAX_SIZE / ms->numStacks);
    return ms->tops[stackNumber] == startIndex - 1;
}

// Function to push an element onto a specific stack
void push(MultiStack* ms, int stackNumber, int value) {
    if (!isFull(ms, stackNumber)) {
        ms->array[++ms->tops[stackNumber]] = value;
    } else {
        printf("Stack %d Overflow\n", stackNumber + 1);
    }
}

// Function to pop an element from a specific stack
int pop(MultiStack* ms, int stackNumber) {
    if (!isEmpty(ms, stackNumber)) {
        return ms->array[ms->tops[stackNumber]--];
    } else {
        printf("Stack %d Underflow\n", stackNumber + 1);
        return -1;  // Assuming -1 represents an error value
    }
}

// Function to free memory used by multiple stacks
void destroy(MultiStack* ms) {
    free(ms->tops);
}

// Example usage:
int main() {
    MultiStack ms;
    initialize(&ms, 3);  // Create three stacks

    push(&ms, 0, 1);
    push(&ms, 1, 2);
    push(&ms, 2, 3);

    printf("Popped from Stack 1: %d\n", pop(&ms, 0));
    printf("Popped from Stack 2: %d\n", pop(&ms, 1));
    printf("Popped from Stack 3: %d\n", pop(&ms, 2));

    destroy(&ms);  // Free memory

    return 0;
}
