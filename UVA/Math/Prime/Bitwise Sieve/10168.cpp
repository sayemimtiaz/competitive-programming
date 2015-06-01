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
#define SIZE 3163
#define i64 unsigned 
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

i64 flag[51],a[555],c;
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
     i64 M=56;
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
inline bool isPrime(i64 n)
{
  i64 i;
  for(i=1;i<c&&a[i]<n;i++)
   if(n%a[i]==0)
    return 0;
   return 1;
} 

int main()
{
    i64 n,i;
    sieve();
    while(scanf("%u",&n)==1)
    {
      if(n<8){
         printf("Impossible.\n");continue;} 
      if(n%2){
       printf("2 3 ");n-=5;}
      else{
        printf("2 2 ");n-=4;}
        if(n==4){
       printf("2 2\n");continue;}
      for(i=1;a[i]<n&&i<c;i++)
       if(isPrime(n-a[i])){
        printf("%u %u\n",a[i],n-a[i]);break;}
    }
    return 0;
}
