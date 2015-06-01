#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
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

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define ff first
#define ss second
#define mems(x,a) memset(x,a,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;
typedef long long i64;
typedef double dle;

inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b){return (a>b)?b:a;}
inline dle dis(dle ax,dle ay,dle bx,dle by){return ((ax-bx)*(ax-bx)+(ay-by)*(ay-by));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
int Sum[700000],v,Lazy[700000];
bool Flag[700000];

void init(int l,int h,int n)
{
  if(l==h){
    Flag[n]=0;
    Sum[n]=0;
    Lazy[n]=0;
    return;
  }
  int m=(l+h)/2;
  init(l,m,2*n);
  init(m+1,h,2*n+1);
  Sum[n]=Flag[n]=Lazy[n]=0;
}
void Refresh(int l,int h,int n)
{
  Flag[n]=0;
  Lazy[2*n]=Lazy[2*n+1]=Lazy[n];
  Flag[2*n]=Flag[2*n+1]=1;
  Sum[n]=(h-l+1)*Lazy[n];
}
int update(int l,int h,int x,int y,int n)
{
  if(Flag[n])
   Refresh(l,h,n);
  if(h<x||l>y)
    return Sum[n];
  if(l>=x&&h<=y)
  {
    Sum[n]=v*(h-l+1);
    Flag[n]=1;
    Lazy[n]=v;
    return Sum[n];
  }
  int mm=(l+h)/2;
  Sum[n]=update(l,mm,x,y,2*n)+update(mm+1,h,x,y,2*n+1);
  return Sum[n];
}
int Query(int l,int h,int x,int y,int n)
{
  if(Flag[n])
   Refresh(l,h,n);
  if(h<x||l>y) return 0;
  if(l>=x&&h<=y)
   return Sum[n];
  int mm=(l+h)/2;
  return Query(l,mm,x,y,2*n)+Query(mm+1,h,x,y,2*n+1);
}
int gcd(int a,int b)
{
    int t;
    while(b)
    {
      t=a;
      a=b;
      b=t%b;
    }
    return a;
}
int main()
{
   int a,b,c,n,q,kase,kas=0,d;
    S1(kase);
    while(kase--)
    {
      S2(n,q);
      init(0,n-1,1);
      printf("Case %d:\n",++kas);
      while(q--)
      {
        S1(c);
        if(c==1){
         S3(a,b,v);
         update(0,n-1,a,b,1);
        }
        else{
         S2(a,b);
         c=Query(0,n-1,a,b,1);
         if(b-a==0) {printf("%d\n",c);continue;}
         d=gcd(b-a+1,c);
          c/=d;d=(b-a+1)/d;
         if(d==1){
         printf("%d\n",c);continue;}
         printf("%d/%d\n",c,d);
         }
      }
    }
    return 0;
}
