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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

vector<int>adj[1200],cost[1200];
int d[1200],N,ct[1200];
pair<int,int>next,nodotmp;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void Dijkstra()
{
     int u,v,c,i;
  priority_queue<pair<int,int> >pq;
  for(i=1;i<=N;i++)
    d[i]=INT_MX,ct[i]=-1;
  ct[2]=1;
  d[2]=0;
  bool vis[1200]={0};
  pq.push(make_pair(0,2));
  while(!pq.empty())
  {
     nodotmp=pq.top();
     pq.pop();
     u=nodotmp.second;
     if(!vis[u])
     {
       vis[u]=1;
       for(i=adj[u].size()-1;i>=0;i--)
       {
        v=adj[u][i];
        if(d[v]>d[u]+cost[u][i])
        {
          d[v]=d[u]+cost[u][i];
          pq.push(make_pair(-d[v],v));
        }
       }
     }
  }
}
int f(int u)
{
    if(ct[u]>=0)
     return ct[u];
     int cnt=0,v,i,c;
    for(i=adj[u].size()-1;i>=0;i--)
     {
        v=adj[u][i];
        if(d[v]<d[u])
         cnt+=f(v);
     }
     ct[u]=cnt;
     return cnt;
    
}
int main()
{
    int a,b,c,i,M,max;
    while(scanf("%d",&N)&&N)
    {
      scanf("%d",&M);
      while(M--)
      {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(b);
        cost[a].push_back(c);
        adj[b].push_back(a);
        cost[b].push_back(c);
      }
      Dijkstra();
      printf("%d\n",f(1)); 
       for(i=1;i<=N;i++)
       cost[i].clear(),adj[i].clear();  
    }
    return 0;
}
