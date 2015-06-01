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
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))
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

int a[1020],n,m;

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
}

bool simulate(int s)
{
     int c,sum,i;
     if(a[1]>s) return 0;
     if(a[1]==s) c=1,sum=0;
     else  c=0,sum=a[1];
     rep(i,2,n)
     {
        if(sum+a[i]>s){ if(a[i]>s) return 0;sum=a[i],c++;}
        else sum+=a[i];       
     }
     c++;
  //   printf("%d %d\n",c,sum);
     if(c>m) return 0;
     if(sum>s) return 0;
     return 1;
}
int main()
{
    int i,left,rite,mid;
    while(~scanf("%d %d",&n,&m))
    {
      scanf("%d",&a[1]);
      left=rite=a[1];
     rep(i,2,n){
      scanf("%d",&a[i]);
      left=MIN(left,a[i]);
      rite+=a[i];
      }
      
      while(left<rite){
       mid=(left+rite)/2;
      // printf("%d %d %d\n",left,rite,mid);
       if(simulate(mid)) rite=mid;
       else left=mid+1;
       }
       printf("%d\n",rite);
    }
    return 0;
}
