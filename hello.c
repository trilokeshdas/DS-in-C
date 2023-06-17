#include <stdio.h>

// Iterative Linear Search
int linearSearchIterative(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Recursive Linear Search
int linearSearchRecursive(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1; // Base case: key not found
    }
    if (arr[start] == key) {
        return start; // Key found at current index
    }
    return linearSearchRecursive(arr, start + 1, end, key); // Recursively search in the remaining array
}

int main() {
    int arr[] = { 2, 7,  9, 12, 13, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 13;

    // Iterative linear search
    int indexIterative = linearSearchIterative(arr, n, key);
    if (indexIterative != -1) {
        printf("Key %d found at index %d using iterative linear search.\n", key, indexIterative);
    } else {
        printf("Key %d not found using iterative linear search.\n", key);
    }

    // Recursive linear search
    int indexRecursive = linearSearchRecursive(arr, 0, n - 1, key);
    if (indexRecursive != -1) {
        printf("Key %d found at index %d using recursive linear search.\n", key, indexRecursive);
    } else {
        printf("Key %d not found using recursive linear search.\n", key);
    }

    return 0;
}