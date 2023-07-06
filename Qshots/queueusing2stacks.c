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
void enqueue(int x);
int dequeue();
stack *s1;
stack *s2;

int main(){
    s1=(stack *)malloc(sizeof(stack));
    s2=(stack *)malloc(sizeof(stack));
    create(s1);
    create(s2);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(s1);
    dequeue();
    display(s1);
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
    for(int i=s->top; i>=0; i--){
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
void enqueue(int x){
    while(!isEmpty(s1)){
    push(s2,pop(s1));
    }
    push(s1,x);

    while(!isEmpty(s2)){
        push(s1,pop(s2));
    }

}
int dequeue(){
    int x=pop(s1);
    return x;
}