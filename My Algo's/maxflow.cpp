#include<cstdio>
#include<queue>
using namespace std;
#define INF 31000
#define MAXN 1000
#define MINI(a,b) (a>b)?b:a
int flow[MAXN][MAXN],N,src,dest,path[MAXN];
int bfs()
{
    int i,u,v,cf;
    queue<int>q;
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
int maxflow()
{
    int cf,totalflow=0,v;
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
void init()
{
     int i,j;
     for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
        flow[i][j]=0;
}
int main()
{
 int E,getrslt,a,b,c; 
  while(~scanf("%d %d",&N,&E))
  {
  init();
  while(E--)
  {
    scanf("%d %d %d",&a,&b,&c);
    flow[a][b]+=c;
    flow[b][a]=0;        
  }
  scanf("%d %d",&src,&dest);
  getrslt=maxflow();
  printf("%d\n",getrslt);
  }
  return 0;
}
