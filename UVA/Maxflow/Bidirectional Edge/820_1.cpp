#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 500
#define INF 2147483647
long path[MAXN],flow[MAXN][MAXN],S,D,N;
long bfs()
{
     long v,i,u,cf;
     for(i=1;i<=N;i++)
      path[i]=-2;
     queue<long>q;
     q.push(S);
     path[S]=-1;
     while(!q.empty())
     {
       u=q.front();
       q.pop();
       if(u==D)
       {
           cf=INF;
           v=D;
           while(path[v]!=-1)
           {
             cf=(cf>flow[path[v]][v])?flow[path[v]][v]:cf;
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
void maxflow()
{
     long cf,v,totalflow=0;
     while(cf=bfs())
     {
       totalflow+=cf;
       v=D;
       while(path[v]!=-1)
       {
          flow[path[v]][v]-=cf;
          flow[v][path[v]]+=cf;
          v=path[v];
       }
     }
     printf("The bandwidth is %ld.\n\n",totalflow);
}
int main()
{
    long E,kas=1,a,b,c;
    while(scanf("%ld",&N)&&N)
    {
        scanf("%ld %ld %ld",&S,&D,&E);
        while(E--)
        {
          scanf("%ld %ld %ld",&a,&b,&c);
          flow[a][b]+=c;
          flow[b][a]+=c;
        }
        printf("Network %ld\n",kas++);
        maxflow();
        memset(flow,0,sizeof(flow));
                  
    }                   
    return 0;
}
