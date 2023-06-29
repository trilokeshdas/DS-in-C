#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *a;
};
typedef struct stack stack;
int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s, int x);
int pop(stack *s);
void display(stack *s);
int peek(stack *s);
void create(stack *s);
void DFS(int source);
stack *s;
//DFS implementation
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
int main(){
    s=(stack *)malloc(sizeof(stack));
    create(s);
    DFS(0);
    return 0;
}
int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(stack *s, int x){
    if(!isFull(s)){
        s->top++;
        s->a[s->top]=x;
       
    }
    else{
        printf("stack overflow\n");
    }
}
int pop(stack *s){
    if(!isEmpty(s)){
        int x=s->a[s->top];
        s->top--;
        return x;
    }else{
        printf("stack underflow\n");
    }
}
void display(stack *s){
    for(int i=0; i<=s->top; i++){
        printf("%d\t",s->a[i]);
    }
    printf("\n");
}
int peek(stack *s){
    return s->a[s->top];
}
void create(stack *s){
    s->top=-1;
    s->size=100;
    s->a=(int *)malloc(s->size*sizeof(int));
}
void DFS(int source){
    
    push(s,source);
    while(!isEmpty(s)){
        int currentvertex=pop(s);
        if(visited[currentvertex]==1){
            if(!isEmpty(s)){
        pop(s);
        }
    }else{
       visited[currentvertex]=1;
       printf("%d ",currentvertex);
        for(int j=0; j<7; j++){
            if(adj[currentvertex][j]==1  && visited[j]==0){
                push(s,j);
            }
        }
    }
    }
}