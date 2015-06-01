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

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
i64 gcd(i64 a,i64 b)
{
    if(b==0)
     return a;
  return gcd(b,a%b);
}

int main()
{
    int kase,i,n,kas=1;
    i64 a[11],x,y,u,lcm;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
       scanf("%lld",&a[i]);
      u=1;
      for(i=0;i<n-1;i++)
      {
        lcm=(a[i]*a[i+1])/gcd(a[i],a[i+1]);
        x=(lcm/a[i])*u;
        y=(lcm/a[i+1]);
        u=x+y;
        a[i+1]=lcm;         
      }
     a[i]*=n;
     x=gcd(a[i],u);
     printf("Case %d: %lld/%lld\n",kas++,a[i]/x,u/x);
    }
    return 0;
}
