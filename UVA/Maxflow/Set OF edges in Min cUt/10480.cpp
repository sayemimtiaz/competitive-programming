#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<cctype>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INF 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

int n,flow[55][55],path[55];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int bfs()
{
    int i,u,v,cf,tf;
    queue<long>q;
    for(i=1;i<=n;i++)
     path[i]=-2;
    q.push(1);
    path[1]=-1;
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       if(u==2)
       { 
         cf=INF;
         v=2;
         while(path[v]!=-1)
         {
           cf=MIN(cf,flow[path[v]][v]);
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=1;i<=n;i++)
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
    int cf,v,totalflow=0;
    while(cf=bfs())
    {
       totalflow+=cf;
      // printf("%d\n",cf);
       v=2;
       while(path[v]!=-1)
       {
           flow[v][path[v]]+=cf;
           //if(flow[v][path[v]]>flow[path[v]][v])
           // flow[v][path[v]]-=flow[path[v]][v];
           flow[path[v]][v]-=cf;
          //printf("%d ",v);
           v=path[v];
       }
      // printf("\n");
    }
    return totalflow;
    
}

int main()
{
    int m,i,j,a,b,c;
    while(scanf("%d %d",&n,&m)&&(n||m))
    {
        for(i=0;i<m;i++)
        {
         scanf("%d %d %d",&a,&b,&c);
         flow[a][b]=flow[b][a]=c;
        }
        maxflow();
        for(i=1;i<=n;i++)
        {
       //  printf("%d\n",path[i]);
         for(j=1;j<=n;j++)
          if(path[i]!=-2&&path[j]==-2&&!flow[i][j]&&flow[j][i])
           printf("%d %d\n",i,j);
           }
        printf("\n");
        
         for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
          flow[i][j]=0;
    }
    return 0;
}
