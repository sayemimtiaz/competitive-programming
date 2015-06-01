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
#define S3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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
i64 S[300009],M[300009],u;

void init(i64 b,i64 e,i64 n)
{
  if(b==e)  S[n]=M[n]=0;
  else{
   i64 m=(b+e)/2;
   S[n]=M[n]=0;
   init(b,m,2*n);
   init(m+1,e,2*n+1);    
  }
}
i64 Query(i64 b,i64 e,i64 i,i64 j,i64 n)
{
  if(e<i||b>j) return 0;
  if(b>=i&&e<=j) return S[n];
  i64 m=(b+e)/2;
  i64 d;
  if(e<=j&&b<=i)d=e-i+1;
  else if(e>=j&&b>=i) d=j-b+1;
  else d=j-i+1;
  return (d*M[n])+Query(b,m,i,j,2*n)+Query(m+1,e,i,j,2*n+1);
}
i64 Update(i64 b,i64 e,i64 i,i64 j,i64 n)
{
  if(e<i||b>j) return S[n];
  if(b>=i&&e<=j)
   {M[n]=M[n]+u;
   S[n]=S[n]+((e-b+1)*u);
   return S[n];
   }
  i64 m=(b+e)/2;
  return S[n]=((e-b+1)*M[n])+Update(b,m,i,j,2*n)+Update(m+1,e,i,j,2*n+1);
}

int main()
{
    i64 a,b,q,n,i,j,kase,kas=0,typ;
    S1(kase);
    while(kase--)
    {
      S2(n,q);
      init(1,n,1);
      printf("Case %lld:\n",++kas);
      while(q--)
      {
       S1(typ);
       if(typ==0)
       {
         S3(a,b,u);a++,b++;
         Update(1,n,a,b,1);
       }
       else
       {
           S2(a,b);a++,b++;
           printf("%lld\n",Query(1,n,a,b,1));
       }
      }
    }
    return 0;
}
