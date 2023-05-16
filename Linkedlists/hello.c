#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
   struct node *next;
};
typedef struct node node;
node *head=NULL;
void createlist(int n);
void insertbeg(int x);
void insertend(int x);
void insertmid(int prevvalue , int nextvalue, int x);
void insertbef(int befvalue, int x);
void insertaft(int aftvalue, int x);
void display();

int main(){
    createlist(3);
    insertbeg(4);
    insertend(5);
    insertmid(2,3,6);
    insertbef(1,7);
    insertaft(3,8);
    return 0;
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
          node *p1=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p->data=x;
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
void insertbeg(int x){
        node *p=(node *)malloc(sizeof(node));
        p->data=x;
        p->next=head;
        head=p;
        display();
}
void insertend(int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p->data=x;
    while(p1->next!=NULL){
        p1=p1->next;
    }
    p1->next=p;
    p->next=NULL;
    display();
}
void insertmid(int prevvalue, int nextvalue, int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p2=head->next;
    p->data=x;
    while(p1->data!=prevvalue && p2->data!=nextvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p->next=p2;
    p1->next=p;
    display();
}
void insertbef(int befvalue, int x){
     node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p2=head->next;
    p->data=x;
    while(p2->data!=befvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display();
}
void insertaft(int aftvalue, int x){
      node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p2=head->next;
    p->data=x;
    while(p1->data!=aftvalue){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=p;
    p->next=p2;
    display();
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