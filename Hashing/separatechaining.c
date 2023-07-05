#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node* hashTable[], int key) {
    int index = key % SIZE;
    struct Node* newNode = createNode(key);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(struct Node* hashTable[], int key) {
    int index = key % SIZE;
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("Key %d not found in the hash table\n", key);
}

void displayHashTable(struct Node* hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d:", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf(" %d", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* hashTable[SIZE];

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(hashTable, 10);
    insert(hashTable, 70);
    insert(hashTable, 32);
    insert(hashTable, 73);
    insert(hashTable, 26);
    insert(hashTable, 52);
    insert(hashTable, 88);
    insert(hashTable, 12);

    displayHashTable(hashTable);


    return 0;
}