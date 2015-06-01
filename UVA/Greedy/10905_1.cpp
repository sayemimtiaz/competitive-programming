#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX(a,b) (a>b)?a:b

char num[55][1000];

int cmp(const void *a,const void *b)
{
    char cpy1[1000],cpy2[1000];
    strcpy(cpy1,(char*)a);
    strcat(cpy1,(char*)b);
    strcpy(cpy2,(char*)b);
    strcat(cpy2,(char*)a);
    return strcmp(cpy1,cpy2);
}

int main()
{
    int i,j,n,mx_len;
    while(scanf("%d",&n)&&n)
    {
      mx_len=0;
      for(i=0;i<n;i++)
        scanf("%s",num[i]);
       qsort(num,n,sizeof(num[0]),cmp);
      for(i=n-1;i>=0;i--)
       printf("%s",num[i]);
      printf("\n"); 
    }
    return 0;
}
