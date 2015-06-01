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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define ff first
#define ss second
#define mems(x,a) memset(x,a,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;
typedef long long i64;
typedef double dle;

inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b){return (a>b)?b:a;}
inline dle dis(dle ax,dle ay,dle bx,dle by){return ((ax-bx)*(ax-bx)+(ay-by)*(ay-by));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
int T[5050],F[5050],N;
vi adj[5050],cst[5050];

int dijkstra()
{
  int i,u,v,c;
  pii nodo;
  priority_queue<pii>pq;
  mems(T,0);
  mems(F,-1);
  F[1]=0;
  pq.push(pii(0,1));
  while(!pq.empty())
  {
    nodo=pq.top();
    pq.pop();
    u=nodo.ss;c=-nodo.ff;
    if(u==N&&T[N]){
     while(!pq.empty()) pq.pop();
     return c;
     }
    // printf("%d %d\n",u,c);
    if(T[u]>2) continue;
    T[u]++;
    repb(i,adj[u].size()-1,0){
     v=adj[u][i];
     if(T[v]>1||(c+cst[u][i]==F[v])) continue;
     if(F[v]==-1||c+cst[u][i]<F[v])F[v]=c+cst[u][i];
  //   printf("%d %d %d\n",v,F[v],c+cst[u][i]);
     pq.push(pii(-(c+cst[u][i]),v));
     }
  }
}
int main()
{
    int R,kase,kas=0,a,b,c,i;
    S1(kase);
    while(kase--)
    {
      S2(N,R);
      while(R--)
      {
       S3(a,b,c);
       adj[a].pb(b),cst[a].pb(c);
       adj[b].pb(a),cst[b].pb(c);
      }
      printf("Case %d: %d\n",++kas,dijkstra());
      rep(i,0,N)
       adj[i].clear(),cst[i].clear();
    }
    return 0;
}
