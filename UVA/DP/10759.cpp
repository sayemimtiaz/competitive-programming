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

#define S1(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld %lld",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
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
#define eps 1e-9
#define mems(x,a) memset(x,a,sizeof(x))
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
i64 M[145][26];

i64 dp(i64 n,i64 rem)
{
  if(M[n][rem]!=-1) return M[n][rem];
  i64 w=0,i;
  if(rem==1){
   if(n<=6) w=1;
    return M[n][rem]=w;
  }
  for(i=1;i<=6;i++)
   if(n>i)
   w+=dp(n-i,rem-1); 
  return M[n][rem]=w;
}
i64 gcd(i64 a,i64 b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    i64 kase,kas=0,s1,s2,n,x,a,i;
    while(S2(n,x)&&(n||x))
    {
      mems(M,-1);
      s1=0;
      if(x==0)x=1;
     for(i=x;i<145;i++)
      if(i/n<7)
       s1+=dp(i,n);
      s2=pwr(6,n);
      a=gcd(s1,s2);
      s1/=a;s2/=a;
      if(s2==1)
      printf("%lld\n",s1);
      else
      printf("%lld/%lld\n",s1,s2);
    }
    return 0;
}
