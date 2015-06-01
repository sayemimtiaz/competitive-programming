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
vector<pii>adj[30009];
int M[30009];
bool vis[30009];

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

int dfs1(int nod)
{
  int &ret=M[nod];
  if(ret) return ret;
  pii pi;
  int i,m=INT_MN,sz=adj[nod].size();
  vis[nod]=1;
  repb(i,sz-1,0)
   {  pi=adj[nod][i]; 
   if(!vis[pi.first])
    m=MAX(m,pi.second+dfs1(pi.first));
   }
   
   if(m==INT_MN) return 0;
   return M[nod]=m;
}
int main()
{
    int i,j,kase,kas=0,n,a,b,c,w,fnod;
    S1(kase);
    while(kase--)
    {
      S1(n);
      rep(i,1,n-1)
      {
       S3(a,b,c);
       adj[a].pb(pii(b,c));
       adj[b].pb(pii(a,c));
      }
      dfs1(a);
      printf("%d from %d cost %d\n",fnod,a,w);
    }
    return 0;
}
