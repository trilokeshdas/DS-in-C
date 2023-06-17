#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

void preorderTraverse(node *ptr){
    if (ptr==NULL)
      return;
    
    printf(" %d",ptr->data);
    preorderTraverse(ptr->left);
    preorderTraverse(ptr->right);
}

void inorderTraverse(node *ptr){
    if (ptr==NULL)
      return;

    inorderTraverse(ptr->left);
    printf(" %d",ptr->data);
    inorderTraverse(ptr->right);
}

void postorderTraverse(node *ptr){
    if (ptr==NULL)
      return;

    postorderTraverse(ptr->left);
    postorderTraverse(ptr->right);
    printf(" %d",ptr->data);
}

node* bst_createNode(int x){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;
    root = ptr;
    return root;
}

void createNode(node *ptr , int x){
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    ptr = p;
    printf("\nInorder : ");
    inorderTraverse(root);
    printf("\nPreorder : ");
    preorderTraverse(root);
    printf("\nPostorder : ");
    postorderTraverse(root);
    printf("\n");
}

node* bst_insert(node *ptr, int x){
    if(ptr == NULL)
    return bst_createNode(x);

    else if (x < ptr->data)
    ptr->left = bst_insert(ptr->left,x);
    
    else
    ptr->right = bst_insert(ptr->right,x);
}

void insert(node *ptr, int x){
    root = bst_insert(ptr,x);
    printf("\nInorder : ");
    inorderTraverse(ptr);
    printf("\nPreorder : ");
    preorderTraverse(ptr);
    printf("\nPostorder : ");
    postorderTraverse(ptr);
    printf("\n");
}


node* minValueNode(node *ptr){
    node* curr = ptr;
    while (curr!=NULL && curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node* bst_delete(node *ptr ,int x){
    if(ptr == NULL){
        ptr = root;
        return ptr;
    }
    if(ptr->data<x){
        ptr->right = bst_delete(ptr->right ,x);
    }
    else if(ptr->data>x){
        ptr->left = bst_delete(ptr->left,x);
    }
    else
    {
        if(ptr->left==NULL){
            node *temp = ptr->right;
            free(ptr);
            return temp;
        }

        if (ptr->right==NULL)
        {
            node *temp = ptr->left;
            free(ptr);
            return temp;
        }
        node *temp = minValueNode(ptr->right);
        ptr->data = temp->data;
        ptr->right = bst_delete(ptr->right ,temp->data);
    }
    return ptr;
}

void delete(node *ptr ,int x){
    if (ptr == NULL)
    {
        printf("\nCannot delete anything further.Empty!\n");
        exit(1);
    }
    
    root = bst_delete(ptr,x);
    printf("\nInorder : ");
    inorderTraverse(ptr);
    printf("\nPreorder : ");
    preorderTraverse(ptr);
    printf("\nPostorder : ");
    postorderTraverse(ptr);
    printf("\n");
}

void createTree(int first , int second , int third){
    int x = 1;
    for (int i = 0; i < 3; i++)
    {
        if (root==NULL)
        {
            root = bst_createNode(first);
        }
        else
        {
            switch (x)
            {
                case 2 : root = bst_insert(root,second);
                break;
            
                case 3 : root = bst_insert(root,third);
                break;
            }
            
        }
        
        x++;
    }
    printf("\nInorder : ");
    inorderTraverse(root);
    printf("\nPreorder : ");
    preorderTraverse(root);
    printf("\nPostorder : ");
    postorderTraverse(root);
    printf("\n");
}

int main(){
createTree(63,16,76);
insert(root,36);
delete(root,16);
return 0;
}