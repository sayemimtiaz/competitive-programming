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
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 unsigned long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

const i64 mod=1000000007;
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
i64 npow(i64 n)
{
    if(n==0)
     return 1;
    if(n==1)
     return 2;
    i64 t=npow(n/2);
    t=(t*t)%mod;
    if(n%2)
     t=(t*2)%mod;
    return t;
}
int main()
{
    int kase,kas=0;
    i64 n;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%llu",&n);
      printf("Case #%d: %llu\n",++kas,(n*npow(n-1))%mod);
    }
    return 0;
}
