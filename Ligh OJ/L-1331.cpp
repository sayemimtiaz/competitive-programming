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
    double Area,r1,r2,r3,s,a,b,c,A,B,C;
    int i,j,kase,kas=0,q;
    S1(kase);
    while(kase--)
    {
     S3(r1,r2,r3);
     a=r1+r2;b=r1+r3;c=r3+r2;
     s=(a+b+c)/2.0;
     Area=sqrt(s*(s-a)*(s-b)*(s-c));
     A=acos((a*a+b*b-c*c)/(2*a*b));
     B=acos((b*b+c*c-a*a)/(2*c*b));
     C=acos((a*a+c*c-b*b)/(2*a*c));
     Area=Area-(0.5*r1*r1*A+0.5*r2*r2*B+0.5*r3*r3*C);
     printf("Case %d: %.10lf\n",++kas,Area);
     
    }
    return 0;
}
