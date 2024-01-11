#include <stdio.h>
#include <stdlib.h>

// Element in the Stack
typedef struct StackElement {
    int data; // Example: integer data
    // Other data members if needed
} StackElement;

// Stack structure
typedef struct Stack {
    StackElement* array; // Array to store elements
    int top;             // Index of the top element in the stack
    int capacity;        // Maximum capacity of the stack
} Stack;

// Function to initialize the stack
Stack* initializeStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (StackElement*)malloc(capacity * sizeof(StackElement));
    stack->top = -1; // Initialize an empty stack
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top].data = data;    //because the array is a type of stackelement, accessing an element of this, needs to use . to access data
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return an error value (assuming -1 is not a valid element)
    }
    return stack->array[stack->top--].data;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value (assuming -1 is not a valid element)
    }
    return stack->array[stack->top].data;
}

// Function to display the elements of the stack
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->array[i].data);
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main() {
    // Example usage of the stack
    Stack* stack = initializeStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    displayStack(stack);

    printf("Top element: %d\n", peek(stack));

    pop(stack);

    displayStack(stack);

    freeStack(stack);

    return 0;
}
