#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct TwoStacksArray {
    int array[MAX_SIZE];
    int top1;
    int top2;
};

// Initialize two stacks in the array
void initialize(struct TwoStacksArray* stacks) {
    stacks->top1 = -1; // Initialize top of the first stack
    stacks->top2 = MAX_SIZE; // Initialize top of the second stack
}

// Push an element onto the first stack
void push1(struct TwoStacksArray* stacks, int item) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->top1++;
        stacks->array[stacks->top1] = item;
    } else {
        printf("Stack Overflow for Stack 1\n");
    }
}

// Push an element onto the second stack
void push2(struct TwoStacksArray* stacks, int item) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->top2--;
        stacks->array[stacks->top2] = item;
    } else {
        printf("Stack Overflow for Stack 2\n");
    }
}

// Pop an element from the first stack
int pop1(struct TwoStacksArray* stacks) {
    if (stacks->top1 >= 0) {
        int item = stacks->array[stacks->top1];
        stacks->top1--;
        return item;
    } else {
        printf("Stack Underflow for Stack 1\n");
        return -1; // Assuming -1 represents an error or an empty stack
    }
}

// Pop an element from the second stack
int pop2(struct TwoStacksArray* stacks) {
    if (stacks->top2 < MAX_SIZE) {
        int item = stacks->array[stacks->top2];
        stacks->top2++;
        return item;
    } else {
        printf("Stack Underflow for Stack 2\n");
        return -1; // Assuming -1 represents an error or an empty stack
    }
}

int main() {
    struct TwoStacksArray stacks;
    initialize(&stacks);

    push1(&stacks, 1);
    push1(&stacks, 2);
    push1(&stacks, 3);

    push2(&stacks, 4);
    push2(&stacks, 5);
    push2(&stacks, 6);

    printf("Popped from Stack 1: %d\n", pop1(&stacks)); // Output: Popped from Stack 1: 3
    printf("Popped from Stack 2: %d\n", pop2(&stacks)); // Output: Popped from Stack 2: 6

    return 0;
}
