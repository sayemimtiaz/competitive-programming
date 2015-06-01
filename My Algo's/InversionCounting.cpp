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

int a[SIZE],c[SIZE];

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

int combine(int b,int e,int m)
{
    int i,j,k,cnt;
    i=b;j=m+1;k=0,cnt=0;
    while(i<=m&&j<=e)
    {
      if(a[i]<=a[j])
       c[k++]=a[i],i++;
      else
       c[k++]=a[j],j++,cnt+=(m-i+1);
    }
    if(i>m)
     for(;j<=e;j++)
      c[k++]=a[j];
    else
       for(;i<=m;i++)
      c[k++]=a[i];
    for(i=b,j=0;i<=e;i++,j++)
     a[i]=c[j];
    return cnt;
}

int divide(int b,int e)
{
    if(b==e)
     return 0;
    int m,r=0;
    m=(b+e)/2;
    r=divide(b,m);
    r+=divide(m+1,e);
    r+=combine(b,e,m);
    return r;
}


int main()
{
    int n,i;
    while(scanf("%d",&n))
    {
    for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
    printf("%d\n",divide(1,n));
    }
    return 0;
}
