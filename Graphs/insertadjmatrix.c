#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
struct queue{
    int size;
    int f;
    int r;
    int *a;
};
typedef struct queue queue;
struct Graph{
    int numNodes;
    int adj_matrix[MAX_SIZE][MAX_SIZE];
    int visited[MAX_SIZE];
};
typedef struct Graph Graph;
int isEmpty(queue *q);
int isFull(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void display(queue *q);
Graph *createGraph(Graph *graph,int numNodes);
void BFS(Graph *graph, int  source);

queue *q;
int main(){
    
    
     return 0;
}
Graph *createGraph(Graph *graph, int numNodes){
    graph=(Graph *)malloc(sizeof(Graph));
    graph->numNodes=numNodes;
    for(int i=0; i<graph->numNodes; i++){
        graph->visited[i]=0;
        for(int j=0; j<graph->numNodes; j++){
            graph->adj_matrix[i][j]=0;
        }
    }
    return graph;
}
void BFS(Graph *graph,int source){
    q=(queue *)malloc(sizeof(queue));
    q->size=100; // take the size as the no. of times we will enqueue
    q->a=(int *)malloc(q->size*sizeof(int));
    q->f=-1;
    q->r=-1;
    
     //BFS implementation
    //    0---1
    //    | \ |
    //    3---2
    //     \ /              GIVEN GRAPH
    //      4       
    //     / \
    //    5   6
     //This is source. Source can be any vertex
    printf("%d ",source);
    graph->visited[source]=1;
    while(!isEmpty(q)){
        int currentvertex=dequeue(q);
        for(int i=0; i<graph->numNodes; i++){
            if(graph->adj_matrix[currentvertex][i]==1 && graph->visited==0){
                printf("%d ",i);
                graph->visited[i]=1;
                enqueue(q,i);
            }
        }
    }
        
    
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