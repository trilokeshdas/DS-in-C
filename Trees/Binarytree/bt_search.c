#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node node;
node *create(node *ptr);
node *bt_search(node *ptr,int x);
int main(){
    node *root=NULL;
    root=create(root);
    int x=25;
    bt_search(root,x);
    return 0;
}
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
node *bt_search(node *ptr, int x){
    if(ptr==NULL){
        return NULL;
    }
    if(ptr->data==x){
        printf("%d is found",x);
    }
    else{
        bt_search(ptr->left,x);
        bt_search(ptr->right,x);
    }
}
