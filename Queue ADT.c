#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
typedef struct {
    int elements[MAX_SIZE];
    int front;
    int rear;
    size_t size;
} Queue;

// Function to initialize an empty queue
Queue* initializeQueue();

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue);

// Function to check if the queue is full
int isQueueFull(Queue* queue);

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
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = 0;
    return newQueue;
}

int isQueueEmpty(Queue* queue) {
    return (queue == NULL || queue->size == 0);
}

int isQueueFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
}

void enqueue(Queue* queue, int data) {
    if (isQueueFull(queue)) {
        // Handle overflow (full queue)
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0; // Set front for the first element
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular queue
    queue->elements[queue->rear] = data;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        // Handle underflow (empty queue)
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }

    int data = queue->elements[queue->front];
    
    if (queue->front == queue->rear) {
        // The queue has only one element
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Circular queue
    }

    queue->size--;

    return data;
}

size_t getQueueSize(Queue* queue) {
    return (queue == NULL) ? 0 : queue->size;
}

void freeQueue(Queue* queue) {
    free(queue);
}

void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    do {
        printf("%d ", queue->elements[i]);
        i = (i + 1) % MAX_SIZE; // Circular queue
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    Queue* myQueue = initializeQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    displayQueue(myQueue); // Output: 10 20 30

    printf("Dequeued element: %d\n", dequeue(myQueue)); // Output: Dequeued element: 10

    displayQueue(myQueue); // Output: 20 30

    freeQueue(myQueue);

    return 0;
}


//********************************************************************** linked list ***********************
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
