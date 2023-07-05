#include<stdio.h>
#include<stdlib.h>

void heapsort(int *a, int size);
void heapify(int *a, int size, int index);
void display(int *a, int size);
int main(){
    int a[]={1,-2,45,0,11,-6,9,-20};
    int n=sizeof(a)/sizeof(a[0]);
    heapsort(a,n);
    display(a,n);
    return 0;
}
void display(int *a, int n){
     
  for(int i=0; i<n; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void heapify(int *a, int n, int i){
    int largest=i;
    int l=2*i+1;   // relation to  find the left and thee right tree children indexes in an array representation of tree
    int r=2*i+2;    // i is the index of the parent 
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        // swap the parent value with its children having value larger than it to make it a max heap
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapsort(int *a, int n){
    // buidling heap
    for(int i=(n/2)-1; i>=0; i--){  // we are taking i=n/2 -1 as it will start from non leaf nodes excluding the leaf nodes as they can be considered as max heap when they are checked individually
        heapify(a,n,i);
    }
    // swaping the maximum value of the tree that is the root with the last leaf node value after max heap is built
    for(int i=n-1; i>=0; i--){
        // swap the root value of the max heap with the last leaf node i.e the last element of the arrray
        // i.e swap(a[0],a[i])
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0); // again checking if the value swapped with the max value is actually making max heap or not 
        // if not again it will heapify
    }
}