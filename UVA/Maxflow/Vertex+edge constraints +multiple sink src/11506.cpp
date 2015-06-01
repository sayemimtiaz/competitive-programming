#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MIN(a,b) (a>b)?b:a
#define MAX 2147483647
#define MAXN 2*55
#define in(i) (2*i)
#define out(i) (2*i+1)

long maxflow();
long bfs();

queue<long>q;
long M,flow[MAXN][MAXN],E,par[MAXN],cap[MAXN][MAXN];

int main()
{
    long a,b,c,d,i,W,kas=0;
    while(scanf("%ld %ld",&M,&W)&&(M||W))
    {
      M--;
      cap[in(0)][out(0)]=cap[in(M)][out(M)]=MAX;
      M++;
      for(i=1;i<=M-2;i++)
      {
        scanf("%ld %ld",&a,&c);a--;
        cap[in(a)][out(a)]=c;
      }
      while(W--)
      {
        scanf("%ld %ld %ld",&a,&b,&c);a--,b--;
        cap[out(a)][in(b)]=cap [out(b)][in(a)]=c;
      }
      M=in(M)-1;
      printf("Case %ld: %ld\n",++kas,maxflow());
       memset(flow,0,sizeof(flow));
       memset(cap,0,sizeof(cap));
    }
    return 0;
}
long maxflow()
{
  long TotalFlow=0,u,cf;
  while(cf=bfs())
  {
         TotalFlow+=cf;
         u=M;
         while(par[u]!=-1)
         {
           flow[par[u]][u]+=cf;
           flow[u][par[u]]=-flow[par[u]][u];
           u=par[u];
         }
  }
  return TotalFlow;
}
long bfs()
{
     long i,cf,u,v;
     for(i=0;i<=M;i++)
      par[i]=-2;
     par[0]=-1;
     q.push(0);
     while(!q.empty())
     {
       u=q.front();
       q.pop();
       if(u==M)
       {
         cf=MAX;
         while(par[u]!=-1)
         {
           cf=MIN(cf,cap[par[u]][u]-flow[par[u]][u]);
           u=par[u];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=0;i<=M;i++)
       {
          if(par[i]==-2&&cap[u][i]-flow[u][i]>0)
          {
            q.push(i);
            par[i]=u;
          }
       }
     }
     return 0;
}
 
