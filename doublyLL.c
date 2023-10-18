#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global pointer to the head of the list
struct Node* head = NULL;

// Function to insert a node at the front of the list
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Function to insert a node at the middle of the list
void insertMiddle(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        // List is empty, insert at the front
        insertFront(value);
        return;
    }

    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (position == 1) {
        // Insert at the front
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (current->next == NULL) {
        // Insert at the end
        newNode->prev = current;
        newNode->next = NULL;
        current->next = newNode;
    } else {
        // Insert in the middle
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Function to insert a node at the end of the list
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        // List is empty, insert at the front
        insertFront(value);
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    newNode->prev = current;
    current->next = newNode;
}

// Function to delete a node from the front of the list
void deleteFront() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the front.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the middle of the list
void deleteMiddle(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return;
    }

    if (position == 1) {
        deleteFront();
        return;
    }

    struct Node* current = head;
    int count = 1;
    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of range. Cannot delete from the middle.\n");
        return;
    }

    if (current->next == NULL) {
        current->prev->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
}

// Function to delete a node from the end of the list
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(current);
}

// Function to print the list
void printList() {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insertFront(10);
    insertFront(20);
    insertFront(30);
    printList();

    insertMiddle(15, 2);
    printList();

    insertEnd(40);
    insertEnd(50);
    printList();

    deleteFront();
    printList();

    deleteMiddle(2);
    printList();

    deleteEnd();
    printList();

    return 0;
}
