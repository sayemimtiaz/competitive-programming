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
#define S2(a,b) scanf("%lld %lld",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 1e-9
#define ff first
#define ss second
#define mems(x,a) memset(x,a,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,-1,1};

typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
typedef pair<int,int>pii;
typedef long long i64;
typedef double dle;

inline i64 MAX(i64 a,i64 b) {return (a>b)?a:b;}
inline i64 MIN(i64 a,i64 b){return (a>b)?b:a;}
inline dle dis(dle ax,dle ay,dle bx,dle by){return ((ax-bx)*(ax-bx)+(ay-by)*(ay-by));}
i64 pwr(i64 x,i64 n)
{
  if(n==0) return 1;
  if(n==1) return x;
  i64 a=pwr(x,n/2);
  a=a*a;
  if(n%2) a*=x;
  return a;
}

int M[32][5][5][5][5][5][5];
int F[10];

int dp(bool p,int s)
{
  int &ret=M[s][F[1]][F[2]][F[3]][F[4]][F[5]][F[6]];
  if(ret!=-1) return ret;
  if(s==31) return ret=!p;
  int i;
  rep(i,1,6)
   if(F[i]<4&&s+i<32)
   {
     F[i]++;
    if(dp(!p,s+i)==p){
     F[i]--;
     return ret=p;
     }
    F[i]--;
   }
   return ret=!p;
    
}
int main()
{
    char G[100];
    int s,i;
    while(gets(G))
    {
      mems(M,-1);mems(F,0);
      s=0;
      for(i=0;G[i];i++){
       F[G[i]-'0']++;
       s+=(G[i]-'0');
       }
     if(dp(i%2,s)) printf("%s B\n",G);
      else printf("%s A\n",G);
    }
    return 0;
}
