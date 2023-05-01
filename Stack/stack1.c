#include<stdio.h>     //THE ADDRESS OF THE STACK SHOULD BE PASSED SO THAT ALL THE MEMBERS VALUE WILL BE changed BY USING A POINTER
#include<stdlib.h>
#define size 100
    struct stack{
    int top;
    int arr[size]; //array of any size
}; 
typedef struct stack stack;
int isEmpty(stack *s);
int isFull(stack *s);
void push(int x, stack *s);
int  pop(stack *s);
int peek(stack *s);
void traverse(stack *s);
int main(){
    stack *s;
    s->top=-1;
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    push(5,s);
    push(15,s); 
    push(225,s);  
     printf("%d\n",isEmpty(s));
      printf("%d\n",isFull(s));
    printf("%d\n",s->arr[0]);
    printf("now traversing\n");

    traverse(s);
    pop(s);
    // for(int i=0; s->top==-1; i++){
    //     traverse(s);
    // }
    
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
    if(s->top==size){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int x, stack *s){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top]=x;
        printf("%d\n",s->top);
        printf("%d\n",s->arr[s->top]);
    }
    else{
        printf("Stack overflow");
    }
}
int pop(stack *s){
    if(!isEmpty(s)){
        int x= s->arr[s->top];
        s->top--;
        return x;
    }
    else{
        printf("stack underflow");
    }
}
int peek(stack *s){
    int x= s->arr[s->top];
    return x;
}
void traverse(stack *s){
    while(s->top!=-1){
        printf("%d\n",peek(s));
        pop(s);
    }
    
}
