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
bool palin(int n)
{
     int d[100],i,j,k;
     i=0;
     while(n)
     {
       d[i++]=n%10;
       n/=10;
     }
     for(;i<4;i++)
      d[i]=0;
     for(k=0,j=i-1;k<=j;k++,j--)
      if(d[j]!=d[k])
       return 0;
     return 1;
}

int main()
{
    char str[1000];
    int h,m,d,i,a,b;
    while(gets(str))
    {
      sscanf(str,"%d%*c%d",&h,&m);
      d=h*100+m;
      if(d>=2332){
       printf("00:00\n");continue;}
      for(i=d+1;i<2400;i++)
      {
         a=i/100;
         b=i-a*100;
         if(b>=0&&b<=59&&palin(i))
         {
          printf("%02d:%02d\n",a,b);break;
          }
      }
    }
    return 0;
}
