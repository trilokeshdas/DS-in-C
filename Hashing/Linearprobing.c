#include <stdio.h>

#define SIZE 10 // Size of the hash table

int hashFunction(int key) {
    return key % SIZE; // Simple modulo hashing
}

void insert(int hashTable[], int key) {
    int index = hashFunction(key); // Get the index using the hash function
    
    // Linear probing to handle collisions
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; // Move to the next index
    }
    
    hashTable[index] = key; // Insert the key into the hash table
}

void search(int hashTable[], int key) {
    int index = hashFunction(key); // Get the index using the hash function
    
    // Linear probing to handle collisions
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE; // Move to the next index
    }
    
    printf("Key %d not found in the hash table\n", key);
}

void displayHashTable(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[SIZE];

    // Initialize the hash table with -1 (indicating empty slot)
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    insert(hashTable, 12);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 45);
    insert(hashTable, 55);
    
    displayHashTable(hashTable);
    
    search(hashTable, 35);
    search(hashTable, 40);
    
    return 0;
}