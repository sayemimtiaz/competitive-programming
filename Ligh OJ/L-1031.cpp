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
#define swap(a,b) a^=b,b^=a,a^=b
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



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
int A[120],M[105][105][2];

int dp(int L,int H,bool T)
{
  if(L>H) return 0;
  if(L==H)
   return A[L];
  int &m=M[L][H][T];
  
  if(m!=INT_MN) return m;
  
  int nT=T?0:1;
  int i;
  int sum=0;
  
  rep(i,L,H)
  {
    sum+=A[i];
    m=MAX(m,sum-dp(i+1,H,nT));
  }
  sum=0;
  repb(i,H,L+1)
  {
    sum+=A[i];
    m=MAX(m,sum-dp(L,i-1,nT));
  }
  return M[L][H][T]=m;
}
int main()
{
    int k,i,j,n,kase,kas=0;
    S1(kase);
    while(kase--)
    {
      S1(n);
      rep(i,1,n){
       S1(A[i]);
       rep(j,1,n)
        rep(k,0,1)
         M[i][j][k]=INT_MN;
       }
      printf("Case %d: %d\n",++kas,dp(1,n,1));
    }
    return 0;
}
