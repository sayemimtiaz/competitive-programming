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
    int a[10009],i,peak,n;
    bool move;
    while(scanf("%d",&n)&&n)
    {
      for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
     a[0]=a[n];n++;
     a[n]=a[1];
     move=0;
     if(a[0]<a[1])
        move=1;
     peak=0;
     for(i=2;i<=n;i++)
     {
       if(move&&a[i]<a[i-1])
        peak++,move=0;
       else if(!move&&a[i]>a[i-1])
        peak++,move=1;
     }
     printf("%d\n",peak); 
    }
    return 0;
}
