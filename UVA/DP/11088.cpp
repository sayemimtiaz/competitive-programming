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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define ff first
#define ss second
#define mems(x,a) memset(x,a,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;
typedef long long i64;
typedef double dle;
struct Point
{
  dle x,y;
};
inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b){return (a>b)?b:a;}
inline dle dis(Point a,Point b){return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
int M[120][32770],a[30],n;

int dp(int s,int h,int ad)
{
 if(M[ad][s]!=-1)return M[ad][s];
 int w=0,i;
 if(h==3)
 {
   if(ad<20) return M[ad][s]=0;
   w=1;
   rep(i,0,n-1)
     if(!(s&(1<<i)))
        w=MAX(w,1+dp(s|(1<<i),1,a[i])); 
 }
 else{
 rep(i,0,n-1)
  if(!(s&(1<<i)))
       w=MAX(w,dp(s|(1<<i),h+1,ad+a[i]));
  }
  return M[ad][s]=w;
}
int main()
{
    int kas=0,i;
    while(S1(n)&&n)
    {
      mems(M,-1);
      rep(i,0,n-1)
       S1(a[i]);
      printf("Case %d: %d\n",++kas,dp(0,0,0));
    }
    return 0;
}
