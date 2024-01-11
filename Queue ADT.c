#include <stdlib.h>

// Node structure to represent elements in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
    size_t size; // Number of elements in the queue
} Queue;

// Function to initialize an empty queue
Queue* initializeQueue();

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue);

// Function to enqueue an element to the back of the queue
void enqueue(Queue* queue, int data);

// Function to dequeue an element from the front of the queue
int dequeue(Queue* queue);

// Function to get the size of the queue
size_t getQueueSize(Queue* queue);

// Function to free the memory allocated for the queue
void freeQueue(Queue* queue);

// Function to display the elements of the queue (optional)
void displayQueue(Queue* queue);

// Implementation of the functions

Queue* initializeQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    newQueue->front = newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

int isQueueEmpty(Queue* queue) {
    return (queue == NULL || queue->size == 0);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        // Handle underflow (empty queue)
        return -1; // Assuming -1 is not a valid element in the queue
    }

    Node* frontNode = queue->front;
    int data = frontNode->data;

    if (queue->front == queue->rear) {
        // The queue has only one element
        queue->front = queue->rear = NULL;
    } else {
        queue->front = frontNode->next;
    }

    free(frontNode);
    queue->size--;

    return data;
}

size_t getQueueSize(Queue* queue) {
    return (queue == NULL) ? 0 : queue->size;
}

void freeQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
