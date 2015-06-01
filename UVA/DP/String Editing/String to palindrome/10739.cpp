#include<stdio.h>
#include<string.h>
#define MIN(a,b) (a>b)?b:a
int len[1005][1005];
int main()
{
    int kase,i,j,n,k,kas=1;
    char str[2000];
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
       gets(str);
       n=strlen(str);
       for(i=0;i<n;i++)
          for(k=0,j=i;j<n;j++,k++)
          {
            if(k==j)
            {len[k][j]=0;continue;}
            if(str[k]==str[j])
            { len[k][j]=len[k+1][j-1];continue;}
            len[k][j]=MIN(len[k][j-1],len[k+1][j]);
            len[k][j]=MIN(len[k][j],len[k+1][j-1]);
            len[k][j]+=1;
          }
       printf("Case %d: %d\n",kas++,len[0][n-1]);
    }
    return 0;
}
