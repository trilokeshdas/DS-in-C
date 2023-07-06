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
void maxmin(stack *s);

int main(){
    stack *s1=(stack *)malloc(sizeof(stack));
    create(s1);
    push(s1,1);
    push(s1,10);
    push(s1,3);
    push(s1,-27);
    maxmin(s1);
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
void maxmin(stack *s){
    int max=s->a[s->top];
    int n=s->top;
    for(int i=s->top; i>=0; i--){
        if(s->a[i]>max){
            max=s->a[i];
        }
    }
    printf("%d is the max value\n",max);
    s->top=n;
    int min=s->a[s->top];
     for(int i=s->top; i>=0; i--){
        if(s->a[i]<min){
            min=s->a[i];
        }
    }
    printf("%d is the min value",min);
}
