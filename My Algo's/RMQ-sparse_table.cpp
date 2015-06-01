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

int m[100][100];

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
    int n,i,j,b,a[100],max,q,c,g,d,x,y;
    while(~scanf("%d",&n))
    {
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     
    for(i=0;i<n;i++)
     m[i][0]=a[i];
     
    for(j=1;(1<<j)<=n;j++)
     for(i=0;i+(1<<j)<=n;i++)
       m[i][j]=MIN(m[i][j-1],m[i+(1<<(j-1))][j-1]);
     
     scanf("%d",&q);
     while(q--)
     {
       scanf("%d %d",&x,&y);
       d=log(y-x+1)/log(2);
       printf("%d\n",MIN(m[x][d],m[y-(1<<d)+1][d]));
     }

    }
    return 0;
}
