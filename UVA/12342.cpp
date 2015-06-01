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
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-13
#define mems(x) memset(x,0,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};
struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;



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
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
}


int main()
{
    int kase,kas=0;
    double n,a,r;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%lf",&n);
      printf("Caes %d: ",++kas);
      n-=180000;r=0.00;
      if(n<=0){
       printf("0\n");continue;}
      a=300000.00;
      n-=a;
      if(n<0){ a+=n;
      r+=(10.00*a)/(double)100.00;
      r=ceil(r+eps);
      if(r<2000) r=2000.00;
      printf("%0.lf\n",r);
      continue;
      }
      r+=(10.00*a)/(double)100.00;
      a=400000.00;
      n-=a;
      if(n<0){ a+=n;
      r+=(15.00*a)/(double)100.00;
      r=ceil(r+eps);
      if(r<2000) r=2000.00;
      printf("%0.lf\n",r);
      continue;
      } 
       r+=(15.00*a)/(double)100.00;
       a=300000.00;
      n-=a;
      if(n<0){ a+=n;
      r+=(20.00*a)/(double)100.00;
      r=ceil(r+eps);
      if(r<2000) r=2000.00;
      printf("%0.lf\n",r);
      continue;
      } 
       r+=(20.00*a)/(double)100.00;
       r+=(25.00*n)/(double)100.00;
       r=ceil(r+eps);
      if(r<2000) r=2000.00;
      printf("%0.lf\n",r);
       
    }
    return 0;
}
