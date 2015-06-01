#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>
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
#define i64 long long
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

bool flag[10001][201];

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

int main()
{
    int kase,i,j,k,n,m,a;
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&k);
      scanf("%d",&a);
      m=a%k;
      if(m<0) flag[0][k+abs(m)-1]=1; else flag[0][m]=1;
      for(i=1;i<n;i++){
       scanf("%d",&a);
       for(j=0;j<k;j++)
        if(flag[i-1][j]){
             m=(j+a)%k;
          if(m<0) flag[i][k+abs(m)-1]=1; else flag[i][m]=1;
           m=(j-a)%k;
          if(m<0) flag[i][k+abs(m)-1]=1; else flag[i][m]=1;
          }
       for(j=k;j<2*k;j++)
        if(flag[i-1][j]){
          m=(k-j-1+a)%k;
          if(m<0) flag[i][k+abs(m)-1]=1; else flag[i][m]=1;
          m=(k-j-1-a)%k;
          if(m<0) flag[i][k+abs(m)-1]=1; else flag[i][m]=1;
          }
       }
       if(flag[n-1][0])
        printf("Divisible\n");
       else
        printf("Not divisible\n");

      mems(flag);
    }
    return 0;
}
