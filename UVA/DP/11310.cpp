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
    int i,kase,n,j;
    i64 way[45];
    way[0]=way[1]=1;
    way[2]=5;
    for(i=3;i<=40;i++)
    {
      way[i]=way[i-1]+4*way[i-2]+2*way[i-3];
    }
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      printf("%lld\n",way[n]);
    }
    return 0;
}
