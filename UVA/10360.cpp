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

int R[1026][1026];

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
    int kase,x,y,n,i,j,d,p,max;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d",&d);
      scanf("%d",&n);
      while(n--)
      {
        scanf("%d %d %d",&x,&y,&p);
        x=x-d;y=y-d;
        for(i=x;i<=(x+2*d);i++)
         for(j=y;j<=(y+2*d);j++)
          if(i<0||j<0||i>1024||j>1024)
           continue;
          else
           R[i][j]+=p;
      }
      max=R[0][0],x=0,y=0;
       for(i=0;i<1025;i++)
         for(j=0;j<1025;j++)
          if(R[i][j]>max)
          {
            max=R[i][j];
            x=i,y=j;              
          }
       printf("%d %d %d\n",x,y,max);
       memset(R,0,sizeof(R));
    }
    return 0;
}
