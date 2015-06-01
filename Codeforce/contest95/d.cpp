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

bool flag;
vi adj[3050];
int p[3050],d[3050];
bool s[3050],vis[3050];
qi q;

void bfs()
{
     int i,next,u;
  while(!q.empty())
  {
    u=q.front();q.pop();
     for(i=adj[u].size()-1;i>=0;i--)
  {
    next=adj[u][i];
    if(d[next]>d[u]+1)
     d[next]=d[u]+1,q.push(next);
  }
}
}
void dfs(int cur)
{
   int i,next;
  if(flag) return;
  vis[cur]=1;
  for(i=adj[cur].size()-1;i>=0;i--)
  {
    if(flag) return;
    next=adj[cur][i];
    if(vis[next]==0){
     p[next]=cur;dfs(next);}
    else if(p[cur]!=next){
       flag=1;
      while(cur!=next)
      {
        d[cur]=0;
        q.push(cur);
        cur=p[cur];
      //  cout<<cur<<endl;
      }
      d[cur]=0;q.push(cur);
      return; 
    }
  }
  
}
int main()
{
    int n,a,b,i;
    S1(n);
    rep(i,1,n){
     S2(a,b);
     adj[a].pb(b);
     adj[b].pb(a);
     p[i]=i;
     d[i]=INT_MX;
     }
     dfs(a);
     bfs();
     printf("%d",d[1]);
     for(i=2;i<=n;i++)
      printf(" %d",d[i]);
     printf("\n");
      rep(i,1,n)
       adj[i].clear();
       mems(vis);
       flag=0;
     getchar();getchar();
    return 0;
}
