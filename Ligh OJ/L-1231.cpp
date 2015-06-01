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
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define mems(x) memset(x,0,sizeof(x))
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
int R[1500][1500];

int main()
{
    int mod=100000007;
    int W[2000],A[2000],C[2000],c,T[2000],k,i,j,kase,kas=0,n;
    S1(kase);
    while(kase--)
    {
     S2(n,k);
     rep(i,1,n)
      S1(A[i]);
     c=0;
     rep(i,1,n)
     {
      S1(T[i]);
      rep(j,1,T[i])
       C[++c]=A[i];
      }
     W[0]=1;
     rep(i,1,c)
      repb(j,k,0)
       if(j+C[i]<=k&&W[j]){
        if(R[j+C[i]][j]){
          W[j+C[i]]=(((W[j+C[i]]+W[j])%mod)-R[j+C[i]][j]);
          if(W[j+C[i]]<0)
           W[j+C[i]]+=mod;
           }
        else
          W[j+C[i]]=(W[j+C[i]]+W[j])%mod;
        R[j+C[i]][j]=W[j]%mod;
        }
      
       printf("Case %d: %d\n",++kas,W[k]%mod);
       mems(R);mems(W);
    }
    return 0;
}
