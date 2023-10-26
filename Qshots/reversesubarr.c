#include<stdio.h>
#include<stdlib.h>

char *rev(char *a,int n)
{
    int s=3;
    int c=0;char temp;
    char *reverse=(char *)malloc(n*sizeof(char));
    c=c+s;
    int i=0;
    int j=0;
    while(i<n)
    {
        if(i!=c && c<=n)
        {
            reverse[i]=a[c-j-1];
            i++;
            j++;
        }
        else if(c>n)
        {
            c=n;
        }
        else
        {
            c=c+s;
            j=0;
        }
    
    }
    return reverse;
}
int main(){
    char a[9]="ABCDEFGHI";
    int n=sizeof(a)/sizeof(a[0]);
    printf("%s",rev(a,n));

    return 0;
}