#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node node;
void createnode( int x);
node *insert(node *ptr, int x);
void inorder(node *ptr);
void preorder(node *ptr);
void postorder(node *ptr);
void display();

node *root=NULL;
int main(){
    createnode(1);
    insert(root,2);
    display();
    insert(root,0);
    display();
    insert(root,3);
    display();

    return 0;
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
void createnode( int x){
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    root=p;
  display();
    
}
node *insert(node *ptr, int x){
    if(ptr==NULL){
     node *p=(node *)malloc(sizeof(node));
     p->data=x;
     p->left=NULL;
     p->right=NULL;
     ptr=p;
     return ptr;
    }
    else{
        if(x<ptr->data){
            ptr->left=insert(ptr->left,x);
        }
        else{
            ptr->right=insert(ptr->right,x);
        }
    }
    
}