#include<stdio.h>
#include<stdlib.h>
// THIS IS APPLICABLE FOR ONLY SORTED ARRAY
int main(){
    int n,i,low,mid,high,element;
    printf("enter the size of the array");
    scanf("%d",&n);
    int a[n];
    for(i=0; i<n;i++){
        printf("enter the elements");
        scanf("%d",&a[i]);
    } 
    printf("enter the element to be found");
    scanf("%d",&element);
    low=0;
    high=n-1;
    
    while(low<=high){
        mid=(low+high)/2;
    if(a[mid]==element){
        printf("the position of the element %d is %d",element,mid+1);
        break;//to directly go out of the loop
    }
    if(a[mid]<element){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    if(a[mid]!=element){
        printf("the element is not found");
    }

    return 0;
}