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

#define S1(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld %lld",&a,&b)
#define S3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64  long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,-1,sizeof(x))
#define swap(a,b) a^=b,b^=a,a^=b
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
typedef pair<int,int>pii;



inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b) {return (a>b)?b:a;}
inline dle dis(Point a,Point b) {return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}
i64 M[11][11][2],D[11],d,SS[11],S[11][11];

i64 dp0(i64 rem,i64 zer,i64 s)
{
  if(S[rem][zer]!=-1) return S[rem][zer];
  if(rem==0)
   return S[rem][zer]=zer;
  i64 i,w=0;
  rep(i,s,9)
   w+=dp0(rem-1,i?zer:zer+1,0);
  return S[rem][zer]=w; 
}
i64 dp1(i64 rem,i64 zer,i64 s,bool flag)
{
   // printf("P %d %d %d\n",rem,zer,M[rem][zer]);
  if(M[rem][zer][flag]!=-1) return M[rem][zer][flag];
  if(rem==0)
   return M[rem][zer][flag]=zer;
  i64 i,w=0;
  i64 e=D[rem];
  if(flag) e=9;
   rep(i,s,e){
  //printf("Under %d %d bosaise %d\n",rem,zer,i);
   w+=dp1(rem-1,i?zer:zer+1,0,D[rem]>i?1:flag);
 // printf("Under %d %d bosaisilo %d cur %d\n",rem,zer,i,w);
  }
  return M[rem][zer][flag]=w; 
}

int main()
{
    i64 Z,i,j,kase,kas=0,t,m,n,k,r1,r2;
  
    SS[1]=1;
    rep(i,2,9){
     mems(S);
     SS[i]=dp0(i,0,1);
     }
    S1(kase);
    while(kase--)
    {
     S2(m,n);
     t=m;d=0;Z=0;
     if(!m) Z=1;
     while(t){
      D[++d]=t%10;
      if(D[d]==0)Z++;
      t/=10;
      }
      if(!d) d++;
      mems(M);
      r1=r2=0;
      rep(k,1,d-1)
       r1+=SS[k];
  
      mems(M);
      if(d==1) r1=1;
      else
      r1+=dp1(d,0,1,0);
  
      t=n;d=0;
      while(t){
      D[++d]=t%10;
      t/=10;
      }
      if(!d) d++;
      rep(k,1,d-1)
       r2+=SS[k];
       mems(M);
      // printf("\n");
      if(d==1) r2=1;
      else
      r2+=dp1(d,0,1,0);
      
     printf("Case %lld: %lld\n",++kas,r2-r1+Z);
    }
    return 0;
}
