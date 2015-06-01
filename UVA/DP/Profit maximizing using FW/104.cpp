#include<stdio.h>
#include<string.h>
#define MAXN 30
#define MAX(a,b) (a>b)?a:b
long P[MAXN][MAXN][MAXN];
double Q[MAXN][MAXN][MAXN];
void path(long i,long j,long s)
{
     if(s==0)
      return;
     else
      path(i,P[i][j][s],s-1);
     printf("%ld ",P[i][j][s]);
}
int main()
{
    long N,i,j,k,s;
    while(~scanf("%ld",&N))
    {
      for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
       {
         if(i==j)
          Q[i][j][1]=1;
         else
           scanf("%lf",&Q[i][j][1]);
         P[i][j][1]=i;
       }
      for(s=2;s<=N;s++)
       for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
         for(k=1;k<=N;k++)
         {
           if(Q[j][k][s]<(Q[j][i][s-1]*Q[i][k][1]))
           {
            Q[j][k][s]=(Q[j][i][s-1]*Q[i][k][1]);
            P[j][k][s]=i;
           }
         }
         bool flag=1;
        for(s=2;flag&&s<=N;s++)
        for(i=1;flag&&i<=N;i++)
         if(Q[i][i][s]>1.01)
         {
          path(i,i,s);
          printf("%ld\n",i);
          flag=0;
          }
         if(flag)
          printf("no arbitrage sequence exists\n");
         memset(Q,0,sizeof(Q));
    }
    return 0;
}
