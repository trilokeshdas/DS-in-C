#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
typedef struct node node;

 node* head = NULL;

// Function to create a new node
//void createNode(int x); for creating a particular node 
void createlist(int size); // for creating a list of nodes. it takes actually the number updto which the list is to be created
void insertbeg(int x);
void insertend(int x);
void insertatmid(int prevvalue,int nextvaalue,int value);
void insertbef( int befvalue,int value);
void insertafter(int aftvalue, int value);
void display();

int main(){
    
    // createNode(3);
    // createNode(2);
    // createNode(1);
    // display();
    createlist(3);
    insertbeg(4);
    //display();
    insertend(5);
    //display();
    insertatmid(2,3,6);
    //display();
    insertbef(1,7);
    //display();
    insertafter(3,8);
   // display();
    

    return 0;
}
void display(){
    node *ptr=head;
    while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
    printf("\n");
}
void insertatmid(int prevvalue,int nextvalue, int x){
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
    p->next=p2;
    p1->next=p;
    display();
    
    
}
void insertbeg(int x){
    node *ptr=( node*)malloc(sizeof( node));
    ptr->data=x;
    ptr->next=head;
    head=ptr;
    display();
    
}
void insertend(int x){
    node *ptr=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    ptr=head;
    p->data=x;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->next=NULL;
    display();
   
}
void insertbef(int befvalue, int value){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p1=head;
    p2=head->next;
    p->data=value;
    while(p2->data!=befvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display();
 
}
void insertafter( int aftvalue,int value){
    node *p1=( node*)malloc(sizeof( node));
    node *p2=( node*)malloc(sizeof( node));
    node *p=( node*)malloc(sizeof( node));
    p->data=value;
    p1=head;
    p2=head->next;
    while(p1->data!=aftvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display();
    
}
// void createNode(int x) {
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->data = x;
//     newNode->next = head;
//     head=newNode;
// }
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