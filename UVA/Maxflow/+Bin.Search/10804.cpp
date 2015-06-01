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
#define i64 double
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
typedef pair<int,double>pii;



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

struct PP
{
 double x,y;
}G[102],H[102];
int flow[200][200];
int k,sink,par[200],n,m;
double mid;
vector<pii>adj[200];

int bfs()
{
  int i,u;
  pii v;
  stack<int>s;
  rep(i,0,sink) par[i]=-1;
  par[0]=-2;
  s.push(0);
  while(!s.empty())
  {
    u=s.top();s.pop();
    if(u==sink)
    {
      while(!s.empty()) s.pop();
      return 1;
    }
   // printf("%d\n",u);
    repb(i,adj[u].size()-1,0)
    {
      v=adj[u][i];
      if(par[v.first]==-1&&flow[u][v.first]&&v.second<=mid){
   //    printf("%d\n",v.first,v.second);
       par[v.first]=u,s.push(v.first);
       }
    }
  }  
  return 0;
}
bool ok()
{
  int j,i,u,tf;
  tf=0;
  rep(i,1,m)
    flow[0][i]=1,flow[i][0]=0;
  rep(i,1,sink)
    flow[i+m][sink]=1,flow[sink][i+m]=0;
  rep(i,1,m)
     rep(j,1,n)
        flow[i][j+m]=1,flow[j+m][i]=0;
  while(bfs())
  {
      tf++;
      u=sink;
     // printf("%d",sink);
      while(u)
      {
      //  printf(" %d",par[u]);
        flow[par[u]][u]=0;
        flow[u][par[u]]=1;
        u=par[u];
      } 
     // printf("\n");
  }
//  /printf("tf %d\n",tf);
  return (tf>=k);
}
int main()
{
    int i,j,kase,kas=0;
    double d,low,high;
    S1(kase);
    while(kase--)
    {
      S3(m,n,k);
      k=m-k;
      rep(i,1,m)
       scanf("%lf %lf",&G[i].x,&G[i].y); 
      rep(i,1,n)
       scanf("%lf %lf",&H[i].x,&H[i].y);
      
      rep(i,1,m)
       adj[0].pb(pii(i,INT_MN));
      
      low=0;high=0;
      rep(i,1,m)
       rep(j,1,n)
       {
         d=sqrt((G[i].x-H[j].x)*(G[i].x-H[j].x)+(G[i].y-H[j].y)*(G[i].y-H[j].y));
         adj[i].pb(pii(j+m,d));
         adj[j+m].pb(pii(i,d));
         high=MAX(high,d);
       }
       sink=m+n+1;
       rep(i,1,n)
         adj[i+m].pb(pii(sink,INT_MN));

       high++;
       bool flag=0;
       while(1)
       {
         if(low-high>eps) break;
         if(high-low>-eps&&high-low<eps) break;
         mid=(low+high)/2.00;
         bool ret=ok();
         //printf("low=%0.3lf high=%0.3lf mid=%0.3lf ret=%d\n",low,high ,mid,ret);
         if(ret){flag=1; high=mid;}
         else low=mid;
       }
       printf("Case #%d:\n",++kas);
       if(!flag)
        printf("Too bad.\n");
       else
        printf("%0.3lf\n",high);
       printf("\n");
       rep(i,0,sink) adj[i].clear();
    }
    return 0;
}
