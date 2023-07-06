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
void enqueue(queue *q, int x);
int dequeue(queue *q);
void display(queue *q);
void push(int x);
int pop();
void create(queue *q);
queue *q1;
queue *q2;
int main(){
    q1=(queue *)malloc(sizeof(queue));
    q2=(queue *)malloc(sizeof(queue));
    create(q1);
    create(q2);
    push(10);
    push(5);
    push(20);
    display(q1);
    pop();
    display(q1);
    pop();
    display(q1);
    
    
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
void enqueue(queue *q, int x){
    if(!isFull(q)){
        if(isEmpty(q)){
            q->f++;
            q->r++;
            q->a[q->r]=x;
             printf("%d is enqueued\n",x);
        }else{
        q->r++;
        q->a[q->r]=x;
        
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
void create(queue *q){
    q->size=100;
    q->r=-1;
    q->f=-1;
    q->a=(int *)malloc(q->size*sizeof(int));
}
void push(int x){
    enqueue(q2,x);
    while(!isEmpty(q1)){
        enqueue(q2,dequeue(q1));
    }
    queue *q=q2;
    q2=q1;
    q1=q;
}
int pop(){
    if(!isEmpty(q1)){
        int x=dequeue(q1);
    }
    else{
        printf("stack underflow");
    }
}