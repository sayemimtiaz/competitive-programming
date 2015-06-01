#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
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

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
vi adj[120];
qi q;
bool C[1][120],T[1][120];

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
void bfs1(int s)
{
    int i,u,v;
    bool vis[120]={0};
    vis[s]=vis[0]=1;
    q.push(0);
    while(!q.empty())
    {
		u=q.front();
        q.pop();
		T[0][u]=1;
        for(i=adj[u].size()-1; i>=0; i--)
        {
            v=adj[u][i];
            if(!vis[v])
             q.push(v),vis[v]=1;
        }
    }
	
}
void bfs2(int s)
{
    int i,u,v;
    bool vis[120]={0};
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
		u=q.front();
        q.pop();
		C[0][u]=1;
        for(i=adj[u].size()-1; i>=0; i--)
        {
            v=adj[u][i];
            if(!vis[v])
             q.push(v),vis[v]=1;
        }
    }
}
int main()
{
    int kase,kas=0,i,j,n,k,a;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%d",&n);
     printf("Case %d:\n",++kas);
     rep(i,0,n-1)
      rep(j,0,n-1){
       scanf("%d",&a);
       if(a)
        adj[i].pb(j);
       }
       bfs2(0);
       C[0][0]=1;
       printf("+");
       rep(i,1,2*n-1)
        printf("-");
       printf("+\n");
       rep(i,0,n-1)
        if(C[0][i])
         printf("|Y");
        else
         printf("|N");
        printf("|\n");
      rep(i,1,n-1){
        bfs1(i);
         printf("+");
       rep(k,1,2*n-1)
        printf("-");
       printf("+\n");
       rep(j,0,n-1)
       {
         if(C[0][j]&&!T[0][j])
          printf("|Y");
         else
           printf("|N");
       }
       printf("|\n");
        mems(T);
       }
        printf("+");
       rep(i,1,2*n-1)
        printf("-");
       printf("+\n");
       rep(i,0,n-1)
        adj[i].clear();
       mems(C);
       mems(T);
    }
    return 0;
}
