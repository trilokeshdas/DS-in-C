#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;
node *insertatmid(node *head, int x);
void display(struct node *ptr);


int main(){
     node* head; // struct node* type pointer structure to allocate memory in the heap
     node* second;
     node* third;
     node* fourth;
    //ALLOCATION
    head=( node*)malloc(sizeof( node)); //typecasting to struct node type
    second=( node*)malloc(sizeof( node));
    third=( node*)malloc(sizeof(node));
    fourth=( node*)malloc(sizeof(node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL; //termination of the linked lists
    head=insertatmid(head,6);
 display(head);
    

    return 0;
}
void display(node *ptr){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}
node *insertatmid(node *head, int x){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p->data=x;
    p1=head;
    p2=head->next;
    while(p1->data!=2){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
     return head;
}