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
void BFS(int source);
queue *q;
int main(){
    q=(queue *)malloc(sizeof(queue));
    q->size=100; // take the size as the no. of times we will enqueue
    q->a=(int *)malloc(q->size*sizeof(int));
    q->f=-1;
    q->r=-1;
    BFS(0);
    
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
void BFS(int source){
     //BFS implementation
    //    0---1
    //    | \ |
    //    3---2
    //     \ /              GIVEN GRAPH
    //      4       
    //     / \
    //    5   6
     //This is source. Source can be any vertex
    int visited[7]={0,0,0,0,0,0,0}; //as no vertex are visited so all are initialised to zero
        int adj[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",source);
    visited[source]=1;
    enqueue(q,source);
    while(!isEmpty(q)){
        int currentvertex=dequeue(q);
        for(int j=0; j<7; j++){
            if(adj[currentvertex][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
}
  
    