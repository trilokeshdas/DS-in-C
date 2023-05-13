#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;
node *createnode(node *head, int x);
node *deletebeg(node *head);
node *deleteend(node *head);
node *deleteany(node *head, int x);
node *deletebef(node *head, int befvalue);
node *deleteafter(node *head, int aftvalue);
void display( node *ptr);


int main(){
     node *head=NULL;
    head=createnode(head,8);
    head=createnode(head,7);
    head=createnode(head,6);
    head=createnode(head,5);
    head=createnode(head,4);
    head=createnode(head,3);
    head=createnode(head,2);
    head=createnode(head,1);
     display(head);
    head=deletebeg(head);
     //display(head);
    head=deleteend(head);
     //display(head);
    head=deleteany(head,5);
     //display(head);
    head=deleteafter(head,4);
    //display(head);
    head=deletebef(head,4);
    //display(head);
    

    return 0;
}
void display(node *ptr){
    while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;
    }
    printf("\n");
}
node *deletebeg(node *head){
    node *p=head;
    head=head->next;
    free(p);
    display(head);
    return head;
}
node *deleteend(node *head){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    while(p2->next!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=NULL;
    free(p2);
    display(head);
    return head;
}
node *deleteany(node *head,int x){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    while(p2->data!=x){
        p1=p1->next;
        p2=p2->next;
    }
    p=p2->next;
    p1->next=p;
    free(p2);
    display(head);
    return head;
}
node *deleteafter(node *head, int aftvalue){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    while(p1->data!=aftvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p=p2->next;
    p1->next=p;
    free(p2);
    display(head);
    return head;
}
node *deletebef(node *head, int befvalue){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    while(p2->next->data!=befvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p2->next;
    free(p2);
    display(head);
    return head;
}
node *createnode(node *head, int x){
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=head;
    head=new;
    return head;
}