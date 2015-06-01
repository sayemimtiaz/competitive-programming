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
#define S3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define pb push_back
#define PI 2.0*acos(0.0)
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

int main()
{
    double x1,x2,y1,y2,x,y,x3,y3,s,a,b,c;
    int i,j,kase,kas=0,q;
    S1(kase);
    while(kase--)
    {
     S3(x1,y1,x2);
     S3(y2,x3,y3);
     x=(x1+x3)/2.0;y=(y1+y3)/2.0;
     x=2.0*x-x2;y=2.0*y-y2;
     a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
     b=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
     c=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
     s=(a+b+c)/2.0;
     s=sqrt(s*(s-a)*(s-b)*(s-c));
     s=2.0*s;
     printf("Case %d: %0.lf %0.lf %0.lf\n",++kas,x,y,s);
     
    }
    return 0;
}
