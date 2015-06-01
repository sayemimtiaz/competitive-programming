//It makes an connected undirected graph directed
//which doesn't violate connectivity of original graph 

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 int
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

vi adj[1200];
bool vis[1200],orient[1200][1200];
int low[1200],d[1200],tim;

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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}

void dfs(int v,int p)
{
  vis[v]=1;
  d[v]=tim++;
  low[v]=d[v];
  int i,w;
  repb(i,adj[v].size()-1,0)
  {
    w=adj[v][i];
    if(w==p) continue;
    if(!vis[w]){
      orient[v][w]=1;
      dfs(w,v);
      if(low[w]>d[v]) orient[w][v]=1;//v,w is a bridge
      low[v]=MIN(low[v],low[w]);
     }
    else{
      low[v]=MIN(low[v],d[w]);
      if(!orient[v][w]&&!orient[w][v])
       if(d[w]<d[v]) orient[v][w]=1;
       else orient[w][v]=1;
    }
  }
}
int main()
{
    int n,m,i,j,a,b,kas=0;
    while(S2(n,m)&&(n||m))
    {
      while(m--)
      {
        S2(a,b);
        adj[a].pb(b),adj[b].pb(a);
      }
      tim=0;
      dfs(a,-1);
      printf("%d\n\n",++kas);
      rep(i,1,n)
       rep(j,1,n)
        if(orient[i][j]) 
         printf("%d %d\n",i,j);
      rep(i,1,n){
        adj[i].clear();vis[i]=0;
       rep(j,1,n)
        orient[i][j]=0;
        }
        printf("#\n");
    }
    return 0;
}
