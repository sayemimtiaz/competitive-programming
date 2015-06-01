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
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
int d[1005];
vi adj[1005];
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void bfs()
{
     queue<int>q;
     int u,i,v;
     bool vis[1005]={0};
     vis[0]=1;
     d[0]=0;
     q.push(0);
     while(!q.empty())
     {
       u=q.front();
       q.pop();
       for(i=adj[u].size()-1;i>=0;i--)
       {
         v=adj[u][i];
         if(!vis[v])
          d[v]=d[u]+1,vis[v]=1,q.push(v);
       }
     }
}
int main()
{
    int i,a,b,n,e,kase;
    bool isStart=0;
    scanf("%d",&kase);
    while(kase--)
    {
       scanf("%d %d",&n,&e);
       for(i=0;i<e;i++)
       {
         scanf("%d %d",&a,&b);
         adj[a].pb(b);
         adj[b].pb(a);
       }
       bfs();
      if(isStart)printf("\n");
      else isStart=1;
      for(i=1;i<n;i++){
       printf("%d\n",d[i]);adj[i].clear();}
       adj[0].clear();
    }
    return 0;
}
