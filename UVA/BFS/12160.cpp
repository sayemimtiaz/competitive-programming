#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
#include<stdlib.h>
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


int main()
{
    queue<int>q;
    int d[12000],L,U,R,i,T,p,pp,j,K[20],N,kas=0;
    while(S3(L,U,R)&&(L||U||R))
    {
       rep(i,0,10001)
        d[i]=-1;
      rep(i,1,R)
       S1(K[i]);
      d[L]=0;
      q.push(L);
      while(!q.empty()){
        T=q.front();
        q.pop();
        rep(i,1,R){
         N=T+K[i];
         pp=p=0,j=0;
         while(j<4&&N)
         {
           pp+=((N%10)*pwr(10,p++));
           N/=10;
          // if(T==99) printf("%d %d\n",pp,N);
           j++;
         }
        // printf("%d\n",pp);
         if(d[pp]==-1) d[pp]=d[T]+1,q.push(pp);
        }
      }
      printf("Case %d: ",++kas);
      if(d[U]==-1)
       printf("Permanently Locked\n");
      else
       printf("%d\n",d[U]);
    }
    return 0;
}
