#include<stdio.h>
#include<stdlib.h>

void selectsort(int *a, int size);
void display(int *a, int size);
int main(){
    int a[]={1,-2,45,0,11,-6,9,-20};
    int n=sizeof(a)/sizeof(a[0]);
    selectsort(a,n);
    return 0;
}
void display(int *a, int n){
     
  for(int i=0; i<n; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void selectsort(int *a, int n){
    int i,j;
    int minIndex;
    for(i=0; i<n-1; i++){
        minIndex=i;
        for(j=i+1; j<n; j++){
            if(a[j]<a[minIndex]){
                minIndex=j;
            }
        }
        //swap the minindex value with the ith index value
        int temp;
        temp=a[i];
        a[i]=a[minIndex];
        a[minIndex]=temp;
        display(a,n);
    }
}