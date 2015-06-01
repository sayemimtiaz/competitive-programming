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
#define eps 0.00000000001
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
vi grap1[12000],grap2[12000];

struct S
{
  int node;
  int f;
}N[12000];
int tim,n;
int vis[12000];
bool C[12000],flag;

bool cmp(S a,S b)
{
    return a.f>b.f;
}

void dfs1(int cur)
{
     int i,next;
     tim++;
     vis[cur]=1;
     for(i=grap1[cur].size()-1;i>=0;i--)
     {
       next=grap1[cur][i];
       if(!vis[next])
         dfs1(next);
       else if(vis[next]==2)
        flag=0;
     }
     vis[cur]=2;
     tim++;
     N[cur].f=tim;
}
void dfs2(int cur)
{
     int i,next;
     vis[cur]=1;
     for(i=grap2[cur].size()-1;i>=0;i--)
     {
       next=grap2[cur][i];
       if(!vis[next])
         dfs2(next);
     }
}
int main()
{
    int i,e,a,b,j,kas=1,kase,m;
    S1(kase);
    while(kase--)
    {
        S2(n,m);
        rep(i,0,n-1)
          grap1[i].clear(),grap2[i].clear();
       // mems(C);
        mems(vis);
        rep(i,0,n-1)
         N[i].node=i,N[i].f=0;
        rep(i,0,m-1)
        {
          S2(a,b);
          grap1[a].pb(b);
          grap2[b].pb(a);
        }
       flag=1;tim=0;
        for(i=0;i<n;i++)
         if(!vis[i]){
           if(i){ flag=0;break;}
          dfs1(i);}
         if(!flag){printf("NO\n");continue;}
        sort(N,N+n,cmp);
        mems(vis);j=0;
        for(i=0;i<n;i++)
         if(!vis[N[i].node]){
           if(j){ flag=0;break;}
          dfs2(N[i].node);j++;}
         if(!flag)printf("NO\n");
         else printf("YES\n");
   
        }
        return 0;
}
