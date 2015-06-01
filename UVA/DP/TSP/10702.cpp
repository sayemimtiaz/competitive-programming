#include<stdio.h>
#define MAXNODE 120
#define MAXTRIP 1200 
#define MAX(a,b) (a>b)?a:b
long adj[MAXNODE][MAXNODE],C,T,memo[MAXNODE][MAXTRIP];
bool dest[MAXNODE];
void init()
{
     long i,j;
     for(i=1;i<=C;i++)
     {dest[i]=0;
     for(j=1;j<=T;j++)
      memo[i][j]=-1;
     }
}
long dp(long cur,long trip)
{
     if(memo[cur][trip]!=-1)
      return memo[cur][trip];
     long cm,m,i;
     if(trip==1)
     {
        for(i=1;i<=C;i++)
        {
          if(dest[i])
           cm=MAX(adj[cur][i],cm);
        }        
     }
     else
     {
     for(i=1;i<=C;i++)
     {
       if(cur!=i)
       {
         m=adj[cur][i]+dp(i,trip-1);
         cm=MAX(m,cm);
       }
     }
     }
     memo[cur][trip]=cm;
     return cm;
}
int main()
{
    long S,E,temp,i,j;
    while(scanf("%ld %ld %ld %ld",&C,&S,&E,&T)&&(C||S||T||E))
    {
        init();
        for(i=1;i<=C;i++)
          for(j=1;j<=C;j++)
           scanf("%ld",&adj[i][j]);
        for(j=1;j<=E;j++)
        {
           scanf("%ld",&temp);
           dest[temp]=1;
        }
        printf("%ld\n",dp(S,T));
    }
    return 0;
}
