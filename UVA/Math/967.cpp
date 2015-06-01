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
#define i64 unsigned
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
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

i64 flag[20],a[1000],c,b[20],d[9000],o,L;


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
i64 pwr(i64 n)
{
  if(n==0) return 1;
  if(n==1) return 10;
  i64 a=pwr(n/2);
  a=a*a;
  if(n%2) a*=10;
  return a;
}

bool IsPrime(i64 n)
{
  for(i64 i=0;a[i]<n&&i<c;i++)
   if(n%a[i]==0)
    return 0;
   return 1;
  
}
void sieve()
{
  i64 i,j,k;
  for(i=3;i<=1000;i+=2)
   if(!chkC(flag,i)){
     a[c++]=i;
     if(i<32)
      for(j=i*i,k=i<<1;j<=1000;j+=k)
       setC(flag,j);
       }
}
void check()
{
  i64 s,i,j,k,r,last;
  last=L-1;
  do
  {
    i=(last+1)%L;k=1;r=0;
    while(k<L){
      r+=(b[i]*pwr(L-k));
       i=(i+1)%L;
      k++;
    }
    r+=b[last];
    if(!IsPrime(r))
      return;
     if(last==L-1)
      s=r;
     last=(last+1)%L;
    
   }while(last!=L-1);
   d[o++]=s; 

}
void backTrack(i64 h)
{
  if(h==L){
    check();
   return;}
   
  b[h]=1;
  backTrack(h+1);
  b[h]=3;
  backTrack(h+1);
  b[h]=7;
  backTrack(h+1);
  b[h]=9;
  backTrack(h+1);
}
int main()
{
    sieve();
    for(L=3;L<=6;L++)
     backTrack(0);
    sort(d,d+o);
    int h,l,cnt,i;
    while(scanf("%d",&l)&&l>=0)
    {
     scanf("%d",&h);
     cnt=0;
     for(i=0;i<o;i++)
      if(d[i]>=l&&d[i]<=h)
       cnt++;
      if(cnt==1)
      printf("1 Circular Prime.\n");
      else if(cnt>1)
       printf("%d Circular Primes.\n",cnt);
      else
       printf("No Circular Primes.\n");
    }
    return 0;
}
