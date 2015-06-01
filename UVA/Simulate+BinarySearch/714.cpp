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

int N,K,P[2600];

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

inline bool check(i64 W)
{
   i64 G,S,i,I,j;
   
   G=S=0,I=0;
   rep(i,1,N){
    S+=P[i],I++;
   if(S>W){ if(I==1) return 0; G++,S=I=0;i--;}
   if(G>K) return 0;
  //  printf("%d %d\n",G,S);
    if(N-i+1==K-G) break;
   }
   G++;
   if(S>W||G>K) return 0;
   rep(j,i+1,N){
    if(P[j]>W) return 0;
    if(G+1>K) return 0;
    G++;
   }
   if(G!=K) return 0;
   return 1;
}

int main()
{
    i64 i,j,k,G,kase,L,U,M,S,C[5600];
    
    S1(kase);
    while(kase--)
    {
     S2(N,K);
     L=U=0;
     rep(i,1,N){
      S1(P[i]);
      U+=P[i];
      }
     while(L<U)
     {
       M=(L+U)/2;
       if(check(M)) U=M;
       else L=M+1;
     }
    // printf("%d\n",L);
     S=0;j=1;k=1;G=0;
     repb(i,N,1){
       S+=P[i];
       if(S>L){
       G++;C[j++]=-1;S=0;k--;i++;}
       if(S)C[j++]=P[i];
       if(N-k+1==K-G) break;
       k++;
     }
     C[j++]=-1;
     repb(k,i-1,1)
      C[j++]=P[k],C[j++]=-1;
     repb(i,j-2,1)
     {
       if(C[i]==-1) {printf(" /");continue;}
       if(i!=j-2)
        printf(" ");
       printf("%lld",C[i]);
     }
     printf("\n");
    }
    return 0;
}
