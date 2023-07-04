#include<stdio.h>
#include<stdlib.h>

void insertsort(int *a, int size);
void display(int *a, int size);
int main(){
    int a[]={12,54,65,7,23,9};
    int n=sizeof(a)/sizeof(a[0]);
    insertsort(a,n);
    return 0;
}
void display(int *a, int n){
     
  for(int i=0; i<n; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void insertsort(int *a, int n){
    int i,j;
    int key;
    for(i=1; i<n; i++){
        key=a[i];
        j=i-1;
        while(a[j]>key && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        display(a,n);
    }
}