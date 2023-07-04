#include<stdio.h>
#include<stdlib.h>

void quicksort(int *a, int lb, int ub);
int partition(int *a,int lb, int ub);
void display(int *a, int size);
int main(){
    int a[]={7,6,10,5,9,2,1,15,7};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    display(a,n);
    return 0;
}
void display(int *a, int n){
     
  for(int i=0; i<n; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
int partition(int *a,int lb, int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            // swap start and end
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    // now swap pivot with the end element
    int temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    return end;
}
void quicksort(int *a, int lb, int ub){
    if(lb<ub){
        int partitionIndex=partition(a,lb,ub);
        quicksort(a,lb,partitionIndex-1);
        quicksort(a,partitionIndex+1,ub);
    }
}