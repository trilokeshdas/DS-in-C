#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;
node *head=NULL;
void createnode(int x);
void createlist(int size);
void deletebeg();
void deleteend();
void deleteany(int x);
void deletebef(int befvalue);
void deleteafter(int aftvalue);
void display();


int main(){

    // createnode(8);
    // createnode(7);
    // createnode(6);
    // createnode(5);
    // createnode(4);
    // createnode(3);
    // createnode(2);
    // createnode(1);
    // display();
    createlist(8);
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
    display();
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
    display();
    
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
    display();
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
    display();
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
    display();
}
void createnode(int x){
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=head;
    head=new;
}
void createlist(int size){
    int x=1;
    for(int i=0; i<size; i++){
        if(head==NULL){
            node *newnode=(node *)malloc(sizeof(node));
            newnode->data=x;
            newnode->next=head;
            head=newnode;
        }
        else{
          node *p1=(node *)malloc(sizeof(node));   //basically this is insertion at end code segment but we are not
    node *p=(node *)malloc(sizeof(node));          // calling it in this function because after calling createlist in the main
    p1=head;                                       // main function it will display multiple times bacause display 
    p->data=x;                                   // function is called in insertion end function
    while(p1->next!=NULL){
        p1=p1->next;
    }
    p1->next=p;
    p->next=NULL;
    }
        x++;
    }
    display();
}