#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX(a,b) (a>=b)?a:b
#define MAXCOIN 320
#define MAXS 510000
int p[MAXCOIN][MAXS],v[MAXCOIN];
int main ()
{
    int kase,n,S,sum,i,j,w1,w2,kas=0;
    while(scanf("%d",&n)==1)
    {
       
       sum=0;
       for(i=1;i<=n;i++)
       {
        scanf("%d",&v[i]);
        sum+=v[i];
       }
       S=sum/2;
       for(i=0;i<=S;i++)
        p[0][i]=0;
        for(i=0;i<=n;i++)
        p[i][0]=0;
       for(i=1;i<=n;i++)
         for(j=1;j<=S;j++)
         {
          if(v[i]>j)
           p[i][j]=p[i-1][j];
          else
		    p[i][j]=MAX(p[i-1][j],v[i]+p[i-1][j-v[i]]);
          }
          sum=p[n][S]-(sum-p[n][S]);
          if(sum<0)sum=-sum;
       printf("Case %d: %d\n",++kas,sum);
    }
    return 0;
}
