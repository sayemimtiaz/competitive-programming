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
#define i64  long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,-1,sizeof(x))
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

i64 M[52][52][52];
int m,n;

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

i64 dp(int nn,int k)
{
    if(M[m][nn][k]!=-1) return M[m][nn][k];
    if(!k&&!nn) return M[m][nn][k]=1;
    if(!k||!nn) return M[m][nn][k]=0;
    int i;
    i64 w=0;
    for(i=1;i<=m&&i<=nn;i++)
     w+=dp(nn-i,k-1);
   return M[m][nn][k]=w;
}
int main()
{
   int i,j,kase,kas=0,k;
   scanf("%d",&kase);
   
     mems(M);
    while(kase--)
    {
     scanf("%d %d %d",&n,&k,&m);
      printf("Case %d: %lld\n",++kas,dp(n,k));
    }
    return 0;
}
