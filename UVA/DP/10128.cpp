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
i64 n,F,pp,qq;
i64 M[1<<13][15][14],R[14][14][14];
bool V[1<<13][15][14];

i64 dp(i64 s,i64 p,i64 q,i64 yet)
{
  i64 &ret=M[s][p+q][yet];
  if(V[s][p+q][yet]) return ret;
  i64 w=0;
  i64 i;
  V[s][p+q][yet]=1;
  if(p==0&&q==0&&F==s)
        return ret=1;
 
  if(p!=0){
  rep(i,1,n)
    if(!(s&(1<<(i-1))))
    {
      if(i>yet&&((p==1&&i==n)||(p>1&&i!=n)))
        w+=dp(s|(1<<(i-1)),p-1,q,i==n?0:i);
      else if(i<=yet)
       w+=dp(s|(1<<(i-1)),p,q,yet);
    }
  }
  else{
 
   rep(i,1,n)
    if(!(s&(1<<(i-1)))){
        if(i>yet&&q>0)
        w+=dp(s|(1<<(i-1)),p,q-1,i);
      else if(i<=yet)
       w+=dp(s|(1<<(i-1)),p,q,yet);
      }
    }
    return ret=w;
}
int main()
{
   i64 kase,i,j,k;
   for(n=1;n<=13;n++)
     for(j=1;j<=n;j++)
      for(k=1;k+j-1<=n&&k<=n;k++){
       F=(1<<n)-1;
       R[n][j][k]=dp(0,j,k-1,0);
       mems(V,0);
       }
    S1(kase);
    while(kase--)
    {
      S3(n,pp,qq);
      if(pp==0||qq==0||pp>n||qq>n||pp+qq>14)
      { printf("0\n");continue;}
      printf("%lld\n",R[n][pp][qq]);
    }
    return 0;
}
