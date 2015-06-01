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
#define eps 1e-9
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
double a[105][105];
int main()
{
    int i,j,n,m,kase;
    double b,sum,cnt,avg;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%d %d",&n,&m);
     cnt=sum=0.0;
     for(i=0;i<n;i++)
      for(j=0;j<m;j++){
       scanf("%lf",&a[i][j]);
       if(a[i][j])
       cnt++,sum+=a[i][j];
       }
      avg=sum/cnt;
      b=floor(avg);
      if(avg-b>0.49999)
       b++;
      for(i=0;i<n;i++,printf("\n"))
      for(j=0;j<m;j++){
       if(j)
        printf(" ");
        if(a[i][j])
        printf("%0.lf",a[i][j]);
       else
       printf("%0.lf",b);
       }
    }
    return 0;
}
