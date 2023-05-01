#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *a;
};
typedef struct stack stack;

int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s,char x);
char pop(stack *s);
int stacktop(stack *s);
int precedence(char ch);
int isOperator(char ch);
char *infixtopostfix(char *infix, stack *s);




int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->size=100;
    s->a=(char *)malloc(s->size*sizeof(char));
    s->top=-1;

    char infix[100]="A+B*C";
    printf("%s is the postfix expression", infixtopostfix(infix, s));

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
void push(stack *s,char x){
    if(!isFull(s)){
        s->top++;
        s->a[s->top]=x;
    }
    else{
        printf("stack overflow\n");
    }
}
char pop(stack *s){
    if(!isEmpty(s)){
    char x=s->a[s->top];
    s->top--;
    return x;
}else{
    printf("stack underflow\n");
  }
}
int stacktop(stack *s){
    if(!isEmpty){
        return s->a[s->top];
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
        return 1;
    }else{
        return 0;
    }
}
int precedence(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return 0;
    }
}
char *infixtopostfix(char *infix, stack *s){
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(s))){
                    push(s,infix[i]);
                    i++;
            }
            else{
                postfix[j]=pop(s);
                j++;
            }
            

        }
    }
    while(!isEmpty(s)){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
