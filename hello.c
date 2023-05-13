#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Globally declared head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtStart(int newData) {
    struct Node* newNode = createNode(newData);

    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int newData) {
    struct Node* newNode = createNode(newData);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a node between two nodes in the linked list
void insertBetween(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(newData);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node before a given node in the linked list
void insertBefore(int key, int newData) {
    struct Node* newNode = createNode(newData);

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    // Search for the key in the linked list
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key was not found
    if (current == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    // If the key is found at the head node
    if (prev == NULL) {
        newNode->next = current;
        head = newNode;
        return;
    }

    prev->next = newNode;
    newNode->next = current;
}

// Function to insert a node after a given node in the linked list
// Function to insert a node after a given data value in the linked list
void insertAfter(int prevData, int newData) {
    struct Node* newNode = createNode(newData);

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    // Search for the previous data value in the linked list
    while (current != NULL && current->data != prevData) {
        current = current->next;
    }

    // If the previous data value was not found
    if (current == NULL) {
        printf("Previous data value not found in the list.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
// Function to display the linked list
void displayList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insertAtStart(3);
    insertAtStart(2);
    insertAtStart(1);
    displayList();

    // Insert 4 at the start
    insertAtStart(4);
 displayList();
    // Insert 5 at the end
    insertAtEnd(5);
     displayList();

    // Insert 6 between 2 and 3
    insertBetween(head->next->next, 6);
 displayList();

 insertBefore(1, 7);
  displayList();

  insertAfter(3,8);
  displayList();
    // Insert
}