#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void display();

int main(){
     
     node* second;
     node* third;
     node* fourth;
    //ALLOCATION
    head=(struct node*)malloc(sizeof(struct node)); //typecasting to struct node type
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=11;
    head->prev=NULL;
    head->next=second;

    second->data=78;
    second->prev=head;
    second->next=third;
    
    third->data=82;
    third->prev=second;
    third->next=fourth;

    fourth->data=112;
    fourth->prev=third;
    fourth->next=NULL; //termination of the linked lists
    display();
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
