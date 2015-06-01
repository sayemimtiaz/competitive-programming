#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define INF 2147483647
#define MAXN 3000
#define MINI(a,b) (a>b)?b:a
vector<long>adj[MAXN];
long flow[MAXN][MAXN],N,src,dest,path[MAXN];
long bfs()
{
    long i,u,v,cf,tf;
    queue<long>q;
    for(i=1;i<=N;i++)
     path[i]=-2;
    q.push(src);
    path[src]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(u==dest)
       { 
         cf=INF;
         v=dest;
         while(path[v]!=-1)
         {
           cf=MINI(cf,flow[path[v]][v]);
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=1;i<=N;i++)
       {
           if(path[i]==-2&&flow[u][i])
           {
             q.push(i);
             path[i]=u;
           }
       }
    }
    return 0;
}
long maxflow()
{
    long cf,v,totalflow=0;
    while(cf=bfs())
    {
       totalflow+=cf;
       v=dest;
       while(path[v]!=-1)
       {
           flow[path[v]][v]-=cf;
           flow[v][path[v]]+=cf;
           v=path[v];
       }
    }
    return totalflow;
    
}
int main()
{
  bool done[MAXN];
  long j,E,i,getrslt,a,b,c,TC[MAXN]; 
  while(~scanf("%ld",&N))
  {
   memset(done,0,sizeof(done));
   N=(N*2)+2;
   for(i=2;i<N;i+=2)
    scanf("%ld",&TC[i]);
   scanf("%ld",&E);
  for(i=1;i<=E;i++)
  {
    scanf("%ld %ld %ld",&a,&b,&c);
    a*=2;b*=2;
    if(!done[a])
    {
    flow[a][a+1]=TC[a];
    done[a]=1;
    }
    flow[a+1][b]=c;
   }
  scanf("%ld %ld",&b,&c);
  while(b--)
  {
   scanf("%ld",&a);
   a*=2;
   flow[1][a]=INF;
  }
  while(c--)
  {
   scanf("%ld",&a);
   a*=2;
    if(!done[a])
    {
    flow[a][a+1]=TC[a];
    done[a]=1;
    }
   flow[a][a+1]=TC[a];
   flow[a+1][N]=INF;
  }
  src=1;dest=N;
  printf("%ld\n",maxflow());
  memset(flow,0,sizeof(flow));
  }
  return 0;
}
