#include<stdio.h>
#include<stdlib.h>
const int m=3;
const int n=3;
void spiral();
int main(){
int a[3][3]={{1,2,3},
             {4,5,6},
             {7,8,9}};
    int rowstart=0;
    int rowend=m-1;
    int columnstart=0;
    int columnend=n-1;
    while(rowstart<=rowend && columnstart<=columnend)
    {
         for(int i=columnstart; i<=columnend; i++)
         {
           printf("%d ",a[rowstart][i]);   
         }
         rowstart++;
         for(int i=rowstart; i<=rowend; i++)
         {
             printf("%d ",a[i][columnend]);
         }
         columnend--;
         for(int i=columnend; i>=columnstart; i--)
         {
            printf("%d ",a[rowend][i]);
         }
         rowend--;
         for(int i=rowend; i>=rowstart; i--)
         {
            printf("%d ",a[i][columnstart]);
         }
        columnstart++;
    }


    return 0;
    
}
