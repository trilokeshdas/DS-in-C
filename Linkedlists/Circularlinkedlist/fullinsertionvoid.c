#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void createlist(int size);
void display();
void insertbeg(int x);
void insertend(int x);
int main(){
    createlist(4);
    insertbeg(5);
    insertend(6);
    return 0;
}
void display(){
    node *ptr=(node *)malloc(sizeof(node));
    ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");

}
void createlist(int size){
    int x=1;
    for(int i=0; i<size; i++){
        if(head==NULL){
            node *new=(node *)malloc(sizeof(node));
            new->data=x;
            new->next=new;
            head=new;
        }
        else{
            node *p1=(node *)malloc(sizeof(node));
            node *p=(node *)malloc(sizeof(node));
            p->data=x;
            p1=head;
            while(p1->next!=head){
                p1=p1->next;
            }
            p1->next=p;
            p->next=head;
        }
        x++;
    }
    display();
}
void insertbeg(int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p1=head;
    while(p1->next!=head){
        p1=p1->next;
    }
    p->next=head;
    p1->next=p;
    head=p;
    display();
}
void insertend(int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p=(node *)malloc(sizeof(node));
    p1=head;
    p->data=x;
    while(p1->next!=head){
        p1=p1->next;
    }
    p->next=head;
    p1->next=p;
    display();
}