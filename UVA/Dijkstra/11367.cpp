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

struct Node
{
  int u,c;
};
struct State
{
  int u,r,d;
};

vector<Node>adj[1009];
bool vis[1009][109];
int n,O[1009];

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

bool operator<(const State &a,const State &b)
{
  return a.d > b.d;
}
void dijkstra(int C,int s,int t)
{
    priority_queue<State>q;
    State temp={s,0,0};
    q.push(temp);
    bool flag=0;
    int i,j,nr;
    while(!q.empty())
    {
      temp=q.top();q.pop();
      if(vis[temp.u][temp.r]) continue;
 
      vis[temp.u][temp.r]=1;
      if(temp.u==t){ printf("%d\n",temp.d);flag=1;break;}
      repb(i,adj[temp.u].size()-1,0)
      {
        Node N=adj[temp.u][i];
         nr=temp.r-N.c;
         if(nr>-1){
         if(!vis[N.u][nr]){
         State next={N.u,nr,temp.d};
          q.push(next);}
          }
          nr=temp.r+1;
         if(nr>C||vis[temp.u][nr]) continue;
         State next1={temp.u,nr,temp.d+O[temp.u]};
          q.push(next1);
      }
    }
    if(!flag)
     printf("impossible\n");
     rep(i,0,n-1)
      rep(j,0,100)
       vis[i][j]=0;
       while(!q.empty())
        q.pop();
}
int main()
{
    int m,a,b,c,C,i,q;
    
    while(S2(n,m)==2)
    {
      rep(i,0,n-1)
       S1(O[i]);
      while(m--){
        S3(a,b,c);
        Node U={b,c};
        adj[a].pb(U);
        Node V={a,c};
        adj[b].pb(V);
        }
        S1(q);
        while(q--){
          S3(C,a,b);
          dijkstra(C,a,b);
        }
        rep(i,0,n-1)
         adj[i].clear();
    }
    return 0;
}
