#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define the circular queue structure
struct CircularQueue {
    int* array;
    int front;
    int rear;
    int size;
};

// Function to create a new circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* cq = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    cq->array = (int*)malloc(sizeof(int) * MAX_SIZE);
    cq->front = cq->rear = -1;
    cq->size = 0;
    return cq;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->size == 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return cq->size == MAX_SIZE;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Circular queue is full. Cannot enqueue more elements.\n");
        return;
    }

    if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % MAX_SIZE;
    }

    cq->array[cq->rear] = value;
    cq->size++;
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty. Cannot dequeue an element.\n");
        return -1; // Return an error value
    }

    int value = cq->array[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    cq->size--;

    return value;
}

// Function to get the front element of the circular queue without dequeuing
int peek(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty. No element to peek.\n");
        return -1; // Return an error value
    }
    return cq->array[cq->front];
}

int main() {
    struct CircularQueue* cq = createCircularQueue();

    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);

    printf("Front element: %d\n", peek(cq));

    printf("Dequeued: %d\n", dequeue(cq));
    printf("Dequeued: %d\n", dequeue(cq));

    enqueue(cq, 40);
    enqueue(cq, 50);

    printf("Front element: %d\n", peek(cq));

    while (!isEmpty(cq)) {
        printf("Dequeued: %d\n", dequeue(cq));
    }

    return 0;
}
