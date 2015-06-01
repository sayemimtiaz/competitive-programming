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
#define swap(a,b,t) t=a,a=b,b=t
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
typedef pair<int,int>pii;

vi adj[12000];
vector<pii>vv;
bool vis[12000];
int low[12000],d[12000],tim;

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
      dfs(w,v);
      if(low[w]>d[v]) vv.pb(pii(MIN(v,w),MAX(v,w)));
      low[v]=MIN(low[v],low[w]);
     }
    else
      low[v]=MIN(low[v],d[w]);
  }
}
int main()
{
    char str[1000];
    int n,m,i,j,a,b,kas=0;
    while(S1(n)==1)
    {
      rep(i,1,n){
        scanf("%d %s",&a,str);
        sscanf(str,"%*c%d%*c",&m);
        while(m--)
        {
          S1(b);
          adj[a].pb(b),adj[b].pb(a);
        }
        
      }
      tim=0;
      rep(i,0,n-1)
       if(!vis[i]) dfs(i,-1);
      sort(vv.begin(),vv.end());
      a=vv.size();
      printf("%d critical links\n",a);
      rep(i,0,a-1){
         printf("%d - %d\n",vv[i].first,vv[i].second);
         }
      vv.clear();
      rep(i,0,n-1){
        adj[i].clear();vis[i]=0;}
        printf("\n");
    }
    return 0;
}
