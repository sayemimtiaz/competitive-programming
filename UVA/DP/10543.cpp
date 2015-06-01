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

int memo[55][25];
vi adj[55];
int n,k;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int dp(int city,int lec)
{
    if(lec>=21)
     return 21;
    if(city==n-1&&lec>=k)
     return 1;
    if(memo[city][lec]!=-1)
     return memo[city][lec];
     int i,m=21,v,t;
    for(i=adj[city].size()-1;i>=0;i--)
    {
      v=adj[city][i];
      if(v!=city){
       t=1+dp(v,lec+1);
       m=MIN(m,t);
       }         
    }
    memo[city][lec]=m;
    return m;
}
int main()
{
    int m,t,i,j,a,b;
    while(scanf("%d %d %d",&n,&m,&k)&&(n||m||k))
    {
       for(i=0;i<n;i++)
        for(j=0;j<25;j++)
         memo[i][j]=-1;
       while(m--)
       {
         scanf("%d %d",&a,&b);
         adj[a].pb(b);
       }
       t=dp(0,1);
       if(t!=21)
        printf("%d\n",t);
       else 
        printf("LOSER\n");
         for(i=0;i<n;i++)
          adj[i].clear();
    }
    return 0;
}
