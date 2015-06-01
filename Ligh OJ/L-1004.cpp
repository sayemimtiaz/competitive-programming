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
#define swap(a,b,t) t=a,a=b,b=t
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
  return a;
}
int M[250][250],A[250][250];

int main()
{
    int kase,N,i,j,k,kas=0;
    S1(kase);
    while(kase--)
    {
      S1(N);
      rep(i,1,N)
       rep(j,1,i)
        S1(A[i][j]);
       k=1;
       rep(i,N+1,2*N-1){
        rep(j,1,N-k) 
         S1(A[i][j]);
         k++;
        }
       rep(i,1,N)
        rep(j,1,i)
         M[i][j]=A[i][j]+MAX(M[i-1][j-1],M[i-1][j]);
      
         k=1;
       rep(i,N+1,2*N-1){
        rep(j,1,N-k) {
         M[i][j]=A[i][j]+MAX(M[i-1][j],M[i-1][j+1]);
           //printf("M[%d][%d]=%d\n",i,j,M[i][j]);
            }
         k++;
        }
        printf("Case %d: %d\n",++kas,M[2*N-1][1]);
        
    }
    return 0;
}
