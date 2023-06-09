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
void deletebeg();
void deleteend();
void deleteanyval(int x);

int main(){
    createlist(4);
    deletebeg();
    deleteend();
    deleteanyval(2);
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
void deletebeg(){
    node *p1=(node *)malloc(sizeof(node));
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    display();
}
void deleteend(){
    node *p1=(node *)malloc(sizeof(node));
    //node *p2=(node *)malloc(sizeof(node)); commented this to do in the other way by using only one pointer
    p1=head;
   // p2=head->next;
    while(p1->next!=NULL){
        p1=p1->next;
        //p2=p2->next;
    }
    p1->prev->next=NULL;
    free(p1);
    display();
}
void deleteanyval( int x){
    node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    p1=head;
    p2=head->next;
    while(p2->data!=x){
        p1=p1->next;
        p2=p2->next;
    }
    node *temp=p2;
    p2=p2->next;
    p2->prev=p1;
    p1->next=p2;
    free(temp);
    display();
}