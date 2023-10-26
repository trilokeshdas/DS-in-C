#include <stdio.h>

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == key) {
            return mid; // Key found at the middle index
        }

        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
        } else {
            return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = { 2, 7,  9, 12, 13, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 13;

    // Recursive binary search
    int indexRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    if (indexRecursive != -1) {
        printf("Key %d found at index %d using recursive binary search.\n", key, indexRecursive);
    } else {
        printf("Key %d not found using recursive binary search.\n", key);
    }

    return 0;
}