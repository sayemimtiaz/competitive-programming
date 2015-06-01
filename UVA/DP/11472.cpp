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
#define mem(x) memset(x,sizeof(x),0)
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

struct Point
{
  dle x,y;
};
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;
const i64 mod=1000000007;
i64 memo[105][11][1030];
int F,n;

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

i64 dp(int L,int S,int C)
{
    if(memo[L][S][C]!=-1)
     return memo[L][S][C];
     if(L==1)
     {
       if((S+1<n||S-1>=0)&&(C|(1<<S))==F)
        return 1;
       return 0; 
     }
  //   printf("State %d %d %d\n",L,S,C);
    i64 m;
    m=0;
    if(S+1<n)
     m=(m+dp(L-1,S+1,C|(1<<S)))%mod;
    //  printf("Finish State %d %d %d with %lld\n",L,S,C,m);
    if(S-1>=0)
      m=(m+dp(L-1,S-1,C|(1<<S)))%mod;
    memo[L][S][C]=m;
//    printf("Finish State %d %d %d with %lld\n",L,S,C,m);
    return m;
}

int main()
{
    int kase,i,j,m,k;
    i64 sum;
    
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%d %d",&n,&m);
      F=(1<<n)-1;
      rep(i,0,m)
       rep(j,0,n)
        rep(k,0,F)
         memo[i][j][k]=-1;
       sum=0;
      rep(i,n,m)
       rep(j,1,n-1)
       {
         sum=(sum+dp(i,j,0|(1<<j)))%mod;
       //  printf("%lld\n",sum);
         }
       printf("%lld\n",sum);
    }
    return 0;
}
