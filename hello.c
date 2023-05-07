#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *a;
};
typedef struct stack stack;
int isEmpty(stack *s);
int isfull(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int postfixevaluation(char *postfix, stack *s);
 int isOperator(char ch);
 int stacktop(stack *s);

int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->size=100;
    s->a=(char *)malloc(s->size*sizeof(char));
    s->top=-1;
    char postfix[100]="28-4+567*+*";
    // for(int i=0; postfix[i]!='\0'; i++){
    //     printf("%c\n",postfix[i]);
    // }
    printf("%d is the postfixevaluation of %s\n",postfixevaluation(postfix,s),postfix);
    
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
        printf("stack overflow");
    }
}
int pop(stack *s){
    if(!isEmpty(s)){
    int x= s->a[s->top];
    s->top--;
    return x;
    }
    else{
        printf("stack underflow");
    }
}
int stacktop(stack *s){
    return s->a[s->top];
}
 int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*'|| ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
 }
int postfixevaluation(char *postfix, stack *s){
    int i=0;
    
    while(postfix[i]!='\0'){
        if(!isOperator(postfix[i])){
            push(s,postfix[i]-'0'); //ch - '0' is used for getting digit rather than ASCII code of digit
            i++;
        }
        else{
            int op2,op1;
            int value;

            op2=pop(s);
            op1=pop(s);
            
            switch(postfix[i]){
                case '+':
                    value=op1+op2;
                    break;
                case '-':
                    value=op1-op2;
                    break;
                case '*':
                    value=op1*op2;
                    break;
                case '/':
                    value=op1/op2;
                    break;
            }
            push(s,value);
            i++;
        
        }
    }
return stacktop(s);
    
}