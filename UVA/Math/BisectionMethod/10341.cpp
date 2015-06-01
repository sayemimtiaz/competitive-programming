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
#define F(x)  p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x*x) + u

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
    long double p,q,r,s,t,u,f0,f1,m,a,b,fm;
    while(~scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&p,&q,&r,&s,&t,&u))
    {
      f0=F(0);f1=F(1);
      if((f0>eps&&f1>eps)||(f0<-eps&&f1<-eps))
       printf("No solution\n");
      else if(f0<eps&&f0>-eps)
       printf("0.0000\n");
      else if(f1<eps&&f1>-eps)
       printf("1.0000\n");
      else
      {
          a=0.0000,b=1.0000;
          while(1)
          {
            m=(a+b)/(double)2.0000;
            fm=F(m);
           // printf("F[%lf]=%lf\n",m,fm);
            if(fm<eps&&fm>-eps){
             printf("%.4Lf\n",m);break;}
            if(fm>eps&&f0>eps)
             a=m,f0=fm;
            else
             b=m,f1=fm;
          }
      }
    }
    return 0;
}
