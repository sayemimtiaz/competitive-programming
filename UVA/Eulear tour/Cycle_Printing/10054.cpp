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
#define mem(x) memset(x,sizeof(x),0)
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

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

vi adj[55];
si s;
int taken[55][55],f[55][55];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

void dfs(int u)
{
  int i,v;  
  for(i=adj[u].size()-1;i>=0;i--)
  {
    v=adj[u][i];
    if(taken[u][v]<f[u][v])
    {
     taken[u][v]++;
     if(u!=v)
      taken[v][u]++;
     dfs(v);
    }
  }
  s.push(u);
}

int main()
{
    int v,kase,kas=1,n,e,i,a,b,j;
    bool flag,isStart=0;
    scanf("%d",&kase);
    while(kase--)
    {
      int degree[55]={0};
       for(i=1;i<=50;i++)
        for(j=1;j<=50;j++)
         f[i][j]=taken[i][j]=0;
     scanf("%d",&e);
     for(i=1;i<=e;i++)
     {
       scanf("%d %d",&a,&b);
       adj[a].pb(b);
       adj[b].pb(a);
       degree[b]++,degree[a]++;
       f[a][b]++;
       if(a!=b)
        f[b][a]++;
     }
     flag=1;
     for(i=1;i<=50;i++)
      if(degree[i]%2==1){
       flag=0;break;}
       
       if(isStart)
        printf("\n");
       else
        isStart=1;
        printf("Case #%d\n",kas++);
       int taken[55][55]={0};
      if(flag)
      dfs(a);
      if(s.size()!=e+1)
       flag=0;
      if(flag)
      {
        a=s.top();s.pop();
        while(!s.empty())
        {
           b=s.top();s.pop();
           printf("%d %d\n",a,b);
           a=b;
        }
      }
      else
       printf("some beads may be lost\n");
       
       for(i=1;i<=50;i++)
        adj[i].clear();
      while(!s.empty())
        s.pop();
    }
    return 0;
}
