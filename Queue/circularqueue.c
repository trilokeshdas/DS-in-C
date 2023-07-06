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
void createqueue(queue *q);

int main(){
    queue *q=(queue *)malloc(sizeof(queue));
    createqueue(q);
   
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    enqueue(q,6);
    display(q);
    
     return 0;
}
void createqueue(queue *q){
    q->size=5;
    q->f=-1;
    q->r=-1;
    q->a=(int *)malloc(sizeof(int));
}
int isEmpty(queue *q){
    if((q->f==-1 && q->r==-1) || q->f>q->r){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(queue *q){
    if(q->f==(q->r+1)%(q->size)){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(queue *q, int x){
    if(!isFull(q)){
        if(q->f==-1 && q->r==-1){
            q->r=0;
            q->f=0;
            q->a[q->r]=x;
        }else{
       q->r=(q->r+1)%(q->size);
       q->a[q->r]=x;
        }
    }
    else{
        printf("Queue overflow\n");
    }
}
int dequeue(queue *q){
    if(!isEmpty(q)){
        int x=q->a[q->f];
        q->f=(q->f+1)%(q->size);
        return x;
    }
    else{
        printf("queue underflow\n");
    }
}
void display(queue *q){
    for(int i=q->f; i!=q->r; i=(i+1)%(q->size)){
        printf("%d\t",q->a[i]);
    }
    printf("%d ",q->a[q->r]);
    printf("\n");
}