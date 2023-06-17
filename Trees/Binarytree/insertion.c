#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node node;
node *create(node *ptr);
void inorder(node *ptr);
void preorder(node *ptr);
void postorder(node *ptr);
void display(node *root);
int main(){
    node *root=NULL;
    root=create(root);
    display(root);
    root=create(root);
    display(root);
    
    return 0;
}
// node *create(){
//     node *newnode=(node *)malloc(sizeof(node));
//     int x;
//     printf("enter the value of the node:");
//     scanf("%d",&x);
//     if(x==-1){
//         return NULL;
//     }
//     newnode->data=x;
//     printf("enter the left child node of %d",x);
//     newnode->left=create();
//     printf("enter the right child of %d",x);
//     newnode->right=create();
//     return newnode;
// }




node *create(node *ptr){
    if(ptr==NULL){
        int x;
        node *newnode=(node *)malloc(sizeof(node));
        printf("enter the value of the node:");
        scanf("%d",&x);
        if(x==-1){
            return NULL;
        }
        newnode->data=x;
        newnode->left=NULL;
        newnode->right=NULL;
        ptr=newnode;
    }
    printf("enter the value of left child of %d:",ptr->data);
    ptr->left=create(ptr->left);
    printf("enter the value of right child of %d:",ptr->data);
    ptr->right=create(ptr->right);
    return ptr;
}
void inorder(node *ptr){
    if(ptr==NULL){
        return;
    }
    inorder(ptr->left);
    printf("%d ",ptr->data);
    inorder(ptr->right);
}
void preorder(node *ptr){
    if(ptr==NULL){
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void postorder(node *ptr){
    if(ptr==NULL){
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ",ptr->data);
}
void display(node *root){
    printf("Inorder:");
    inorder(root);
    printf("\n");
    printf("Preorder:");
    preorder(root);
    printf("\n");
    printf("Postorder:");
    postorder(root);
    printf("\n");
    printf("\n");
}