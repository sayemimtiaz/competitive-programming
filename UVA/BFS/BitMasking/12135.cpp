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

int m,d[42768];
vi adj[100];
bool vis[42768];
qi q;

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
  int u,v,i,j;
  vis[0]=1;
  d[0]=0;
  q.push(0);
  while(!q.empty())
  {
    u=q.front();
    q.pop();
   //printf("State %d\n",u);
    for(i=0;i<m;i++)
    {
      v=u;
      for(j=adj[i].size()-1;j>=0;j--)
        v=v^(1<<adj[i][j]);
     // printf("%d %d\n",v,vis[v]);
      if(vis[v])
       continue;
      vis[v]=1,q.push(v),d[v]=d[u]+1;             
    }
  }
}

int main()
{
    int n,kase,kas=0,sz,q,i,u,p,b;
    char str[1000];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      for(i=0;i<m;i++)
      {
        scanf("%d",&sz);
        while(sz--)
        {
          scanf("%d",&b);
          adj[i].pb(b);
        }
      }
      bfs();
      scanf("%d",&q);
      printf("Case %d:\n",++kas);
      while(q--)
      {
        scanf("%s",str);
        p=strlen(str)-1;
        for(u=0,i=0;str[i];i++,p--)
         u+=((str[i]-'0')*(1<<p));
        if(vis[u])
        printf("%d\n",d[u]);
        else
        printf("-1\n");
      }
      printf("\n");
      memset(vis,0,sizeof(vis));
      for(i=0;i<m;i++)
          adj[i].clear();
    }
    return 0;
}
