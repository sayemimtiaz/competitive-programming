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

inline i64 max(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 min(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int main()
{
    int a,n,m,kase,show,i;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      show=0;
      while(n>=m)
      {
        a=n/m;
        show+=a;
        if(n==m)
         n=0;
        else
          n=a+(n%m);
      }
      if(n)
       printf("cannot do this\n");
      else
       printf("%d\n",show);
    }
    return 0;
}
