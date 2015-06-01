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
int H[20],A[20][20],memo[33768],N;

int dp(int state)
{
  if(memo[state]!=-1) return memo[state];
  int j,t,m=INT_MX,i,s;
 
   rep(i,1,N)
   if(!(state&(1<<(i-1)))){
    t=H[i]+dp(state|(1<<(i-1)));
    m=MIN(m,t);
   }
   
  rep(i,1,N)
   if(state&(1<<(i-1)))
   {
      rep(j,1,N)
       if(!(state&(1<<(j-1)))&&A[i][j])
       {
      s=H[j]/A[i][j];
      if(H[j]%A[i][j]) s++;
      t=s+dp(state|(1<<(j-1)));
      m=MIN(t,m);
      }
   }
   
   return memo[state]=m;
}
int main()
{
    int i,j,kase,kas=0;
    char ch;
    S1(kase);
    while(kase--)
    {
     S1(N);
     rep(i,1,N)
      S1(H[i]);
      rep(i,1,N){
        getchar();
      rep(j,1,N)
      {
        scanf("%c",&ch);
        A[i][j]=ch-'0';
      }
     }
    
     rep(i,0,1<<N)
      memo[i]=-1;
     memo[(1<<N)-1]=0;
     printf("Case %d: %d\n",++kas,dp(0));
    }
    return 0;
}
