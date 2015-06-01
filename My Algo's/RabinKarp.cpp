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
const int mod=611957;
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}

i64 npow(int n,int p)
{
    if(p==1)
     return n;
    if(p==0)
     return 1;
    i64 a;
    a=npow(n,p/2);
    a=(a*a)%mod;
    if(p%2)
     a=(a*n)%mod;
    return a; 
}

int main()
{
    int i,n,m,s,d;
    i64 pp,p,t,a;
    char P[1000],T[10000];
    bool found;
    while(~scanf("%s",T))
    {
      scanf("%s",P);
      //Radix
       d=29;
      p=0,t=0;
      //Preprocessing
      for(i=0;P[i]!='\0';i++)
      {
        p=(((d*p)%mod)+(P[i]%d))%mod;
        t=(((d*t)%mod)+(T[i]%d))%mod;
      }
      m=i;
      n=strlen(T);
      //log(n) method to compute pow()
      pp=npow(d,m-1)%mod;
      found=false;
      
      for(s=0;s<=(n-m);s++)
      {
        if(p==t)
        {
          for(i=0;i<m;i++)
           if(T[s+i]!=P[i])
            break;
          if(i==m)
          {found=true;printf("Valid shift at %d\n",s);break;}
        }
        if(s<(n-m))
        {
         a=(d*(t-((pp*(T[s]%d))%mod))%mod);
         if(a<0)
          a+=mod;
         t=(a+(T[s+m]%d))%mod;
        }
      }
      if(found==false)
       printf("Invalid shift\n");
      }
      return 0;
}
