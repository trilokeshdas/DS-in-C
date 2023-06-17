#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
typedef struct node node;
void createtree(int *a, int size);
 node *bst_search(node *ptr,int x);
node *root=NULL;


int main(){
    int a[]={63,16,76};
    int n=sizeof(a)/sizeof(a[0]);
    createtree(a,n);
    int x=16;
    if(bst_search(root,x)!=NULL){
        printf("%d is found",x);
    }
    else{
        printf("%d is not found",x);
    }
    return 0;
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
//RECURSSIVE SEARCH
node *bst_search(node *ptr,int x){
    if(ptr==NULL){
        return NULL;
    }
    if(ptr->data==x){
        return ptr;
    }
    else if(x<ptr->data){
       return  bst_search(ptr->left,x);
    }
    else{
        return bst_search(ptr->right,x);
    }
}
//Without recurssive search
// node *bst_search(int x){
//     node *current=root;
//     while(current!=NULL){
//         if(current->data==x){
//             return current;
//         }
//         else if(x<current->data){
//             current=current->left;
//         }
//         else{
//             current=current->right;
//         }
//     }
//     if(current==NULL){
//         return NULL;
//     }
// }