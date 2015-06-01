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
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
vi adj[120];
bool vis[33768];
int dis[33768],m;
qi q;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}


void bfs(int s)
{
  int u,v,i,j; 
  vis[s]=1,q.push(s),dis[s]=0;
  while(!q.empty())
  {
   u=q.front();q.pop();
   rep(i,0,m-1)
   {
     v=u;
     repb(j,adj[i].size()-1,0)
      v=v^(1<<adj[i][j]);
    // printf("%d\n",v);
     if(!vis[v])
      vis[v]=1,dis[v]=dis[u]+1,q.push(v);
  }
}
}
int main()
{
    int kase,n,i,j,a,kas=1;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      rep(i,0,m-1)
       rep(j,0,n-1)
       {
         scanf("%d",&a);
         if(a)
         adj[i].pb(j);
       }
       bfs((1<<n)-1);
       printf("Case %d: ",kas++);
       if(!vis[0])
        printf("IMPOSSIBLE\n");
       else
        printf("%d\n",dis[0]);
        rep(i,0,m-1)
         adj[i].clear();
        mems(vis);
    }
    return 0;
}
