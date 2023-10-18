#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Initialize the head pointer

// Function to insert a node at the front of the circular linked list
void insertAtFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode; // Point to itself to form a circular list
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
}

// Function to insert a node at the middle of the circular linked list
void insertAtMiddle(int data) {
    if (head == NULL) {
        insertAtFront(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    newNode->next = slow->next;
    slow->next = newNode;
}

// Function to delete a node from the front of the circular linked list
void deleteFromFront() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head->next;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head;
        free(head);
        head = current;
    }
}

// Function to print the circular linked list
void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head->next);

    printf("...\n");
}

int main() {
    // Example usage
    insertAtFront(10);
    insertAtFront(5);
    insertAtEnd(20);
    insertAtMiddle(15);
    printList();

    deleteFromFront();
    deleteFromEnd();
    deleteFromEnd();
    printList();

    return 0;
}
