#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[]={10,20,30,40,50,60,70,80,90};
    int low,mid,high;
    int x=40;
    low=0;
    high=8;
    while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==x){
        printf("the position of element %d  is %d",x,mid+1);
        break;
    }
    else if(arr[mid]<x){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    if(arr[mid]!=x){
        printf("element not found");
    }
    return 0;
}