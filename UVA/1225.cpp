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

int M[10009][10];
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

inline int count(int t,int n)
{
int c=0;
while(n)
{
if(n%10==t)
 c++;
n/=10;
}
return c;
}
int main()
{
     int kase,n,a,i,j;
    for(i=1;i<=10001;i++)
    {
      for(j=0;j<=9;j++)
       M[i][j]=M[i-1][j]+count(j,i);
    }
   
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&n);
      printf("%d",M[n][0]);
      for(i=1;i<=9;i++)
       printf(" %d",M[n][i]);
       printf("\n");
      
    }
    return 0;
}
