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

int flow[1030][1030],path[1030],S,D;
vector<int>adj[1030];

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
          // printf("Edge %ld %ld costs %ld\n",path[v],v,flow[path[v]][v]);
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
      // printf("%d\n",cf);
       v=D;
       while(path[v]!=-1)
       {
           flow[path[v]][v]-=cf;
           flow[v][path[v]]+=cf;
        //   printf("%d ",v);
           v=path[v];
       }
      // printf("\n");
    }
    return totalflow;
    
}
int main()
{
    int i,j,k,v,t,C,P;
    while( scanf("%d %d",&C,&P)&&(C||P))
    {
      S=0,D=C+P+1;
      for(v=0,i=1;i<=C;i++)
      {
        adj[0].pb(i);
        scanf("%d",&k);
        flow[0][i]=k;
        v+=k;
      }
      for(i=1;i<=P;i++)
      {
        adj[C+i].pb(D);
        flow[C+i][D]=1;
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        { 
          scanf("%d",&t);
          adj[i+C].pb(t),adj[t].pb(i+C);
          flow[t][i+C]=1;
        }
      }
      if(maxflow()==v)
      {
        printf("1\n");
      for(i=1;i<=C;i++,printf("\n"))
      {
         bool flag=0;
       for(j=C+1;j<=C+P;j++)
       {
        if(flow[j][i]){
          if(flag)
           printf(" ");
          else
           flag=1;
          printf("%d",j-C);
          }
       }
       }
      }
      else 
      printf("0\n");
       for(i=0;i<=D;i++){
        adj[i].clear();  
         for(j=0;j<=D;j++)        
          flow[i][j]=0;
          }       
    }
    return 0;
}
