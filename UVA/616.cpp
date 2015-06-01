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

int main()
{
    int i,n,a,t,cnt;
    while(scanf("%d",&n)&&n>=0)
    {
      bool flag=0;
      for(i=2;i*i<=n;i++)
      {
        a=n;cnt=0;
        while(a%i==1)
          a=a-(a/i)-1,cnt++;
        if(a%i==0&&cnt==i)
         flag=1,t=i;
      }
      if(flag)
      printf("%d coconuts, %d people and 1 monkey\n",n,t);
     else
      printf("%d coconuts, no solution\n",n);
    }
    return 0;
}
