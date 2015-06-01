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

int main()
{
    int kase,h,l,w,n,min,a;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      min=INT_MX;
      for(h=n/2;h>=1;h--)
       for(l=n/h;l>=1;l--)
       {
          w=h*l;
          if(n%w==0)
          {
            w=n/w;
            a=2*(h*l)+2*(h*w)+2*(l*w);
            min=MIN(min,a);
          }
       }
       printf("%d\n",min);
    }
    return 0;
}
