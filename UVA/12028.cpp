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
i64 A[100009];
int main()
{
    int kase,i,kas=1;
    i64 K,C,n,Tsum,Osum,Res,temp;
    scanf("%d",&kase);
    while(kase--)
    {
     scanf("%lld %lld %lld %lld",&K,&C,&n,&A[0]);
     Osum=A[0];
     for(i=1;i<n;i++)
     {
       A[i]=(K*A[i - 1] + C)%1000007;
       Osum+=A[i];
     }
     sort(A,A+n);
     Res=0;
     Tsum=A[0];
     for(i=0;i<n-1;i++)
     {
       temp=Osum-Tsum;
       Res+=abs(temp-(n-1-i)*A[i]);
       Tsum+=A[i+1];
     }
     printf("Case %d: %lld\n",kas++,Res);
    }
    return 0;
}
