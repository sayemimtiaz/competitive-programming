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
#define SIZE 100009
#define i64 long long
#define dle double
#define ifor(i,a,b) for(i=a;i<=b;i++)
#define dfor(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a

int A[SIZE];
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
    int Y,P,i,n,b,e,s,f,max,m;
    while(~scanf("%d",&Y))
    {
      scanf("%d",&P);
      for(i=1;i<=P;i++)
       scanf("%d",&A[i]);
      max=0;
      for(i=1;i<=P;i++)
      {
        n=A[i]+Y-1;
        b=i;e=P;
        while(b<=e)
        {
           m=(b+e)/2;
           if(m==P)
            break;
           else if(A[m]<=n&&A[m+1]>n)
            break;
           else if(A[m]>n)
            e=m-1;
           else
            b=m+1;
         }
         n=m-i+1;
         if(max<n)
           s=i,f=m,max=n;
      }
      printf("%d %d %d\n",max,A[s],A[f]);
    }
    return 0;
}
