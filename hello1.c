#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==-1 && q->f==-1){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        if(isEmpty(q)){
            q->r++;
            q->f++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
        }else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
        }
    }
}
 
int dequeue( struct queue *q){
    if(!isEmpty(q)){
        int x=q->arr[q->f];
        q->f++;
        printf("%d is dequeued\n",x);

    }
    else{
        printf("queue underflow\n");
    }
}
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 45);
    
   
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}