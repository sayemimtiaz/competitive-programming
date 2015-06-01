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
struct PP
{
 double x,y;
}B[502],R[502];
int flow[500][500];
int k,mid,sink,par[500],r,b;
vector<pii>adj[500];

int bfs()
{
  int i,u;
  pii v;
  queue<int>q;
  rep(i,0,sink) par[i]=-1;
  par[0]=-2;
  q.push(0);
  while(!q.empty())
  {
    u=q.front();q.pop();
    if(u==sink)
    {
      while(!q.empty()) q.pop();
      return 1;
    }
   // printf("%d\n",u);
    repb(i,adj[u].size()-1,0)
    {
      v=adj[u][i];
      if(par[v.first]==-1&&flow[u][v.first]&&v.second<=mid){
   //    printf("%d\n",v.first,v.second);
       par[v.first]=u,q.push(v.first);
       }
    }
  }  
  return 0;
}
bool ok()
{
  int j,i,u,tf;
  tf=0;
  rep(i,1,b)
    flow[0][i]=1,flow[i][0]=0;
  rep(i,1,sink)
    flow[i+b][sink]=1,flow[sink][i+b]=0;
  rep(i,1,b)
     rep(j,1,r)
        flow[i][j+b]=1,flow[j+b][i]=0;
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
    int i,j,n,low,high,kase,t;
    double d,x,y;
    char str[509];
    S1(kase);
    while(kase--)
    {
      S2(n,k);
      b=r=0;
      rep(i,1,n)
      {
       scanf("%lf %lf %s",&x,&y,str); 
       if(str[0]=='b')
         B[++b].x=x,B[b].y=y;
       else
         R[++r].x=x,R[r].y=y;
      }
      if(b<k||r<k){printf("Impossible\n");continue;}
      
      rep(i,1,b){
       adj[0].pb(pii(i,INT_MN));
       }
      
      low=0;high=0;
      rep(i,1,b)
       rep(j,1,r)
       {
         d=ceil(sqrt((B[i].x-R[j].x)*(B[i].x-R[j].x)+(B[i].y-R[j].y)*(B[i].y-R[j].y)));
         t=(int)d;
         adj[i].pb(pii(j+b,t));
         adj[j+b].pb(pii(i,t));
         high=MAX(high,t);
       }
       sink=b+r+1;
       rep(i,1,r)
       {
         adj[i+b].pb(pii(sink,INT_MN));
       }
       high++;
       while(low<high)
       {
         mid=(low+high)/2;
         bool ret=ok();
        // printf("low=%d high=%d mid=%d ret=%d\n",low,high ,mid,ret);
         if(ret) high=mid;
         else low=mid+1;
       }
       printf("%d\n",high);
       rep(i,0,sink) adj[i].clear();
    }
    return 0;
}
