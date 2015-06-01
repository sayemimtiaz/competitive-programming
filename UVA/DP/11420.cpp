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
#define mems(x) memset(x,-1,sizeof(x))
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
i64 M[67][3][67];
int n,s;

i64 dp(int pos,int status,int sec)
{
  i64 &ret=M[pos][status][sec];
  if(ret!=-1) return ret;
  ret=0;
  if(pos==n)
  {
   if(sec==0) ret=1;
   if(sec==0&&status==1) ret=2;
   if(sec==1&&(status==0||status==2)) ret=1;
   return ret;
  }

  
  if(sec<=n-pos+1){
   ret=dp(pos+1,1,sec);
  }
  if(sec<=n-pos+1){
  if(sec-1>=0&&(status==0||status==2))
   ret+=dp(pos+1,2,sec-1);
  else if(status==1)
   ret+=dp(pos+1,2,sec);
     }
  return ret;
}
int main()
{
    int i,j;
    while(S2(n,s)&&n>=0&&s>=0)
    {
      if(s>n){printf("0\n");continue;}
      if(s==n){printf("1\n");continue;}
       mems(M);
      printf("%lld\n",dp(1,0,s));
     
    }
    return 0;
}
