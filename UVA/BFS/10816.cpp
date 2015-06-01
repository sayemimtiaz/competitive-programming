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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
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



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
vector<int>adj[302];
vector<double>Tem[302];
vector<double>Dis[302];
int S,T,par[309];
double mid;

bool ok()
{
  queue<int>q;
  int u,v,i;
  bool vis[309]={0};
  vis[S]=1;q.push(S);
  while(!q.empty())
  {
    u=q.front();q.pop();
    if(u==T)
    {
      while(!q.empty()) q.pop();
      return 1;
    }
    repb(i,adj[u].size()-1,0)
    {
      v=adj[u][i];
      if(vis[v]==0&&mid>Tem[u][i])
       vis[v]=1,q.push(v);
    }
  } 
  return 0;
}
bool sp;
void path(int C)
{
  if(C==-1) return;
  path(par[C]);
  if(sp)printf(" "); sp=1;
  printf("%d",C);
}
double bfs()
{
  queue<int>q;
  int u,v,i;
  double D[309];
  rep(i,0,308) par[i]=-1,D[i]=INT_MX;
  q.push(S);D[S]=0;
  while(!q.empty())
  {
    u=q.front();q.pop();
    repb(i,adj[u].size()-1,0)
    {
      v=adj[u][i];
      if(D[v]>D[u]+Dis[u][i]&&mid-Tem[u][i]>-eps)
       par[v]=u,D[v]=D[u]+Dis[u][i],q.push(v);
    }
  } 
  sp=0;
  path(T);
  printf("\n");
  return D[T];
}
int main()
{
    int i,j,kase,kas=0,a,b;
    int N,E;
    double R,D,low,high;
    
    while(S2(N,E)==2)
    {
     S2(S,T);
     while(E--)
     {
       S2(a,b);
       scanf("%lf %lf",&R,&D);
       adj[a].pb(b);
       Tem[a].pb(R);
       Dis[a].pb(D);
       adj[b].pb(a);
       Tem[b].pb(R);
       Dis[b].pb(D);
     }
     low=0;high=52;
     while(1)
     {
       mid=(low+high)/2.00;
       if(low-high>eps) break;
       if(high-low>-eps&&high-low<eps) break;
       bool ret=ok();
      // printf("low=%0.2lf high=%0.2lf mid=%0.2lf %d\n",low,high,mid,ret);
       if(ret) high=mid;
       else low=mid;
     }
     printf("%0.1lf %0.1lf\n",bfs(),mid);
     rep(i,0,N)
      adj[i].clear(),Tem[i].clear(),Dis[i].clear();
    
    }
    return 0;
}
