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

int a[10],n;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

inline void swap(int i)
{
       int temp=a[i];
       a[i]=a[i-1];
       a[i-1]=temp;
}

int recur()
{
    int i,m=0;
    for(i=1;i<n;i++)
    {
      if(a[i]<a[i-1])
      {
        swap(i);
        m+=recur();
        swap(i);
      }
    }
    if(m==0)
     return 1;
    return m;
}

int main()
{
    int i,kas=1;
    bool flag;
    while(scanf("%d",&n)&&n)
    {
      flag=0;
      for(i=0;i<n;i++)
      {
       scanf("%d",&a[i]);
       if(a[i-1]>a[i])
        flag=1;
       }
       if(flag)
      printf("There are %d swap maps for input data set %d.\n",recur(),kas++);
      else
       printf("There are 0 swap maps for input data set %d.\n",kas++);
    }
    return 0;
}
