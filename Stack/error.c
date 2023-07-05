#include<stdio.h>     //THE ADDRESS OF THE STACK SHOULD BE PASSED SO THAT ALL THE MEMBERS VALUE WILL BE changed BY USING A POINTER
#include<stdlib.h>
   
    struct stack{
    int top;
    int arr[80]; //array of any size
}; 
typedef struct stack s;
int isEmpty(s stack);
int isFull(s stack);
void push(int x, s stack);
int  pop(s stack);
int main(){
    s stack;
    stack.top=-1;
    printf("%d\n",isEmpty(stack));
    printf("%d\n",isFull(stack));
    push(5,stack);
    printf("%d\n",isEmpty(stack));
      printf("%d\n",isFull(stack));
    return 0;
}
int isEmpty(s stack){
    if(stack.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(s stack){
    if(stack.top==79){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int x, s stack){
    if(!isFull(stack)){
        stack.top++;
        stack.arr[stack.top]=x;
        printf("%d\n",stack.top);
        printf("%d\n",stack.arr[stack.top]);
    }
    else{
        printf("Stack overflow");
    }
}
int pop(s stack){
    if(!isEmpty(stack)){
        int x= stack.arr[stack.top];
        stack.top--;
        return x;
    }
    else{
        printf("stack underflow");
    }
}

