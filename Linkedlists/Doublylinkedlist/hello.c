// DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Doubly_ll{
    int data;
    struct Doubly_ll* nxt;
    struct Doubly_ll* pre;
};
typedef struct Doubly_ll node;
node *head;

node* create(int x){
    node* new=(node*)malloc(sizeof(node));
    new->data=x;
    new->nxt=NULL;
    new->pre=NULL;
    return new;
}
void insertBegin(int x){
    node *new=create(x);
    if(head==NULL){
        head=new;
        return;
    }
    head->pre=new;
    new->nxt=head;
    head=new;
}
void insertEnd(int x){
    node *new=create(x);
    if(head==NULL){
        head=new;
        return;
    }
    node *p=head;
    while(p->nxt!=NULL)
        p=p->nxt;
    p->nxt=new;
    new->pre=p;
}
void insertByDataAfter(int x,int n){
    node *new=create(x);
    if(head==NULL){
        head=new;
        return;
    }
    node *p=head;
    while(p->data!=n)
        p=p->nxt;
    new->nxt=p->nxt;
    p->nxt=new;
    new->pre=p;
}
void insertByDataBefore(int x,int n){
    node *new=create(x);
    if(head==NULL){
        head=new;
        return;
    }
    node *p=head;
    while(p->data!=n)
        p=p->nxt;
    new->pre=p->pre;
    (p->pre)->nxt=new;
    p->pre=new;
    new->nxt=p;
}
void insertInBetween(int x,int a,int b){
    node *new=create(x);
    if(head==NULL){
        head=new;
        return;
    }
    node *p=head;
    while(p->data!=a && (p->nxt)->data!=b)
        p=p->nxt;
    node *temp=p->nxt;
    p->nxt=new;
    new->pre=p;
    temp->pre=new;
    new->nxt=temp;
}
void createList(int n){
    int t=1,i;
    for(i=1;i<=n;i++,t++)
       insertEnd(t);
}
void deleteBegin(){
    if(head==NULL)
        return;
    node *p=head;
    head=head->nxt;
    head->pre=NULL;
    free(p);
}
void deleteEnd(){
    if(head==NULL)
        return;
    node *p=head;
    while(p->nxt!=NULL)
        p=p->nxt;
    (p->pre)->nxt=NULL;
    free(p);
}
void delByDataAfter(int n){
    if(head==NULL)
        return;
    node *p=head;
    while(p->data!=n)
        p=p->nxt;
    node *temp=p->nxt;
    p->nxt=temp->nxt;
    (temp->nxt)->pre=p;
    free(temp);
} 
void delByDataBefore(int n){
    if(head==NULL)
        return;
    node *p=head;
    while(p->data!=n)
        p=p->nxt;
    node *temp=p->pre;
    (temp->pre)->nxt=p;
    p->pre=temp->pre;
    free(temp);
}
void delByData(int n){
   if(head==NULL)
        return;
    node *p=head;
    while(p->data!=n)
        p=p->nxt;
    (p->nxt)->pre=p->pre; 
    (p->pre)->nxt=p->nxt;
    free(p); 
} 
void display(){
    node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->nxt;
    }
    printf("\n");
}
int main(){
    head=NULL;
    head=create(5);
    createList(3);
    display();
    deleteBegin();
    display();
    deleteEnd();
    display();
    delByData(2);
    display();
    return 0;
}