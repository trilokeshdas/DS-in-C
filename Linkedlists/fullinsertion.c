#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;
node *createnode(node *head, int value);
node *insertbeg(node *head,int x);
node *insertend(node *head,int x);
node *insertatmid(node *head,int prevvalue,int nextvalue, int x);
node *insertbef(node *head, int befvvalue,int x);
node *insertafter(node *head,int aftvalue, int x);
void display(struct node *ptr);


int main(){
     node *head=(node *)malloc(sizeof(node));
     head=NULL;
    head=createnode(head,3);
    head=createnode(head,2);
    head=createnode(head,1);
    display(head);
    head=insertbeg(head,4);
    //display(head);
    head=insertend(head,5);
    //display(head);
    head=insertatmid(head,2,3,6);
    //display(head);
    head=insertbef(head,1,7);
    //display(head);
    head=insertafter(head,3,8);
    //display(head);
    

    return 0;
}
void display(node *ptr){
    while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
    printf("\n");
}
node *insertatmid(node *head,int prevvalue,int nextvalue, int x){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p->data=x;
    p1=head;
    p2=head->next;
    while(p1->data!=prevvalue && p2->data!=nextvalue){
        p1=p1->next;
        p2=p2->next;
        
    }
    p1->next=p;
    p->next=p2;
    display(head);
     return head;
}
node *insertbeg(node *head,int x){
    node *ptr=( node*)malloc(sizeof( node));
    ptr->data=x;
    ptr->next=head;
    head=ptr;
    display(head);
    return head;
}
node *insertend(node *head,int x){
    node *ptr=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    ptr=head;
    p->data=x;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->next=NULL;
    display(head);
    return head;
}
node *insertbef(node *head,int befvalue,int x){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    p->data=x;
    while(p2->data!=befvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display(head);
    return head;
}
node *insertafter(node *head,int aftvalue, int x){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p->data=x;
    p1=head;
    p2=head->next;
    while(p1->data!=aftvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display(head);
     return head;
}
node *createnode(node *head, int value){
    node *new=(node *)malloc(sizeof(node));
    new->data=value;
    new->next=head;
    head=new;
    return head;
}