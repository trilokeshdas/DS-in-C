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

int main(){
    queue *q=(queue *)malloc(sizeof(queue));
    q->size=100;
    q->a=(int *)malloc(q->size*sizeof(int));
    q->f=-1;
    q->r=-1;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    dequeue(q);
    enqueue(q,4);
    dequeue(q);
    dequeue(q);
    enqueue(q,5);
    while(q->f<=q->r){
        dequeue(q);
    }
    //printf("%d",q->a[0]); //checking
    // printf("%d is dequeued\n",dequeue(q));
    // printf("%d is dequeued\n",dequeue(q));
    //dequeue(q);
    printf("now traversing\n");
    display(q);
    dequeue(q);
    display(q);

    

    return 0;
}
int isEmpty(queue *q){
    if(q->f==-1 && q->r==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(queue *q){
    if(q->f==0 && q->r==q->size-1){
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
        printf("%d is enqueued\n",x);
        }
    }
    else{
        printf("Queue overflow");
    }
}
int dequeue(queue *q){
    if(!isEmpty(q)){
        int x=q->a[q->f];
        q->f++;
        printf("%d is dequeued\n",x);

    }
    else{
        printf("queue underflow");
    }
}
void display(queue *q){
    for(int i=q->f; i<=q->r; i++){
        printf("%d\t",q->a[i]);
    }
    printf("\n");
}