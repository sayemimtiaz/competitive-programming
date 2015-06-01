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
    int n,i,j,b,a[100],max,q,c,m[100],g,s[100],x,y;
    while(~scanf("%d",&n))
    {
    for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
    b=sqrt(n);g=b;
    if(b*b!=n)g++;j=1;
    for(i=1;i<=g;i++)
    {
       for(s[j]=i,c=j,max=a[j++];j<(c+b)&&j<=n;j++)
        max=MAX(max,a[j]),s[j]=i;
      m[i]=max;
    }
    scanf("%d",&q);
    while(q--)
    {
      scanf("%d %d",&x,&y);
      max=INT_MN;
      for(i=x;i<=y;)
      {
        if(((i+b-1)<=y&&s[i+b-1]==s[i])||((i+b-1)==n+b))
         max=MAX(max,m[s[i]]),i+=b;
        else
          max=MAX(max,a[i]),i++;
      }
      printf("%d\n",max);
    }
    }
    return 0;
}
