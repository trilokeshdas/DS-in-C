#include<stdio.h>
#include<stdlib.h>
// To check if the values of the array remains same or not without returning the array from the function.
// it will change as the argument of the function takes the address of the first element of the array
// so any value of the array can be changed bcoz of the pointer inside the function without returning the array unlike any variable
void h(int *a, int n);
int main(){
    int a[]={1,2,3};
    int n=3;
    for(int i=0; i<3; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    h(a,n);
     for(int i=0; i<3; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void h(int *a, int n){
    a[0]=5;
    *(a+1)=4; // same as a[1]
    a[2]=3;
}