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

int flow[2005][2005],path[2005],S,D;
vector<int>adj[2005];

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
    int i,j,k,R,C,N,r,c;
    while(scanf("%d %d %d",&R,&C,&N)&&(R||C||N))
    {
      S=0,D=R+C+1;
      for(i=1;i<=R;i++)
       adj[0].pb(i),flow[0][i]=1;
      for(i=1;i<=C;i++) 
       adj[R+i].pb(D),flow[R+i][D]=1;
      for(i=1;i<=N;i++)
      { 
       scanf("%d %d",&r,&c);
       adj[r].pb(c+R),adj[c+R].pb(r);
       flow[r][c+R]=1;
      }
      printf("%d",maxflow());
      for(i=1;i<=R;i++)
       if(path[i]==-2)
          printf(" r%d",i);
      for(i=1;i<=C;i++)
       if(path[R+i]!=-2)
          printf(" c%d",i);
       printf("\n");
       for(i=0;i<=D;i++){
        adj[i].clear();  
         for(j=0;j<=D;j++)        
          flow[i][j]=0;
          }       
    }
    return 0;
}
