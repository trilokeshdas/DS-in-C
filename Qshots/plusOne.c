/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>


int* plusOne(int* digit, int n, int* q){
    int  c=0,j,i;
    int m;
    for(m=0; m<n; m++)
    {
        if(digit[m]==9)
        {
            c++;
        }
    }
    if(c==n)
    {
        j=n;
    }
    else
    {
        j=n-1;
    }
    i=n-1;
    int *a=(int *)malloc((j+1)*sizeof(int));
    while(digit[i]==9 && i>=0 && j>=0)
    {
        a[j]=0;
        i--;
        j--;
    }
    if(i<0)
    {
        a[j]=1;
    }
    else
    {
        a[j]=digit[i]+1;
        j--;
        i--;
    }
    while(j>=0 && i>=0)
    {
        a[j]=digit[i];
        j--;
        i--;
    }
    return a;
}
int main(){
    int digit[]={9,9,9,9};
    int i=1;
    int *m=&i;
    int *p=plusOne(digit,4,m);
    for(int i=0; i<5; i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}