#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum level of the skip list
#define MAX_LEVEL 16

// Define the skip list node structure
struct SkipListNode {
    int key;
    int value;
    struct SkipListNode* forward[MAX_LEVEL];
};

// Define the skip list structure
struct SkipList {
    int level;
    struct SkipListNode* header;
};

// Function to create a new skip list node
struct SkipListNode* createSkipListNode(int key, int value, int level) {
    struct SkipListNode* newNode = (struct SkipListNode*)malloc(sizeof(struct SkipListNode));
    newNode->key = key;
    newNode->value = value;
    for (int i = 0; i < level; i++) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

// Function to create a new skip list
struct SkipList* createSkipList() {
    struct SkipList* skipList = (struct SkipList*)malloc(sizeof(struct SkipList));
    skipList->level = 1;
    skipList->header = createSkipListNode(INT_MIN, 0, MAX_LEVEL);
    for (int i = 0; i < MAX_LEVEL; i++) {
        skipList->header->forward[i] = NULL;
    }
    return skipList;
}

// Function to generate a random level for a new node
int randomLevel() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Function to insert a node into the skip list
void insert(struct SkipList* skipList, int key, int value) {
    struct SkipListNode* update[MAX_LEVEL];
    struct SkipListNode* current = skipList->header;
    
    for (int i = skipList->level - 1; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0];
    if (current == NULL || current->key != key) {
        int newLevel = randomLevel();
        if (newLevel > skipList->level) {
            for (int i = skipList->level; i < newLevel; i++) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }
        
        struct SkipListNode* newNode = createSkipListNode(key, value, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Function to search for a node with a given key
int search(struct SkipList* skipList, int key) {
    struct SkipListNode* current = skipList->header;
    
    for (int i = skipList->level - 1; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    
    current = current->forward[0];
    if (current != NULL && current->key == key) {
        return current->value;
    } else {
        return -1; // Key not found
    }
}

// Function to print the skip list
void printSkipList(struct SkipList* skipList) {
    for (int level = skipList->level - 1; level >= 0; level--) {
        struct SkipListNode* current = skipList->header->forward[level];
        printf("Level %d: ", level);
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->forward[level];
        }
        printf("\n");
    }
}

int main() {
    struct SkipList* skipList = createSkipList();
    
    insert(skipList, 10, 100);
    insert(skipList, 20, 200);
    insert(skipList, 30, 300);
    
    printf("Skip List after insertions:\n");
    printSkipList(skipList);
    
    int value = search(skipList, 20);
    if (value != -1) {
        printf("Value for key 20: %d\n", value);
    } else {
        printf("Key not found\n");
    }
    
    return 0;
}
