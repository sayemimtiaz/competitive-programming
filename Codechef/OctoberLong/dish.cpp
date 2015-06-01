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

int x[105],y[105];
const int mod=1000000007;
int way[105][105];
typedef vector<int>vi;
typedef queue<int>qi;
typedef stack<int>si;

inline i64 MAX(i64 a,i64 b)
{
  return (a>b)?a:b;
}
inline i64 MIN(i64 a,i64 b)
{
  return (a>b)?b:a;
}
/*i64 dp(int n,int m,int s)
{
    if(m==0){
     if(n==0)
     return 1;
     return 0;
     }
    if(memo[n][m]!=-1)
     return memo[n][m];
    i64 way=0;
    int i;
    for(i=x[s];i<=y[s];i++)
     if(n>=i)
      way=(way+dp(n-i,m-1,s+1))%mod;
    memo[n][m]=way;
    return way;
}*/
int main()
{
    int i,j,n,m,kase,k;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%d %d",&n,&m);
     for(i=1;i<=m;i++)
      scanf("%d %d",&x[i],&y[i]);
      way[0][0]=1;
      for(i=0;i<=n;i++)
       for(j=1;j<=m;j++){
        for(k=x[j];k<=i&&k<=y[j];k++)
         way[i][j]=(way[i][j]+way[i-k][j-1])%mod;
        //printf("way[%d][%d]=%d\n",i,j,way[i][j]);
        }
     printf("%d\n",way[n][m]);
    for(i=0;i<=n;i++)
     for(j=0;j<=m;j++)
      way[i][j]=0;
      
    }
    return 0;
}
