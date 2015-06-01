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
#define mem(x) memset(x,sizeof(x),0)
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 unsigned long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

i64 b[66700],a[66700];

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

i64 npow(i64 a,i64 n)
{
    if(n==0)
     return 1;
    if(n==1)
     return a;
    i64 p=npow(a,n/2);
    p*=p;
    if(n%2)
     p*=a;
    return p; 
}
int main()
{
    i64 i,j,c,nc,d,k;
    
    bool pRime[65]={0};
    pRime[5]=1,pRime[7]=1,pRime[11]=1,pRime[13]=1,pRime[17]=1,pRime[19]=1;
    pRime[23]=1,pRime[29]=1,pRime[31]=1,pRime[37]=1,pRime[41]=1,pRime[43]=1,pRime[47]=1;
    pRime[53]=pRime[59]=pRime[61]=1;
    
    c=0;
    bool nRime[66500]={0};
    for(i=2;i<=65536;i++)
     if(nRime[i]==0)
     {
       a[c++]=i;
       if(i<=256)
        for(j=i*i;j<=65536;j*=i)
         nRime[j]=1;
     }
     double nL;
    double L=64.00*log10(2.00);
    nc=0;
    for(i=0;i<c;i++)
    {
      for(j=4;;j++)
      {
        if(pRime[j])
         continue;
        nL=j*log10(double(a[i]));
        if(nL>=L)
         break;
        b[nc++]=npow(a[i],j);
      }
    }
    sort(b,b+nc);
    printf("1\n");
    for(i=0;i<nc;i++)
     printf("%llu\n",b[i]);
    return 0;
}
