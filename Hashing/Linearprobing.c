#include <stdio.h>

#define SIZE 10 

int hashFunction(int key) {
    return key % SIZE; 
}

void insert(int hashTable[], int key) {
    int index = hashFunction(key); 
    
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; 
    }
    
    hashTable[index] = key;
}

void search(int hashTable[], int key) {
    int index = hashFunction(key); 
    
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE; 
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

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
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
