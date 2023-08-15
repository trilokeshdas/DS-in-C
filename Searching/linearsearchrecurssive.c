#include<stdio.h>
#include<stdlib.h>
int lsrecurssive(int *a, int x, int indx, int n);
int main(){
    int a[10]={1,2,5,7,8};
    int n=10;
    int pos=lsrecurssive(a,8,0,n);
    if(pos==0){
        printf("not found");
    }else{
        printf("%d is the position",pos);
    }

    return 0;
}
int lsrecurssive(int *a, int x, int indx, int n){
    int pos=0;
    if(indx>=n){
        return 0;
    }
    else if(a[indx]==x){
        pos=indx+1;
        return pos;
    }
    else{
        indx++;
       return lsrecurssive(a,x,indx,n);
    }
}