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
using namespace std;

#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

bool C[3001][3001];
vector<int>adj[3001];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
    int kase,n,m,i,a,b,n1,cnt,j,k;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      for(i=0;i<m;i++)
      {
        scanf("%d %d",&a,&b);
        C[a][b]=C[b][a]=1;
        if(a<b)
        adj[a].push_back(b);
        else
        adj[b].push_back(a);
      }
      cnt=0;
      for(i=1;i<=n;i++)
       for(j=adj[i].size()-1;j>=0;j--)
       {
         n1=adj[i][j];
        if(n1>i)
         for(k=adj[n1].size()-1;k>=0;k--)
          if(adj[n1][k]>n1&&C[adj[n1][k]][i])
           cnt++;
        }
      printf("%d\n",cnt);
      for(i=1;i<=n;i++)
       adj[i].clear();
      memset(C,0,sizeof(C));
    }
    return 0;
}
