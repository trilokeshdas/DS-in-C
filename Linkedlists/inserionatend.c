#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
  node * insertAtEnd(node *head, int data);

void display(node *ptr);

int main(){
    node *head;
    node *second;
    node *third;
    node *fourth;
    

    head=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));
    fourth=(node *)malloc(sizeof(node));
    
   

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    display(head);
    head=insertAtEnd(head,5);
    display(head);
     return 0;
}
  node * insertAtEnd(node *head, int data){
    node * ptr = (node *) malloc(sizeof(node));
    node *p=(node *) malloc(sizeof(node));
    ptr->data = data;
     p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

void display(node *ptr){
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}