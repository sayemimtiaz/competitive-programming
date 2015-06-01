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
int M[32][32];
i64 W[32][32];

int main()
{
    char S1[100],S2[100];
    int i,j,kase,kas=0,m,n;
    S1(kase);
    
    while(kase--)
    {
      scanf("%s %s",S1,S2);
      for(m=1;S1[m-1];m++)
       M[0][m]=m,W[0][m]=1;
      for(n=1;S2[n-1];n++)
       M[n][0]=n,W[n][0]=1;
      m--,n--;
      M[0][0]=0;W[0][0]=1;
      rep(i,1,n)
       rep(j,1,m)
       {
        M[i][j]=MIN(1+M[i][j-1],1+M[i-1][j]);
        if(S2[i-1]==S1[j-1]){
         M[i][j]=MIN(M[i][j],1+M[i-1][j-1]);
         W[i][j]=W[i-1][j-1];  
         }
         else
         if(M[i][j-1]==M[i][j])
          W[i][j]=W[i-1][j];
         else if(M[i-1][j]==M[i][j])
          W[i][j]=W[i][j-1];
         else 
          W[i][j]=W[i-1][j]+W[i][j-1];
       } 
       printf("Case %d: %d %lld\n",++kas,M[n][m],W[n][m]);  
    }
    return 0;
}
