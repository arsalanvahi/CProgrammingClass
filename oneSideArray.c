//***************stack*********************************************
#include <stdio.h>

#define MAX_SIZE 5

struct Stack {
    int array[MAX_SIZE];
    int topIndex;
};

void initializeStack(struct Stack* stack) {
    stack->topIndex = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->topIndex < MAX_SIZE - 1) {
        stack->topIndex++;
        stack->array[stack->topIndex] = value;
    } else {
        printf("Stack is full, cannot push element\n");
    }
}

int pop(struct Stack* stack) {
    int poppedValue = -1; // Default value for an empty stack
    if (stack->topIndex >= 0) {
        poppedValue = stack->array[stack->topIndex];
        stack->topIndex--;
    } else {
        printf("Stack is empty, cannot pop element\n");
    }
    return poppedValue;
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack)); // Output: 3

    return 0;
}
//***************Queue**********************************************************
#include <stdio.h>

#define MAX_SIZE 5

struct Queue {
    int array[MAX_SIZE];
    int rearIndex;
};

void initializeQueue(struct Queue* queue) {
    queue->rearIndex = -1;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rearIndex < MAX_SIZE - 1) {
        queue->rearIndex++;
        queue->array[queue->rearIndex] = value;
    } else {
        printf("Queue is full, cannot enqueue element\n");
    }
}

int dequeue(struct Queue* queue) {
    int dequeuedValue = -1; // Default value for an empty queue
    if (queue->rearIndex >= 0) {
        dequeuedValue = queue->array[0];

        // Shift elements to the left to simulate dequeue
        for (int i = 1; i <= queue->rearIndex; i++) {
            queue->array[i - 1] = queue->array[i];
        }

        queue->rearIndex--;
    } else {
        printf("Queue is empty, cannot dequeue element\n");
    }
    return dequeuedValue;
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("%d\n", dequeue(&queue)); // Output: 1

    return 0;
}
//*****************************************************************************************************