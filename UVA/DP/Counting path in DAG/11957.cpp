#include<stdio.h>
#include<string.h>

const int mod=1000007;
int m[120][120];
char grid[120][120];
 
int main()
{
    int i,j,n,kase,sum,kas=1;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);n++;
      for(i=2;i<=n;i++)
      {
        getchar();
        for(j=2;j<=n;j++)
        {
          scanf("%c",&grid[i][j]);
          if(grid[i][j]=='W')
            m[i][j]=1;
          else if( grid[i][j]=='B')
           m[i][j]=-1;
        }
      }
      for(i=n;i>=2;i--)
       for(j=n;j>=2;j--)
       {
         if(m[i][j]==-1)
          continue;
         if(m[i+1][j-1]!=-1)
          m[i][j]=(m[i][j]+m[i+1][j-1])%mod;
         else if(m[i+2][j-2]!=-1)
          m[i][j]=(m[i][j]+m[i+2][j-2])%mod;
         if(m[i+1][j+1]!=-1)
          m[i][j]=(m[i][j]+m[i+1][j+1])%mod;
          else if(m[i+2][j+2]!=-1)
          m[i][j]=(m[i][j]+m[i+2][j+2])%mod;
       }
      /* for(i=2;i<=n;i++,printf("\n"))
       for(j=2;j<=n;j++)
        printf("%d ",m[i][j]);*/
       for(sum=0,i=2;i<=n;i++)
        if(m[2][i]!=-1)
         sum=(sum+m[2][i])%mod;
       printf("Case %d: %d\n",kas++,sum);
       memset(m,0,sizeof(m));
    }
    return 0;
}
