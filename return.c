#include<stdio.h>
#include<stdlib.h>

int a(int *a){
    if(*a==1){
        return *a;
    }else{
        *a=*a+1;
    }
}
int main(){
    
    return 0;
}