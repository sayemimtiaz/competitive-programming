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
#define INT_MX 1<<28
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x,a) memset(x,a,sizeof(x))
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
inline dle eu_dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
vi E[1000];
int match[1000],n,dis[1000];

bool bfs()
{  
 int u,v,i;
 qi q;
 
  rep(i,1,n)
   if(match[i]==0) dis[i]=0,q.push(i);
   else dis[i]=INT_MX;
  dis[0]=INT_MX;
  while(!q.empty())
  {
    u=q.front();q.pop();
    if(u==0) continue;
    int len=E[u].size()-1;
    rep(i,0,len)
    {
      v=E[u][i];
      if(dis[match[v]]==INT_MX)
       dis[match[v]]=dis[u]+1,q.push(match[v]);
    }
  }
  return (dis[0]!=INT_MX);
}
bool dfs(int u)
{
  if(u==0) return true;
  
  int i,v;
  int len=E[u].size()-1;
  rep(i,0,len){
    v=E[u][i];
    if(dis[match[v]]==dis[u]+1)
    if(dfs(match[v]))
    {
      match[u]=v,match[v]=u;
      return true;
    }
  }
  dis[u]=INT_MX;
  return false;
}
int main()
{
    int i,j,a,b,m,e;
    S3(n,m,e);
    while(e--)
    {
      S2(a,b);
      E[a].pb(b);
    }
    mems(match,0);
    int ans=0;
    while(bfs())
    {
      
      rep(i,1,n)
       if(match[i]==0&&dfs(i))
        ans++;
    }
    printf("%d\n",ans);
    getchar();getchar();
    return 0;
}
