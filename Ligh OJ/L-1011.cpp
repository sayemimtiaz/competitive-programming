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

int A[20][20];
int memo[20][65556];
int N;

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
  return a;
}

int dp(int node,int state)
{
  if(node>N)
   return 0;
  if(memo[node][state]!=-1)
   return memo[node][state];
  int i,t; 
 int m=INT_MN;
// printf("P %d %d\n",node,state);
  rep(i,1,N){
   if(!(state&(1<<(i-1))))
   {
    // printf("C%d %d\n",i,state|(1<<(i-1)));
     t=A[node][i]+dp(node+1,state|(1<<(i-1)));
     m=MAX(m,t);
   }
}
   return memo[node][state]=m;
}

int main()
{
    int kase,kas=0,i,j;
    S1(kase);
    while(kase--)
    {
     S1(N);
     
     rep(i,1,N)
      rep(j,0,65544)
       memo[i][j]=-1;
       
     rep(i,1,N)
       rep(j,1,N)
        S1(A[i][j]);
     printf("Case %d: %d\n",++kas,dp(1,0));
    }
    return 0;
}
