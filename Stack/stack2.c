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

int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    create(s);
    push(s,1);
    push(s,2);
    pop(s);
    push(s,3);
    push(s,4);
    pop(s);
    push(s,5);
    while(!isEmpty(s)){
        pop(s);
    }
    
    display(s);
    //printf("%d is the topmost element",peek(s));
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
        printf("%d is pushed\n",x);
    }
    else{
        printf("stack overflow\n");
    }
}
int pop(stack *s){
    if(!isEmpty(s)){
        int x=s->a[s->top];
        s->top--;
        printf("%d is poped\n",x);
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