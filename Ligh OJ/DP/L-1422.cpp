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
#define Ss(a) scanf("%s",a)
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
#define swap(a,b,t) t=a,a=b,b=t
#define mems(x,a) memset(x,a,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;
typedef int i64;
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

int C[120],M[101][101];

int dp(int a,int b)
{
  if(a>b) return 0;
  int &rs=M[a][b];
  if(rs!=-1) return rs;
  rs=1000;
  int i;
  for(i=a+1;i<=b;i++)
   if(C[a]==C[i])
    rs=MIN(rs,dp(a+1,i-1)+dp(i,b));
  rs=MIN(rs,1+dp(a+1,b));
  return rs;
}
int main()
{
    int kase,kas=0,i,N,j;
    S1(kase);
    while(kase--)
    {
      S1(N);
      rep(i,1,N) S1(C[i]);
      rep(i,0,N) rep(j,0,N) M[i][j]=-1;
      printf("Case %d: %d\n",++kas,dp(1,N));
    }
    return 0;
}
