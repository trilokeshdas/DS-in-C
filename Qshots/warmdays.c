/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* dailyTemperatures(int* temperatures, int temperaturesSize);
int main(){
    int a[]={73,74,75,71,69,72,76,73};
    int n=sizeof(a)/sizeof(a[0]);
    int *b=dailyTemperatures(a,n);
    for(int i=0; i<n; i++){
        printf("%d ",b[i]);
    }


    return 0;
}
int* dailyTemperatures(int* temperatures, int n){
    int *warmdays=(int *)malloc(n *sizeof(int));
    for(int i=0; i<n; i++)
    {
      int j=i;
      int c=0;
      while(temperatures[j]<=temperatures[i] && j<n)
      {
          c++;
          j++;
      }
        if(j>=n){
            warmdays[i]=0;
        }
        else{
        warmdays[i]=c;
        }
    }
    return warmdays;
}