#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
typedef struct node node;
void createtree(int *a, int size);
void inorder(node *ptr);
void preorder(node *ptr);
void postorder(node *ptr);
void conversion(int *a, int size);
void display();
node *root=NULL;
int main(){
    int a[]={10,5,1,7,40,50};
    int n=sizeof(a)/sizeof(a[0]);
    conversion(a,n);
    
    return  0;
}
void createtree(int *a, int n){
    for(int i=0; i<n; i++){
        if(root==NULL){
            node *newnode=(node *)malloc(sizeof(node));
            newnode->data=a[i];
            newnode->left=NULL;
            newnode->right=NULL;
            root=newnode;
        }
        else{
            node *currentnode=(node *)malloc(sizeof(node));
            currentnode=root;
            while(1){
                if(a[i]<currentnode->data){
                    if(currentnode->left==NULL){
                        node *newnode=(node *)malloc(sizeof(node));
                        newnode->data=a[i];
                        newnode->left=NULL;
                        newnode->right=NULL;
                        currentnode->left=newnode;
                        break;
                    }
                    currentnode=currentnode->left;
                }
                else{
                    if(currentnode->right==NULL){
                        node *newnode=(node *)malloc(sizeof(node));
                        newnode->data=a[i];
                        newnode->left=NULL;
                        newnode->right=NULL;
                        currentnode->right=newnode;
                        break;
                    }
                    currentnode=currentnode->right;
                }
            }
        }
    }
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
void display(){
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
void conversion(int *a, int n){
    createtree(a,n);
    printf("Inorder:");
    inorder(root);
    printf("\n");
    printf("Postorder:");
    postorder(root);
    printf("\n");
    printf("Preorder:");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}