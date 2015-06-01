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
#define mems(x) memset(x,-1,sizeof(x))
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
int M[255][205][155],money,C;

int dp(int coke,int n5,int n10)
{
  if(coke==0) return 0;
  if(M[coke][n5][n10]!=-1) return M[coke][n5][n10];
  int n1=money-8*(C-coke)-5*n5-10*n10;
  int t=INT_MX;
  if(n1>=8) t=8+dp(coke-1,n5,n10);
  if(n5>=2) t=MIN(t,2+dp(coke-1,n5-2,n10));
  if(n10>=1) t=MIN(t,1+dp(coke-1,n5,n10-1));
  if(n1>=3&&n5>=1) t=MIN(t,4+dp(coke-1,n5-1,n10));
  if(n1>=3&&n10>=1) t=MIN(t,4+dp(coke-1,n5+1,n10-1));
  if(t==INT_MX)t=0;
  return M[coke][n5][n10]=t;
}
int main()
{
    int n1,n5,n10,kase;
    S1(kase);
    while(kase--)
    {
      S1(C);
      S3(n1,n5,n10);
      money=n1+5*n5+10*n10;
      mems(M);
      printf("%d\n",dp(C,n5,n10));
    }
    return 0;
}
