#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

void initDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->items[deque->front] = item;
}

void insertRear(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->items[deque->rear] = item;
}

int removeFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedItem = deque->items[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return removedItem;
}

int removeRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove.\n");
        return -1;
    }

    int removedItem = deque->items[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return removedItem;
}

int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->items[deque->front];
}

int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    return deque->items[deque->rear];
}

int main() {
    struct Deque myDeque;
    initDeque(&myDeque);

    insertFront(&myDeque, 10);
    insertRear(&myDeque, 20);
    insertFront(&myDeque, 5);

    printf("Front element: %d\n", getFront(&myDeque));
    printf("Rear element: %d\n", getRear(&myDeque));

    removeFront(&myDeque);

    printf("After removing front element, new front: %d\n", getFront(&myDeque));

    return 0;
}
