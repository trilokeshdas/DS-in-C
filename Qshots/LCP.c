//longest common prefix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * longestCommonPrefix(char **a, int n){
    char *store=malloc(100*sizeof(char));
    int i=0;
while(i<n-1)
{
    int j=0;
    int k=0;
    while(a[i][j]!='\0' || a[i+1][j]!='\0' && store[k]!='\0')
    {
        if(a[i][j]==a[i+1][j] && (a[i][j]!='\0' || a[i+1][j]!='\0'))
        {
            store[k]=a[i][j];
            j++;
            k++;
        }
        else
        {
            store[k]='\0';
            break;
        }
    }
    i++;
 }
 return store;
    
}

int main(){
    char a[3][100]={"flower","flow","flight"};
    char s[100];
    printf("%c",a[0][3]);
    char c=a[0][3];
    printf("%c",c);
    s[0]=a[0][3];
    printf("%c",s[0]);
    return 0;
}