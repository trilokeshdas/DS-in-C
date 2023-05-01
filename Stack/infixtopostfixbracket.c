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
char stacktop(stack *s);
int precedence(char ch);
int isOperator(char ch);
char *infixtopostfix(char *infix, stack *s);




int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->size=100;
    s->a=(char *)malloc(s->size*sizeof(char));
    s->top=-1;

    char infix[100];
    printf("enter the infix Expression");
    scanf("%s",infix);
    printf("%s is the postfix expression of %s\n", infixtopostfix(infix, s),infix);
   

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
char stacktop(stack *s){
    if(!isEmpty(s)){
        return s->a[s->top];
}else{
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
// int precedence(char ch){
//     switch(ch){
//         case '+':
//         case '-': 
//                 return 1;
//         case '*':
//         case '/':
//                 return 2;
//         case '^':
//                 return 3;
    
//         default: return 0;
//     }
// }
char *infixtopostfix(char *infix, stack *s){
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            if(infix[i]=='('){
            push(s,infix[i]);
           // printf("%c\n",stacktop(s));
            i++;
        }
        else if(infix[i]==')'){
            while(stacktop(s)!='('){
                postfix[j]=pop(s);
                //printf("%c",stacktop(s));
                j++;

            }
        
            //printf("%c",stacktop(s));
            pop(s);
            i++;
        }
        else{
            postfix[j]=infix[i];
            i++;
            j++;
        } 
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

