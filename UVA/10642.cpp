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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
    i64 kase,kas=1,x1,x2,y1,y2,x,y,n;
    scanf("%lld",&kase);
    while(kase--)
    {
     scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
     x=(x1+y1)+1;
     y=(x2+y2);
     if(x<y)
     n=((y*(y+1))/2)-((x*(x+1))/2);
     else
     n=0;
     n=n+x2+1+y1;
     if((x1==x2&&y1==y2)||n<0)
      n=0;
     printf("Case %lld: %lld\n",kas++,n);
     
    }
    return 0;
}
