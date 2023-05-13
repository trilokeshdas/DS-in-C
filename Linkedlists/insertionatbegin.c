#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *insertion(node *head, int x);
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
    head=insertion(head,0);
    display(head);
     return 0;
}

node *insertion(node *head, int x){
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=head;
    head=ptr;
    return head;
}
void display(node *ptr){
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}