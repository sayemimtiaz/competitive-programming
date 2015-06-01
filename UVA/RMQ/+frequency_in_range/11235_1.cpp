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
#define i64 int
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

int M[20000000],S[200500],E[200500],A[100009];

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

void init(int node,int b,int e)
{
  if(b==e) M[node]=1;
  else
  {
   int m=(b+e)/2;
   init(2*node,b,m);
   init(2*node+1,m+1,e);
   int l,h;
   l=S[A[m]+100000];h= E[A[m]+100000];
   if(l<b) l=b;
   if(h-e>1) h=e+1;
   M[node]=MAX(h-l,MAX(M[2*node],M[2*node+1]));
  // printf("(%d,%d)=%d\n",b,e,M[node]);
  }
}
int Query(int node,int b,int e,int i,int j)
{
  if(j<b||i>e) return -1;
  if(b>=i&&e<=j) return M[node];
  int m=(b+e)/2;
  int p1=Query(2*node,b,m,i,j);
  int p2=Query(2*node+1,m+1,e,i,j);
    int l,h;
  if(p1==-1){
     l=S[A[m+1]+100000];h= E[A[m+1]+100000];
     if(l<i) l=i;
     if(h-j>1) h=j+1;
     return MAX(h-l,p2);
   }
  if(p2==-1){
     l=S[A[m]+100000];h= E[A[m]+100000];
     if(l<i) l=i;
     if(h-j>1) h=j+1;
     return MAX(h-l,p1);
   }
       l=S[A[m]+100000];h= E[A[m]+100000];
     if(l<i) l=i;
     if(h-j>1) h=j+1;
  return MAX(h-l,MAX(p1,p2));
}

int main()
{
    int n,q,i,a,b;
    while(S1(n)&&n)
    {
     S1(q);
     S1(A[1]);
     S[A[i]+100000]=1;
    rep(i,2,n)
    {
     S1(A[i]);
     if(A[i]!=A[i-1])
      E[A[i-1]+100000]=i,S[A[i]+100000]=i;
    }
    E[A[i-1]+100000]=i;
    
    init(1,1,n);
    while(q--)
    {
         scanf("%d %d",&a,&b);
         printf("%d\n",Query(1,1,n,a,b)); 
    }
   }
    return 0;
}
