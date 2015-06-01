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

int flow[109][109],path[109],S,D;
vector<int>adj[109];

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
    queue<int>q;
    for(i=0;i<=D;i++)
     path[i]=-2;
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
           cf=MIN(cf,flow[path[v]][v]);
           v=path[v];
         }
         while(!q.empty())
          q.pop();
         return cf;
       }
       for(i=adj[u].size()-1;i>=0;i--)
       {
           v=adj[u][i];
           if(path[v]==-2&&flow[u][v])
           {
             q.push(v);
             path[v]=u;
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
       v=D;
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
    struct PP
    {
      int h,a;
      bool s;
    }M[55],W;
    
    int kase,kas=1,i,j,n,m,a[250],b;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      for(i=1;i<=n;i++)
      {
        adj[0].pb(i);
        flow[0][i]=1;
        scanf("%d %d %d",&M[i].h,&M[i].a,&M[i].s);
      }
      S=0,D=n+m+1;
      for(i=1;i<=m;i++)
      {
        adj[i+n].pb(D);
        flow[i+n][D]=1;
        scanf("%d %d %d",&W.h,&W.a,&W.s);
        for(j=1;j<=n;j++)
         if(abs(M[j].h-W.h)<=12&&abs(M[j].a-W.a)<=5&&W.s==M[j].s)
          adj[j].pb(i+n),adj[i+n].pb(j),flow[j][i+n]=1;
      }
     printf("Case %d: %d\n",kas++,maxflow());
       for(i=0;i<=D;i++){
        adj[i].clear();  
         for(j=0;j<=D;j++)        
          flow[i][j]=0;
          }       
    }
    return 0;

}
