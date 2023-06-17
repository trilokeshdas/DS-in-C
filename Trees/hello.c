#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;
void printInorder(struct Node* root);
void printPreorder(struct Node *root);
void printPostorder(struct Node *root);
void createTree(int first , int second , int third);
void insert(int x);
void deleteNode(int x);


void insert(int value) {
    if (root == NULL) {
         struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    root=newNode;
    }

    struct Node* currentNode = root;
    while (1) {
        if (value < currentNode->value) {
            if (currentNode->left == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                 newNode->value = value;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->left = newNode;
                break;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
               newNode->value = value;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->right = newNode;
                break;
            }
            currentNode = currentNode->right;
        }
    }
    printf("Inorder:");
    printInorder(root);
    printf("\n");
     printf("Preorder:");
            printPreorder(root);
            printf("\n");
            printf("Postorder:");
            printPostorder(root);
            printf("\n");
            printf("\n");
 
}

void printInorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}
void printPreorder(struct Node *ptr){
    if (ptr==NULL){
      return;
    }
    
    printf("%d ",ptr->value);
    printPreorder(ptr->left);
    printPreorder(ptr->right);
}
void printPostorder(struct Node *ptr){
    if(ptr==NULL){
        return;
    }
    printPostorder(ptr->left);
    printPostorder(ptr->right);
    printf("%d ",ptr->value);
}
void createTree(int first , int second , int third){
    for (int i = 0; i < 3; i++)
    {
        if (root==NULL)
        {
           struct Node *new=(struct Node*)malloc(sizeof(struct Node));
           new->value=first;
           new->left=NULL;
           new->right=NULL;
           root=new;
        }
        else
        {
            if(i==2){
                struct Node* currentNode = root;
    while (1) {
        if (second < currentNode->value) {
            if (currentNode->left == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                 newNode->value = second;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->left = newNode;
                break;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
               newNode->value = second;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->right = newNode;
                break;
            }
            currentNode = currentNode->right;
        }
    }
                
            }
            else{
                struct Node* currentNode = root;
    while (1) {
        if (third < currentNode->value) {
            if (currentNode->left == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                 newNode->value = third;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->left = newNode;
                break;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
               newNode->value = third;
                 newNode->left = NULL;
                 newNode->right = NULL;
                currentNode->right = newNode;
                break;
            }
            currentNode = currentNode->right;
        }
    }
            }
            
        }
        
        
 }
            printf("Inorder:");
            printInorder(root);
            printf("\n");
            printf("Preorder:");
            printPreorder(root);
            printf("\n");
            printf("Postorder:");
            printPostorder(root);
            printf("\n");
            printf("\n");
            

}
// Function to delete a node from the binary search tree

// Function to delete a node from the binary search tree
void deleteNode(int data) {
    if (root == NULL) {
        return; // Empty tree, nothing to delete
    }

    struct Node* current = root;
    struct Node* parent = NULL;
    struct Node* nodeToDelete = NULL;

    // Find the node to delete
    while (current != NULL) {
        if (data == current->value) {
            nodeToDelete = current;
            break;
        } else if (data < current->value) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }

    if (nodeToDelete == NULL) {
        return; // Node not found, nothing to delete
    }

    // Case 1: Node to delete has no children
    if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
        if (parent == NULL) {
            // Deleting the root node
            free(root);
            root = NULL;
        } else if (parent->left == nodeToDelete) {
            // Deleting a left child
            free(parent->left);
            parent->left = NULL;
        } else {  
            // Deleting a right child
            free(parent->right);
            parent->right = NULL;
        }
    }
    // Case 2: Node to delete has one child
    else if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) {
        struct Node* child = (nodeToDelete->left != NULL) ? nodeToDelete->left : nodeToDelete->right;
        
        if (parent == NULL) {
            // Deleting the root node
            free(root);
            root = child;
        } else if (parent->left == nodeToDelete) {
            // Deleting a left child
            free(parent->left);
            parent->left = child;
        } else {
            // Deleting a right child
            free(parent->right);
            parent->right = child;
        }
    }
    // Case 3: Node to delete has two children
    else {
        struct Node* successorParent = nodeToDelete;
        struct Node* successor = nodeToDelete->right;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != nodeToDelete) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        nodeToDelete->value = successor->value;
        free(successor);
    }
    
            printf("Inorder:");
            printInorder(root);
            printf("\n");
            printf("Preorder:");
            printPreorder(root);
            printf("\n");
            printf("Postorder:");
            printPostorder(root);
            printf("\n");
            printf("\n");
}



int main() {
   createTree(63,16,76);
    insert(36);
    deleteNode(16);

    return 0;
}
