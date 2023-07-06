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
void trackmax(stack *s, int x);

int main(){
    stack *s1=(stack *)malloc(sizeof(stack));
    create(s1);
    trackmax(s1,10);
    
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
void trackmax(stack *s1, int x){
    stack *s2=(stack *)malloc(sizeof(stack));
    s2->top=-1;
    s2->size=100;
    s2->a=(int *)malloc(s2->size*sizeof(int));
    if(!isFull(s1)){
        if(isEmpty(s1)){
            push(s1,x);
            push(s2,x);
        }
        else{
                push(s1,x);
            if(x>s2->a[s2->top]){
                push(s2,x);
            }
            else{
                push(s1,x);
                push(s2,s2->a[s2->top]);
            }
        }
    printf("%d is the max value\n",s2->a[s2->top]);
    }
    else{
        printf("stack overflow");
    }
}