#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}; typedef struct node node;
void insert(int x);
void createtree(int *a, int size);
void inorder(node *ptr);
void preorder(node *ptr);
void postorder(node *ptr);
void display();
void delete(int x);
node *root=NULL;
int main(){
    int a[]={63,16,76};
    int n=sizeof(a)/sizeof(a[0]);
    createtree(a,n);
    insert(36);
    delete(16);


    return 0;
}
void insert(int x){
    if(root==NULL){
        node *newnode=(node *)malloc(sizeof(node));
        newnode->data=x;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }
    else{
        node *currentnode=(node *)malloc(sizeof(node));
        currentnode=root;
        while(1){
            if(x<currentnode->data){
                if(currentnode->left==NULL){
                     node *newnode=(node *)malloc(sizeof(node));
                     newnode->data=x;
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
                     newnode->data=x;
                     newnode->left=NULL;
                     newnode->right=NULL;
                     currentnode->right=newnode;
                     break;
                }
                currentnode=currentnode->right;
            }
        }
    }
    display();
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
    display();
}
void delete(int x){
    if(root==NULL){
        printf("No node to be deleted");
    }
    node *current=root;
    node *parent=NULL;
    node *nodetodelete=NULL;
    while(current!=NULL){
    if(current->data==x){
        nodetodelete=current;
        break;
    }
    else if(x<current->data){
        parent=current;
        current=current->left;
    }
    else{
        parent=current;
        current=current->right;
    }
  }
  if(nodetodelete==NULL){
    printf("No node found to delete");
  }
  //if node to delete has no child
  if(nodetodelete->left==NULL && nodetodelete->right==NULL){
    if(parent==NULL){
        free(root);
        root=NULL;
    }
    else if(parent->left==nodetodelete){
        free(parent->left);
        parent->left=NULL;
    }
    else{
        free(parent->right);
        parent->right=NULL;
    }
  }
//if node to delete has one child
  else if(nodetodelete->left==NULL || nodetodelete->right==NULL){
   node *child=(nodetodelete->left!=NULL) ? nodetodelete->left : nodetodelete->right;
   if(parent==NULL){
    free(root);
    root=child;
   }
   else if(parent->left==nodetodelete){
    free(parent->left);
    parent->left=child;
   }
   else{
    free(parent->right);
    parent->right=child;
   }
  }
//if node to delete has 2 child
 else{
    node *successorparent=nodetodelete;
    node *successor=nodetodelete->right;

    while(successor->left!=NULL){
        successorparent=successor;
        successor=successor->left;
    }
    if(successorparent!=nodetodelete){
        successorparent->left=successor->right;
    }
    else{
        successorparent->right=successor->right;
    }
    nodetodelete->data=successor->data;
    free(successor);
 }
 display();
}