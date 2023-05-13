#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;
node *head=NULL;
void createnode(int x);
void deletebeg();
void deleteend();
void deleteany(int x);
void deletebef(int befvalue);
void deleteafter(int aftvalue);
void display();


int main(){

    createnode(8);
    createnode(7);
    createnode(6);
    createnode(5);
    createnode(4);
    createnode(3);
    createnode(2);
    createnode(1);
     display();
    deletebeg();
     //display(head);
    deleteend();
     //display(head);
    deleteany(5);
     //display(head);
    deleteafter(4);
    //display(head);
    deletebef(4);
    //display(head);
    

    return 0;
}
void display(){
    node *ptr=(node *)malloc(sizeof(node));
    ptr=head;
    while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
    printf("\n");
}
void deletebeg(){
    node *p=head;
    head=head->next;
    free(p);
    display(head);
}
void deleteend(){
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
    
}
void deleteany(int x){
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
}
void deleteafter( int aftvalue){
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
}
void deletebef( int befvalue){
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
}
void createnode(int x){
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=head;
    head=new;
}