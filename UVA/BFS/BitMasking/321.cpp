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
struct S
{
  int u,s,k;
}p[15][1025];

queue <pii>q;
vi adj[15],swit[15];
int vis[15][1025],d[15][1025];

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

void bfs()
{
  pii nodotmp;
  int u,v,i,s,ns;
  
  while(!q.empty())
  {
    nodotmp=q.front();q.pop();
    u=nodotmp.first;s=nodotmp.second;
   // printf("Maa %d %d\n",u,s);
    repb(i,adj[u].size()-1,0){
      v=adj[u][i];
      if((s&(1<<(v-1)))&&!vis[v][s]){
       p[v][s].u=u,p[v][s].s=s,vis[v][s]=1,q.push(pii(v,s));
    //    printf("F %d %d\n",v,s);
    d[v][s]=d[u][s]+1;
    }
      }
    repb(i,swit[u].size()-1,0){
      v=swit[u][i];
      if(u==v) continue;
      ns=s^(1<<(v-1));
      if(!vis[u][ns])
      {
       p[u][ns].u=u,p[u][ns].s=s;
       p[u][ns].k=v;
       if(ns&(1<<(v-1)))
       vis[u][ns]=2;
       else
       vis[u][ns]=3;
      //  printf("S %d %d\n",u,ns);
       q.push(pii(u,ns));
       d[u][ns]=d[u][s]+1;
       }
      }
  }
}
void print(int n,int s)
{
 if(vis[n][s]==-1) return;
 if(vis[n][s]==1){
  print(p[n][s].u,p[n][s].s); 
  printf("- Move to room %d.\n",n);
  }
 else if(vis[n][s]==2){
  print(p[n][s].u,p[n][s].s); 
  printf("- Switch on light in room %d.\n",p[n][s].k);
  }
  else{
  print(p[n][s].u,p[n][s].s); 
  printf("- Switch off light in room %d.\n",p[n][s].k);
  }
}
int main()
{
    int a,b,r,dd,s,kas=0,i;
    
    while(S3(r,dd,s)&&(r||dd||s))
    {
      while(dd--){
        S2(a,b);
        adj[a].pb(b),adj[b].pb(a);
        }
      while(s--){
        S2(a,b);
        swit[a].pb(b);
      }
      vis[1][1]=-1;p[1][1].u=1,p[1][1].s=1;d[1][1]=0;
      q.push(pii(1,1));bfs();
      printf("Villa #%d\n",++kas);
      if(!vis[r][1<<(r-1)])
       printf("The problem cannot be solved.\n");
      else{
       printf("The problem can be solved in %d steps:\n",d[r][1<<(r-1)]);
       print(r,1<<(r-1));
       }
      printf("\n");
      
      rep(i,1,r){
       adj[i].clear();
       swit[i].clear();
       }
       mems(vis);
    }
    return 0;
}
