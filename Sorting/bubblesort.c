#include<stdio.h>
#include<stdlib.h>

void sort(int *a);

int main(){
    int a[100]={5,1,4,2,8};
    int i;
    sort(a);
    for(i=0;i<5;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
void sort(int *a){
int i,j;
    for(i=0;i<5;i++){
        for(j=i; j<5; j++){
          if(a[i]>a[j]){
              int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
          }
        }
}
}