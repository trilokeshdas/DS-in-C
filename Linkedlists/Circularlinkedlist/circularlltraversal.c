#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //points to thee next node i.e contains the address of the nedxt node
};
struct node *head;
void display(struct node *ptr);


int main(){
    struct node* head; // struct node* type pointer structure to allocate memory in the heap
    struct node* second;
    struct node* third;
    struct node* fourth;
    //ALLOCATION
    head=(struct node*)malloc(sizeof(struct node)); //typecasting to struct node type
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;

    second->data=78;
    second->next=third;
    
    third->data=82;
    third->next=fourth;

    fourth->data=112;
    fourth->next=head; //termination of the linked lists
 
 display(head);
    

    return 0;
}
void display(struct node *head){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    

}