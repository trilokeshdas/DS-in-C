#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void createlist(int size);
void display();
void insertbeg(int x);
void insertend(int x);
void insertbetween(int prevval,int nextval, int x);

int main(){
    createlist(4);
    insertbeg(5);
    insertend(6);
    insertbetween(2,3,7);
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
void createlist(int size){
    int x=1;
    for(int i=0; i<size; i++){
        if(head==NULL){
            node *new=(node *)malloc(sizeof(node));
            new->data=x;
            new->next=NULL;
            new->prev=NULL;
            head=new;
        }
        else{
            node *p1=(node *)malloc(sizeof(node));
            node *p=(node *)malloc(sizeof(node));
            p->data=x;
            p1=head;
            while(p1->next!=NULL){
                p1=p1->next;
            }
            p1->next=p;
            p->prev=p1;
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
    p->prev=NULL;
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
    p->next=NULL;
    p->prev=p1;
    p1->next=p;
    display();
}
void insertbetween( int prevval, int nextval, int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p1=head;
    p2=head->next;
    while(p1->data!=prevval && p2->data!=nextval){
        p1=p1->next;
        p2=p2->next;
    }
    p->next=p2;
    p->prev=p1;
    p2->prev=p;
    p1->next=p;
    display();
}