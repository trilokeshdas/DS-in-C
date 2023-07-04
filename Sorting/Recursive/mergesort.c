#include<stdio.h>
#include<stdlib.h>
// here lb: lower bound
// ub: upper bound
void mergesort(int *a, int lb, int ub);
void merge(int *a, int lb, int mid, int ub); 
void display(int *a, int size);
int main(){
    int a[]={1,-2,45,0,11,-6,9,-20};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    display(a,n);
    return 0;
}
void display(int *a, int n){
     
  for(int i=0; i<n; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void merge(int *a, int lb, int mid, int ub){
    int n=ub+1; // size of the array
    int b[n];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(int i=lb; i<=ub; i++){
        a[i]=b[i];
    }
}
void mergesort(int *a, int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}