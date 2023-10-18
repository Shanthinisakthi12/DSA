#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define the deque structure
struct Deque {
    int* array;
    int front;
    int rear;
    int size;
};

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->array = (int*)malloc(sizeof(int) * MAX_SIZE);
    dq->front = dq->rear = -1;
    dq->size = 0;
    return dq;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* dq) {
    return dq->size == 0;
}

// Function to check if the deque is full
int isFull(struct Deque* dq) {
    return dq->size == MAX_SIZE;
}

// Function to add an element to the front of the deque
void insertFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert more elements.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->array[dq->front] = value;
    dq->size++;
}

// Function to add an element to the rear of the deque
void insertRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert more elements.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->array[dq->rear] = value;
    dq->size++;
}

// Function to remove an element from the front of the deque
int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete an element.\n");
        return -1; // Return an error value
    }

    int value = dq->array[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    dq->size--;

    return value;
}

// Function to remove an element from the rear of the deque
int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete an element.\n");
        return -1; // Return an error value
    }

    int value = dq->array[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->size--;

    return value;
}

int main() {
    struct Deque* dq = createDeque();

    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);

    printf("Front element: %d\n", deleteFront(dq));
    printf("Rear element: %d\n", deleteRear(dq));

    insertRear(dq, 30);
    insertFront(dq, 15);

    printf("Front element: %d\n", deleteFront(dq));
    printf("Rear element: %d\n", deleteRear(dq));

    return 0;
}
