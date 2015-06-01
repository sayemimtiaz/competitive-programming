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

int N,K,Sleep[1000];

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


inline bool check(int W)
{
  int S,Night,L,U,M,C;
  bool found;
  S=0;
  if(W<Sleep[0]) return 0;
  Night=C=0;
  while(1)
  {
    S+=W;
    L=C,U=N;found=0;
    while(L<=U)
    {
      M=(L+U)/2;
    // printf("%d %d %d\n",Sleep[M],Sleep[M+1],S);
      if(M==N&&Sleep[M]<=S){ found=1;break;}
      else if(Sleep[M]<=S&&Sleep[M+1]>S){found=1; break;}
      if(Sleep[M]>S) U=M-1;
      else L=M+1;
    }
    if(!found) return 0;
    S=Sleep[M];
      //printf("P%d %d\n",M,Sleep[M]);
    if(Night<=K&&M==N) return 1;
    C=M+1;
    Night++;
  }
}
 
int main()
{
    int i,j,U,L,M;
    while(~S2(N,K))
    {
     S1(Sleep[0]);
     rep(i,1,N){
      S1(Sleep[i]);
      Sleep[i]+=Sleep[i-1];
      }
     L=0,U=Sleep[N];
     while(L<U)
     {
       M=(L+U)/2;
       if(i=check(M)) U=M;
       else L=M+1;
      // printf("\nreturned %d %d\n",i,M);
     }
     printf("%d\n",L);
    }
    return 0;
}
