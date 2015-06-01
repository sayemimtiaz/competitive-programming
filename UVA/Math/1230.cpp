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

int n;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

i64 npow(int x,int y)
{
    if(y==0)
     return 1;
    if(y==1)
     return (x%n);
    i64 a=npow(x,y/2);
    a=((a%n)*(a%n))%n;
    if(y%2)
     a=((a%n)*(x%n))%n;
    return a; 
}

int main()
{
    int kase,x,y;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d %d",&x,&y,&n);
      printf("%lld\n",npow(x,y)%n);
    }
    scanf("%d",&x);
    return 0;
}
