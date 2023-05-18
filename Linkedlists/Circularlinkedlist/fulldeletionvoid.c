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
void deletebeg();
void deleteend();
int main(){
    createlist(4);
    deletebeg();
    deleteend();
    
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
void deletebeg(){
    node *p1=(node *)malloc(sizeof(node));
     node *temp;
    p1=head;
    while(p1->next!=head){
        p1=p1->next;
    }
    temp=head;
    head=head->next;
    p1->next=head;
    free(temp);
    display();
}
void deleteend(){
    node *p1=(node *)malloc(sizeof(node));
    node *p2=(node *)malloc(sizeof(node));
    p1=head;
    p2=head->next;
    while(p2->next!=head){
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=head;
    free(p2);
    display();
}