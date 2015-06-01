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
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000001
#define i64 unsigned long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
struct Point
{
  dle x,y;
};
int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
inline dle dis(Point a,Point b)
{
  //Without sqrt()
  return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

i64 flag[1562509],a[6000000],c;
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
     i64 M=10000;
     i64 i,j,k;
     c=1;
     for(i=3;i<SIZE;i+=2)
       if(!chkC(i)){
        a[c++]=i;
        if(i<=M)
         for(j=i*i,k=i<<1;j<SIZE;j+=k)
          setC(j);
        }
}

int main()
{
    i64 n,b,e,m,key,i;
    sieve();
    while(scanf("%llu",&n)==1)
    {
       if(n<=4){
         printf("%llu is not the sum of two primes!\n",n);continue;}
      if(n%2){
       if(!chkC(n-2))
         printf("%llu is the sum of 2 and %llu.\n",n,n-2);
       else
         printf("%llu is not the sum of two primes!\n",n);
         continue;
         }
      key=n/2;
      b=1,e=c-1;
      while(b<=e)
      {
        m=(b+e)/2;
        if(a[m]==key||(a[m]<=key&&a[m-1]>=key))
         break;
        if(a[m]>key)
         e=m-1;
        else
         b=m+1;
      }
      bool A=0;
      for(i=m;i>0;i--)
       if(a[i]<(n-a[i])&&(n-a[i])%2&&!chkC(n-a[i])){A=1;
        printf("%llu is the sum of %llu and %llu.\n",n,a[i],n-a[i]);break;}
        
      if(!A)
          printf("%llu is not the sum of two primes!\n",n);
    }
    return 0;
}
