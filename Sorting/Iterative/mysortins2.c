#include<stdio.h>
#include<stdlib.h>

void insertsort(int *a, int size);
void display(int *a, int size);

int main(){
    int a[]={7,2,91,77,3};
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
    int sorted=0;
    for(i=0; i<n; i++){
        sorted=1;
        for(j=n-1; j>0; j--){
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                sorted=0;
            }
        }
        if(sorted){
            return;
        }
        display(a,n);
    }
}