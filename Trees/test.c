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
void levelorder(struct Node *root);
void create(int first , int second , int third);
void insert(int x);
void deleteNode(int x);
void display();


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
void levelorder(struct Node *ptr){
    if(ptr==NULL){
        return;
    }
    if(ptr==root){
        printf("%d ",ptr->value);
        printf("%d ",ptr->left->value);
        printf("%d ",ptr->right->value);
        levelorder(ptr->left);
        levelorder(ptr->right);
    }
    else{
        printf("%d ",ptr->left->value);
        printf("%d ",ptr->right->value);
        levelorder(ptr->left);
        levelorder(ptr->right);
    }

}
void create(int first , int second , int third){
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
               insert(second);
            }
            else{
            insert(third);
        }
    
    }
}
}

void deleteNode(int data) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;
    struct Node* parent = NULL;
    struct Node* nodeToDelete = NULL;

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
        return; 
    }

   
    if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
        if (parent == NULL) {
       
            free(root);
            root = NULL;
        } else if (parent->left == nodeToDelete) {
     
            free(parent->left);
            parent->left = NULL;
        } else {
           
            free(parent->right);
            parent->right = NULL;
        }
    }
   
    else if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) {
        struct Node* child = (nodeToDelete->left != NULL) ? nodeToDelete->left : nodeToDelete->right;
        
        if (parent == NULL) {
          
            free(root);
            root = child;
        } else if (parent->left == nodeToDelete) {
           
            free(parent->left);
            parent->left = child;
        } else {
            
            free(parent->right);
            parent->right = child;
        }
    }
   
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
    
           
}
void display(){
    printf("Inorder:");
    printInorder(root);
    printf("\n");
    printf("Preorder:");
    printPreorder(root);
    printf("\n");
    printf("Postorder:");
    printPostorder(root);
    printf("\n");
    printf("Levelorder:");
    levelorder(root);
    printf("\n");
    printf("\n");
}

int main() {
   create(8,3,10);
   display();
    insert(1);
    display();
    insert(6);
    display();
    insert(14);
    display();
    insert(4);
    display();
    insert(7);
    display();
    deleteNode(3);
    display();

    return 0;
}
