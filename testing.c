#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   
    int data;
    struct node* lchild;
    struct node* rchild;

}node;
node* create(node* root,int data)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node*));
        root->data=data;
        root->lchild=root->rchild=NULL;
    }
    else if(data<root->data)
    root->lchild=create(root->lchild,data);
     else 
    root->rchild=create(root->rchild,data);
    return root;
}

void inorder(node* p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
         printf("%d  ",p->data );
        inorder(p->rchild);
    }
}
void postorder(node* p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d  ",p->data );
    }
}
void preorder(node* p)
{  
    if(p!=NULL)
    {   printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int leaf(node* p)
{
  if(p!=NULL)
  {
     int x=leaf(p->lchild);
     int y=leaf(p->rchild);
     return x+y+1;
  }
}
int sumofnodes(node* p)
{
  if(p!=NULL)
  {
     int x=sumofnodes(p->lchild);
     int y=sumofnodes(p->rchild);
     return x+y+(p->data);
  }
  return 0;
}
int height(node* p)
{
    if(p!=NULL)
    {
        int x=height(p->lchild);
        int y=height(p->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
    }
}
int degree1(node* p)
{
    if(p!=NULL)
    {
        int x=degree1(p->lchild);
        int y=degree1(p->rchild);
        if(p->lchild && p->rchild==NULL || p->lchild==NULL && p->rchild)
        return x+y+1;
        else
        return x+y;
    }
}
int degree2(node* p)
{
    if(p!=NULL)
    {
        int x=degree1(p->lchild);
        int y=degree1(p->rchild);
        if(p->lchild && p->rchild)
        return x+y+1;
        else
        return x+y;
    }
}
int main()
{
    node* root=NULL;
    root=create(root,20);
    root=create(root,40);
    root=create(root,10);
    root=create(root,1);
    root=create(root,25);
    root=create(root,5);
     printf("\npreorder traversal\n");
    preorder(root);
    printf("\npostorder traversal\n");
    postorder(root);
    printf("\ninorder traversal\n");
    inorder(root);
    printf("\n%d  degree 0 leaf nodes\n",leaf(root));
    printf("%d sum of data of nodes\n",sumofnodes(root));
    printf("%d height of tree\n",height(root));
    printf("%d degree one nodes of tree\n",degree1(root));
    printf("%d degree two nodes of tree\n",degree2(root));
}