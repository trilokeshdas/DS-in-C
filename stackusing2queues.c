#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *a;
};
typedef struct queue queue;
int isEmpty(queue *q);
int isFull(queue *q);
int enqueue(queue *q, int x);
int dequeue(queue *q);
void push(queue *q2,queue *q1, int x);
int pop(queue *q1);
int top(queue *q1);
void display(queue *q);

int main(){
    queue *q1=(queue *)malloc(sizeof(queue));
    queue *q2=(queue *)malloc(sizeof(queue));
    q1->size=100; // take the size as the no. of times we will enqueue
    q1->a=(int *)malloc(q1->size*sizeof(int));
    q1->f=-1;
    q1->r=-1;
    q2->size=100; // take the size as the no. of times we will enqueue
    q2->a=(int *)malloc(q2->size*sizeof(int));
    q2->f=-1;
    q2->r=-1;
    push(q2,q1,1);
    push(q2,q1,2);
    push(q2,q1,3);
    pop(q1);
    top(q1);
   
    
    
   
    //printf("%d",q->a[0]); //checking
    // printf("%d is dequeued\n",dequeue(q));
    // printf("%d is dequeued\n",dequeue(q));
    //dequeue(q);
    
    
     return 0;
}
int isEmpty(queue *q){
    if((q->f==-1 && q->r==-1 || (q->f>q->r))){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(queue *q){
    if( q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int  enqueue(queue *q, int x){
    if(!isFull(q)){
        if(isEmpty(q)){
            q->f++;
            q->r++;
            q->a[q->r]=x;
            return x;
        }else{
        q->r++;
        q->a[q->r]=x;
        return x;
        }
        if(q->f>q->r){
            q->f--;
        }
    }
    else{
        printf("Queue overflow\n");
    }
}
int dequeue(queue *q){
    if(!isEmpty(q)){
        int x=q->a[q->f];
        q->f++;
        return x;

    }
    else{
        printf("queue underflow\n");
    }
}
void display(queue *q){
    for(int i=q->f; i<=q->r; i++){
        printf("%d\t",q->a[i]);
    }
    printf("\n");
}
void push(queue *q2,queue *q1, int x){
    int y= enqueue(q2,x);
    printf("%d is pushed\n",y);
    // if(!isEmpty(q1)){
    // while(!isEmpty(q1)){
    //     enqueue(q2,dequeue(q1));
    // }
    // }
    while(!isEmpty(q2)){
        enqueue(q1,dequeue(q2));
    }
}
int pop(queue *q1){
    if(!isEmpty(q1)){
    int y=dequeue(q1);
    printf("%d is poped\n",y);
    }
    else{
        printf("stack underflow");
    }
    } 

int top(queue *q1){
  
    int x= q1->a[q1->f];
    printf("%d is the topmost element\n",x);
}