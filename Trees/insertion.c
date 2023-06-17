#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node node;
node *createtree(node *root, int *arr);
node *insert(node *ptr, int x);
node *createnode(node *ptr, int x);
void inorder(node *ptr);
void preorder(node *ptr);
void postorder(node *ptr);
void display(node *root);

int main(){
node *root=NULL;
    root=createnode(root,2);
    display(root);
    root=insert(root,1);
    display(root);
    root=insert(root,3);
    display(root);
    root=insert(root,5);
    display(root);

    return 0;
}
node *insert(node *ptr, int x){
    if(ptr==NULL){
        node *p=(node *)malloc(sizeof(node));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        ptr=p;
        return ptr;
    }else if(x<ptr->data){
        ptr->left=insert(ptr->left,x);
        return ptr;
    }
    else{
        ptr->right=insert(ptr->right,x);
        return ptr;
    }
}
node *createnode(node *ptr, int x){
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    ptr=p;
    return ptr;
}
// node *createtree(node *root, int *arr){
//     int n=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i<n; i++){
//         if(root==NULL){
//             node *p=(node *)malloc(sizeof(node));
//             p->data=arr[i];
//             p->left=NULL;
//             p->right=NULL;
//             root=p;
//         }
//         else{
//             if(arr[i]<root->data){
//                 root->left=insert(root->left,arr[i]);
//             }
//             else{
//                 root->right=insert(root->right,arr[i]);
//             }
//         }
//     }
//     return root;
// }
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