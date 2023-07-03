#include<stdio.h>
#include<stdlib.h>

void sort(int *a);
void display(int *a);
int main(){
    int a[100]={5,1,4,2,8};
    sort(a);
    return 0;
}
void display(int *a){
  for(int i=0; i<5; i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void sort(int *a){
int i,j;
int sorted=0;
    for(i=0;i<5;i++){
      sorted=1;
        for(j=i; j<5; j++){
          if(a[i]>a[j]){
              int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            sorted=0;
          }
        }
        if(sorted){
          return;
        }
        display(a);
}
}