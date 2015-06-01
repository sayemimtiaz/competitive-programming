#include<stdio.h>
#include<string.h>
long len[1200][1200];
int main()
{
    char str[1200];
    long i,j,k,n,kase;
    scanf("%ld",&kase);
    gets(str);
    while(kase--)
    {
       gets(str);
       n=strlen(str);
       for(i=0;i<n;i++)
          for(k=0,j=i;j<n;j++,k++)
          {
            if(k==j)
             len[k][j]=1;
            else if(str[k]==str[j])
             len[k][j]=2+len[k+1][j-1];
            else
                len[k][j]=(len[k][j-1]>len[k+1][j])?len[k][j-1]:len[k+1][j];
          }
       printf("%ld\n",len[0][n-1]);
    }
    return 0;
}
