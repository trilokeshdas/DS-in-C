//Circular singly ll
#include<stdio.h>
#include<stdlib.h>
struct Circular_SLL{
    int data;
    struct Circular_SLL *nxt;
};
typedef struct Circular_SLL node;
node *head;

node *create(int x){
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->nxt=new;
}
void insertBegin(int x){
    node *new=create(x);
    if(head->nxt==NULL){
        head=new;
        new->nxt=head;
        return;
    }
    node *p1=head->nxt;
    while(p1->nxt!=head)
        p1=p1->nxt;
    p1->nxt=new;
    new->nxt=head;
    head=new;
}
void insertEnd(int x){
    node* new=create(x);
    if(head->nxt==NULL){
        head=new;
        new->nxt=head;
        return;
    }
    node *p1=head;
    while(p1->nxt!=head)
        p1=p1->nxt;
    p1->nxt=new;
    new->nxt=head;
}
void createlist(int n){
    int i;
    for(i=1;i<=n;i++)
        insertEnd(i);
}
void delBegin(){
    node *p1=head;
    node *temp=head;
    while(p1->nxt!=head)
        p1=p1->nxt;
    head=head->nxt;
    p1->nxt=head;
    free(temp);
}
void delEnd(){
    node *p=head;
    node *temp;
    while(p->nxt->nxt!=head)
        p=p->nxt;
    temp=p->nxt;
    p->nxt=head;
    free(temp);
}
void display(){
    node* p=head;
    do{
        printf("%d ",p->data);
        p=p->nxt; 
    }while(p!=head);
    printf("--%d ",p->data);
    printf("\n");
}
int main(){
    // beg_insert(11);
    head=create(10);
    createlist(5);
    // head=(node*)malloc(sizeof(node));
    // node first=(node)malloc(sizeof(node));
    // node second=(node)malloc(sizeof(node));
    // node third=(node)malloc(sizeof(node));
    // head->data=10;
    // first->data=20;
    // second->data=30;
    // third->data=50;
    // head->nxt=first;
    // first->nxt=second;
    // second->nxt=third;
    // third->nxt=head;
    display();
    insertBegin(11);
    display();
    insertEnd(12);
    display();
    // delBegin();
    delEnd();
    display();
    
    return 0;
}